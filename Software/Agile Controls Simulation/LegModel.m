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
function y=LegModel(Link1, Link2, L1, L2, L12, L21, P1x, P1y, P11, P21, P22, Theta1, Theta2, path)
dTheta = 10; %degrees/sec - eventually replace with pneumatic values
%calculate the number of points in the path

numPts = size(path);
numPts = numPts(1);
%foot position index
index = 1;

for i = 1:numPts
    TD = InverseKinematics(L12, L2-L21, path(i, 1), path(i, 2)); %desired theta
    while Theta1 ~= TD(1) || Theta2 ~= TD(2)
        %update Theta1/Teta2 by up to dTheta [calc pressure, velocity, etc]
        if (Theta1 > TD(1))
            Theta1 = min(TD(1), Theta1 + dTheta);
        else
            Theta1 = max(TD(1), Theta1 - dTheta);
        end
        if (Theta2 > TD(2))
            Theta2 = min(TD(2), Theta2 + dTheta);
        else
            Theta2 = max(TD(2), Theta2 - dTheta);
        end
        %update foot position
        footPosition(index,:) = ForwardKinematics(L12, L2-L21, Theta1, Theta2);
        index = index + 1;
    end
end
%draw the foot position
DrawArm(Link1, Link2, footPosition(:,1), footPosition(:,2));
y=0;
end