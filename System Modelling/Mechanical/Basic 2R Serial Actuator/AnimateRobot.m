% ----------------------------------------------------------------------
% Main File   : AnimateRobot.m
% Source Files: cad2poly.m, Trans.m, RotZ.m 
% Description : This script animates the motion of a 2-link robot. It 
%               converts CAD data to MATLAB using the cad2ply.m function 
%               file.
% Author: Dr. Luis A. Rodriguez
% Date: 06/10/2014
% Bugs: none known
% -------------------------------------------------------------------
clear all
clc

% File names of the CAD geometry] to convert to polygons
Link1  = 'Link1.STL';
Link2  = 'Link2.STL';

% Converts CAD geometry into multiple polygons and into its vertices
% link1Pnts  and link2Pnts already includes the bottom
% row of ones, that is link1Pnts = [Pnts;1]
[p,link1Pnts,p2,link2Pnts] = cad2poly(Link1, Link2);

fprintf('\n Animation is ready!! Please hit return to continue.\n')
pause   

% Set axis manually
axis([-35 35 -35 35 -35 35]);
hold on;

%View in 2-D
view(2); %

% radius of circle drawn and initial angle 
% Link Dimensions from center to center
L1 = 18; 
L2 = 12;

%set theta1, theta2 to initial values for first point
theta1 = 0; theta2 = 0;
r = 12;

%positions = [0:360; 0:360];
%positions = [cos(positions(1,:)*pi/180); sin(positions(2,:)*pi/180)];
%positions = r * positions;
%above for circle, below for walking
positions = [180:-1:0; 180:-1:0]; %initial semicircle
positions = [cos(positions(1,:)*pi/180)*r; sin(positions(2,:)*pi/180)*r];
pos2 = [0:180; 0:180];
pos2 = [cos(pos2(1,:)*pi/180)*r; positions(2,:)*0]; %set Y to zero
positions = [positions, pos2];
positions(2,:) = positions(2,:) - 2*r;


% Pre-allocate memory to store x-,y-coordinates
x = inf(length(positions),1);
y = inf(length(positions),1);
h0 = plot(1,1);

% Animated robot 
title('Two-link Robot Animation')

for count = 1:length(positions)
    
    %update angles based on next position
    [theta1, theta2] = invKin(positions(1,count), positions(2,count), L1, L2);
    
    drawRobot(p,p2,theta1,theta2,link1Pnts,link2Pnts)

    % draw circle
    %set x(k) to the current position of the end
    [x(count), y(count)] = fwdKin(theta1, theta2, L1, L2);
    h = plot(x(1:count),y(1:count),'-'); % save current graphics handle
    set(h0, 'XData', [], 'YData', []); % Erase previous line data
    drawnow()
    h0 = h;
    
    % pause program for .05 sec to see animation
    pause(.1)
    
end % End AnimateRobot.m

