%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main File   : CircleStep.m
% Source Files: None 
% Dependancies: None
% Description : Sets the positions for a circular step
% Input       : None
% Output      : positions - array representing the points the leg must be
% moved to execute this step
% Author      : Logan Beaver
% Date        : 09/26/2014
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function positions = CircleStep()
r = 0.10;

positions = [0:1:360; 0:1:360]; %degrees
positions = [cosd(positions(1,:))*r; sind(positions(2,:))*r];
positions(2,:) = positions(2,:) - .26;
positions = positions' * 100;
end