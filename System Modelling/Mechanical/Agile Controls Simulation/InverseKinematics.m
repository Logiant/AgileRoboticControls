%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main File   : InverseKinematics.m
% Source Files: None 
% Dependancies: None
% Description : Calculates the angles required by each of the legs to place
% the foot of the robot into a certain position
% Input       : L1 - Length of the hip joint to the knee joint
%               L2 - Length of the knee joint to the foot
%               x - x position of the foot
%               y - y position of the foot
% Output      : angles - array angles [angle of thigh, angle of shank]
% Author      : Logan Beaver
% Date        : 09/20/2014
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function angles = InverseKinematics(L1,L2, x, y)
%"max()" is used to ensure the robot stays within its operational bounds
num = max((L1+L2)^2 - (x^2 + y^2), 0);
den = max((x^2 + y^2) - (L1-L2)^2, 0);
theta2 = -2*atan2(sqrt(num),sqrt(den));
num = y*(L1+L2*cos(theta2)) - L2*x*sin(theta2);
den = x*(L1+L2*cos(theta2)) + L2*y*sin(theta2);
theta1 = atan2(num,den)*180/pi;
theta2 = theta2*180/pi;
angles = [theta1, theta2];
end