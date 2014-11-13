%The inverse kinematics to determine the robot's necessary position
%Logan Beaver ,10/4/14
function [theta1, theta2] = invKin(x, y, L1, L2)
%"max()" is used to ensure the robot stays within its operational bounds
num = max((L1+L2)^2 - (x^2 + y^2), 0);
den = max((x^2 + y^2) - (L1-L2)^2, 0);
theta2 = -2*atan2(sqrt(num),sqrt(den));
num = y*(L1+L2*cos(theta2)) - L2*x*sin(theta2);
den = x*(L1+L2*cos(theta2)) + L2*y*sin(theta2);
theta1 = atan2(num,den)*180/pi;
theta2 = theta2*180/pi;
end