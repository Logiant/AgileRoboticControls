%Function used to simulate the robotic leg
%Inputs:
%Link1, Link2 - .stl files
%L1, L2 - the length of each link
%L12 - the distance along L1 where L2 is attached
%L21 - the distance along L2 where L1 is attached
%P1x, P1y - the ground location of piston 1
%P12 - the distance of piston 1's attachment point on link 2
%p21 - the distance of piston 2's attachment point on link 1
%p22 - the distance of piston 2's attachment point on link 2
%Theta1 and Theta2 are the starting conditions
function y=LegModel(Link1, Link2, L1, L2, L12, L21, P1x, P1y, P11, P21, P22,path,sampleDistance, time)
%calculate the number of points in the path
numPts = size(path);
numPts = numPts(1);
%foot position index
index = 1;
footPosition(index,:) = path(1,:);
Theta(index,:) = InverseKinematics(L12, L2-L21, footPosition(index,1), footPosition(index,2));
drawPosition(index,:) = ForwardKinematics(L12, L2-L21, Theta(1), Theta(2));
index = index + 1;
%calculate total distance of the path
totalDistance = 0;
for i = 1:numPts
    desiredPos = path(i,:);
    while footPosition(index-1,1) ~= desiredPos(1) || footPosition(index-1,2) ~= desiredPos(2)
        %move footPosition up to sampleDistance
        d = min(sampleDistance, Distance(desiredPos(1), desiredPos(2), footPosition(index-1,1), footPosition(index-1,2)));
        unitVector = [desiredPos(1) - footPosition(index-1,1),desiredPos(2) - footPosition(index-1,2)];
        unitVector = unitVector ./ sqrt(unitVector(1)^2 + unitVector(2)^2);
        unitVector = unitVector.*d;
        %update foot position
        footPosition(index,:) = footPosition(index-1,:) + unitVector;
        Theta(index,:) = InverseKinematics(L12, L2-L21, footPosition(index,1), footPosition(index,2));
        drawPosition(index,:) = ForwardKinematics(L12, L2-L21, Theta(index,1), Theta(index,2));
        index = index + 1;
    end
    if i > 1
       totalDistance = totalDistance + Distance(path(i-1,1), path(i-1,2), path(i,1), path(i,2)); 
    end
end
%calculate cylinder positions
footVelocity = totalDistance/time;
for i = 1:length(footPosition)
    cylPos(i,:) = FootToCylinder(L12, L2-L21, P1x, P1y, P11, P21, P22, footPosition(i,1), footPosition(i,2));
end
dt = 0:time/(length(footPosition)-1):time;
%calculate acceleration parameters
cylAcc(:,1) = diff(cylPos(:,1), 2);
cylAcc(:,2) = diff(cylPos(:,2), 2);
dta = dt(2:length(dt)-1);

%draw the foot position
DrawArm(Link1, Link2, drawPosition(:,1), drawPosition(:,2), L12, L2-L21, cylPos, dt, cylAcc, dta);

maxTheta1 = max(Theta(:,1));
maxTheta2 = max(Theta(:,2));
minTheta1 = min(Theta(:,1));
minTheta2 = min(Theta(:,2));

maxPL1 = max(cylPos(:,1));
maxPL2 = max(cylPos(:,2));
minPL1 = min(cylPos(:,1));
minPL2 = min(cylPos(:,2));

maxP1Acc = max(abs(cylAcc(:,1)));
maxP2Acc = max(abs(cylAcc(:,2)));

%return important values
y = [minTheta1, maxTheta1, minTheta2, maxTheta2; ...
    minPL1, maxPL1, minPL2, maxPL2;...
    0, maxP1Acc, 0, maxP2Acc,];
end