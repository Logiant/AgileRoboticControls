%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main File   : Distance.m
% Source Files: None 
% Dependancies: None
% Description : Distance Formula implementation
% Input       : x1 - x component of position 1
%               y1 - y component of position 1
%               x2 - x component of position 2
%               y2 - y component of position 2
% Output      : d - distance between the two positions
% Author      : Logan Beaver
% Date        : 09/15/2014
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function d = Distance(x1, y1, x2, y2)
    d = sqrt((x1-x2)^2 + (y1-y2)^2);
end

