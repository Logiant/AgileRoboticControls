%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main File   : drawRobot.m
% Source Files: None 
% Dependancies: Trans, RotZ
% Description : Draws the links of the legs
% Input       : p - x,y,z,w verticies of the stl 3D model link 1
%               p2 - x,y,z,w verticies of the stl 3D model link 2
%               theta1 - theta to rotate the stl model upper link
%               theta2 - theta to rotate the stl model lower link
%               link1Pnts - verticies in the upper link
%               link2Pnts - verticies in the lower link
%               L1 - Length from hip to the knee of the leg
% Output      : y - 2D array of Hip Theta and Knee Theta
% Author      : Logan Beaver
% Date        : 11/12/2014
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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