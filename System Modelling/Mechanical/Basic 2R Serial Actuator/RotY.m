
function Ry = RotY(theta)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main File : RotY.m 
% Source Files: None 
% Description : Computes the homogeneus rotation matrix about the Y-axis
% Input       : theta - angle in degrees
% Output      : Ry - 4x4 homogeneous matrix
% Author      : Dr. L.A. Rodriguez
% Date        : 02/04/2014
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

c = cosd(theta);
s = sind(theta);

Ry = [c 0 s 0; 
      0 1 0 0; 
     -s 0 c 0; 
      0 0 0 1];
