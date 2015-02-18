
function Rz = RotZ(theta)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main File   : RotZ.m 
% Source Files: None 
% Description : Computes the homogeneus rotation matrix about the Z-axis
% Input       : theta - angle in degrees
% Output      : Rz - 4x4 homogeneous matrix
% Author      : Dr. L.A. Rodriguez
% Date        : 02/04/2014
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

c = cosd(theta);
s = sind(theta);
Rz = [c -s 0 0; 
      s  c 0 0; 
      0  0 1 0; 
      0  0 0 1];
