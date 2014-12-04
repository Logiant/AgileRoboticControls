function DrawArm(Link1, Link2, x, y, D1, D2, cylPos, dt, cylAcc, dta)
% Converts CAD geometry into multiple polygons and into its vertices
% link1Pnts  and link2Pnts already includes the bottom
% row of ones, that is link1Pnts = [Pnts;1]
[p,link1Pnts,p2,link2Pnts] = cad2poly(Link1, Link2);
view(2); %2D
%set plot bounds
maxVal = (max(max(max(abs(x)), max(abs(y))), 0))/100 + .25;
figure(1);
hold on;
axis([-maxVal maxVal -maxVal maxVal]);
xlabel('X Position [m]');
ylabel('Y Position [m]');
    for i = 1:length(x)
        Theta = InverseKinematics(D1, D2, x(i), y(i));
        %update position of STL models
        drawRobot(p, p2, Theta(1), Theta(2), link1Pnts, link2Pnts, (D1-2)/100);
        %plot current path progress
        figure(1)
        movegui('northwest');
        title('Robot Step Animation');
        plot(x(1:i)/100, y(1:i)/100);
        pause(0.05)
        %draw cylinder positions
        %plot the cylinder lengths
        figure(2);
        movegui('north');
        hold on;
        subplot(2,1,1);
        title('Cylinder 1 - Position vs Time [m]');
        axis([0, max(dt), min(cylPos(:,1))*.95, max(cylPos(:,1))*1.05]);
        plot(dt(1:min(i, length(dt))), cylPos(1:min(i, length(dt)),1));
        figure(3);
        movegui('northeast');
        hold on;
        subplot(2,1,1);
        title('Cylinder 2 - Position vs Time [m]');
        axis([0, max(dt), min(cylPos(:,2))*.95, max(cylPos(:,2))*1.05]);
        plot(dt(1:min(i, length(dt))), cylPos(1:min(i, length(dt)),2)); 
         %plot the cylinder accelerations
        figure(2);
        hold on;
        subplot(2,1,2);
        title('Cylinder 1 - Acceleration vs Time [m/s/s]');
        axis([0, max(dta), min(cylAcc(:,1))*.95, max(cylAcc(:,1))*1.05]);
        plot(dta(1:min(i, length(dta))), cylAcc(1:min(i, length(dta)),1));
        figure(3);
        hold on;
        subplot(2,1,2);
        title('Cylinder 2 - Acceleration vs Time [m/s/s]');
        axis([0, max(dta), min(cylAcc(:,2))*.95, max(cylAcc(:,2))*1.05]);
        plot(dta(1:min(i, length(dta))), cylAcc(1:min(i, length(dta)),2)); 
    end
end