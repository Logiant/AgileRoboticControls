%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main File   : ForwardKinematics.m
% Source Files: None 
% Dependancies: None
% Description : Calculates the foot position when given distances and
% thetas for a robot leg
% Input       : D1 - distance from hip joint to knee joint
%               D2 - distance from knee joint to foot
%               T1 - theta of the thigh from the hip aka link 1
%               T2 - theta of the shank from the thigh aka link 2
% Output      : footPos - he foot position array [x,y]
% Author      : Logan Beaver
% Date        : 09/20/2014
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function footPos = ForwardKinematics(D1,D2,T1,T2)
x = D1*cosd(T1) + D2*cosd(T1+T2);
y = D1*sind(T1) + D2*sind(T1+T2);
footPos = [x, y];
end

