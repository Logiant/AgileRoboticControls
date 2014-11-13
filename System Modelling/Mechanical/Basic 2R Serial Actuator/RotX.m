%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main File : RotX.m 
% Source Files: None 
% Description : Computes the homogeneus rotation matrix about the X-axis
% Input       : theta - angle in degrees
% Output      : Rx - 4x4 homogeneous matrix
% Author      : Dr. L.A. Rodriguez
% Date        : 02/04/2014
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function Rx = RotX(theta)

c = cosd(theta);
s = sind(theta);
Rx = [1 0  0 0; 
      0 c -s 0; 
      0 s  c 0; 
      0 0  0 1];
