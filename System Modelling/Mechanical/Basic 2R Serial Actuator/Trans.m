
function T = Trans(x,y,z)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main File   : Trans.m 
% Source Files: None 
% Description : Computes the homogeneus traslation matrix
% Input       : x,y,z - distance to translate in the respective axis
% Output      : T - 4x4 homogeneous matrix
% Author      : Dr. L.A. Rodriguez
% Date        : 02/04/2014
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

T = [1 0 0 x; 
     0 1 0 y; 
     0 0 1 z; 
     0 0 0 1];
