%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main File   : BoxStep.m
% Source Files: None 
% Dependancies: None
% Description : Sets the positions for a box step
% Input       : None
% Output      : points - array representing the points the leg must be
% moved to execute this step
% Author      : Logan Beaver
% Date        : 09/26/2014
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function points = BoxStep()
points = [-.125, -.35; -.125, -.25; .125, -.25; .125, -.35; -.125, -.35]*100;
end