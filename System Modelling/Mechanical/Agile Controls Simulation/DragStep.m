%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main File   : DragStep.m
% Source Files: None 
% Dependancies: None
% Description : Sets the positions for a step in which the robot is dragged
% Input       : None
% Output      : positions - array representing the points the leg must be
% moved to execute this step
% Author      : Logan Beaver
% Date        : 09/28/2014
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function positions = DragStep()
positions = [0.125:-0.005:-0.125; (0.125:-0.005:-0.125)*0 - 0.55]' * 100;
end