%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main File   : FootToCylinder.m
% Source Files: None 
% Dependancies: InverseKinematics
% Description : Calculates the cylinder length based on the position of the
% foot of the robot
% Input       : D1 - distance from hip joint to knee joint
%               D2 - distance from knee joint to foot
%               P1x - x position where the upper cylinder is attached at
%               the chassis
%               P2y - y position where the upper cylinder is attached at
%               the chassis
%               P11 - length along the upper link where the upper cylinder
%               is attached
%               P21 - length along the upper link where the lower cylinder
%               is attached
%               P22 - length along the lower link where the lower cylinder
%               is attached
%               x - x position of the robot foot
%               y - y position of the robot foot
% Output      : lengths - array of the cylinder lengths
%               [upper cylinder, lower cylinder]
% Author      : Logan Beaver
% Date        : 10/15/2014
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function lengths = FootToCylinder(D1, D2, P1x, P1y, P11, P21, P22, x, y)
%Calculate inverse kinematics
Theta = InverseKinematics(D1, D2, x, y);
%Length of Cylinder 1
deltaX = -P1x + P11*cosd(90-Theta(1));
deltaY = -P1y + P11*sind(90-Theta(1));
PL1 = Distance(deltaX, deltaY, 0, 0);
%Length of Cylinder 2
Ax = P21*cosd(Theta(1)); %x coordinate of P21
Ay = P21*sind(Theta(1)); %y coordinate of P21
Bx = D1*cosd(Theta(1)) + P22*cosd(Theta(1) + Theta(2));
By = D1*sind(Theta(1)) + P22*sind(Theta(1) + Theta(2));
PL2 = Distance(Ax, Ay, Bx, By);
%Store Lengths in an array
lengths = [PL1 PL2];
end

