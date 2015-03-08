%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main File   : DrawArm.m
% Source Files: None 
% Dependancies: InverseKinematics, drawRobot
% Description : Converts CAD geometry into multiple polygons and into 
%               its vertices. Plots the accelerations throughout the step
% Input       : Link1 - CAD geometry of upper link
%               Link2 - CAD geometry of lower link
%               x - x position of the foot
%               y - y position of the foot
%               D1 - Length of the hip joint to the knee joint
%               D2 - Length of the knee joint to the foot
%               clyPos - array of cylinder positions
%               dt - time step on the plot and between samples
%               cylAcc - array of cylindr accelerations
% Output      : None
% Author      : Logan Beaver
% Date        : 1/20/2015
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function DrawArm(Link1, Link2, x, y, D1, D2, cylPos, dt, cylAcc)
% Converts CAD geometry into multiple polygons and into its vertices
% link1Pnts  and link2Pnts already includes the bottom
% row of ones, that is link1Pnts = [Pnts;1]
[p,link1Pnts,p2,link2Pnts] = cad2poly(Link1, Link2);
view(2); %2D
%set plot bounds
maxVal = (max(max(max(abs(x)), max(abs(y))), 0))/100 * 1.25;
figure(1);
hold on;
axis([-maxVal maxVal -maxVal 0.05]);
xlabel('X Position [m]');
ylabel('Y Position [m]');
cdt = cumsum(dt);
    for i = 1:length(x)
        Theta = InverseKinematics(D1, D2, x(i), y(i));
        %update position of STL models
        drawRobot(p, p2, Theta(1), Theta(2), link1Pnts, link2Pnts, (D1-2)/100);
        %plot current path progress
        figure(1)
        movegui('northwest');
        title('Robot Step Animation');
        plot(x(1:i)/100, y(1:i)/100);
 %       pause(0.05)
        %draw cylinder positions
        %plot the cylinder lengths
        figure(2);
        movegui('north');
        hold on;
        subplot(2,1,1);
        title('Cylinder 1 - Position vs Time [m]');
        axis([0, sum(dt), min(cylPos(:,1))*.95, max(cylPos(:,1))*1.05]);
        plot(cdt(1:min(i, length(cdt))), cylPos(1:min(i, length(dt)),1));
        figure(3);
        movegui('northeast');
        hold on;
        subplot(2,1,1);
        title('Cylinder 2 - Position vs Time [m]');
        axis([0, sum(dt), min(cylPos(:,2))*.95, max(cylPos(:,2))*1.05]);
        plot(cdt(1:min(i, length(cdt))), cylPos(1:min(i, length(cdt)),2)); 
         %plot the cylinder accelerations
        figure(2);
        hold on;
        subplot(2,1,2);
        title('Cylinder 1 - Acceleration vs Time [m/s/s]');
        axis([0, sum(dt), min(cylAcc(:,1))*.95, max(cylAcc(:,1))*1.05]);
        plot(cdt(1:min(i, length(cdt)-1)), cylAcc(1:min(i, length(cdt)-1),1));
        figure(3);
        hold on;
        subplot(2,1,2);
        title('Cylinder 2 - Acceleration vs Time [m/s/s]');
        axis([0, sum(dt), min(cylAcc(:,2))*.95, max(cylAcc(:,2))*1.05]);
        plot(cdt(1:min(i, length(cdt)-1)), cylAcc(1:min(i, length(cdt)-1),2)); 
    end
end