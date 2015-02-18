function drawRobot(p,p2,theta1,theta2,link1Pnts,link2Pnts, L1)
% Rotate and translate Link vertices
T_01 = RotZ(theta1);
link1NewPnts = T_01*link1Pnts; % new vertices Link1

T_12 = Trans(L1,0,0)*RotZ(theta2); % new vertices Link2
link2NewPnts = T_01*T_12*link2Pnts;


% Draw robot
set(p,'Vertices',link1NewPnts(1:3,:)');
set(p2,'Vertices',link2NewPnts(1:3,:)');
end