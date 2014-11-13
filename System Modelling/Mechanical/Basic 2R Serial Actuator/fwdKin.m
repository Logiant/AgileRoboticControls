%Logan Beaver
%2 DOF Revolute Serial Arm Forward Kinematics
function [x, y] = fwdKin(theta1, theta2, L1, L2)
x = L1*cosd(theta1) + L2*cosd(theta1 + theta2);
y = L1*sind(theta1) + L2*sind(theta1 + theta2);
end