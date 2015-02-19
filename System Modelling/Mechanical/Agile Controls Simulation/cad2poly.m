
function [p,V,p2,V2] = cad2poly(filename, filename2)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main File : cad2poly.m 
% Source Files: cad2mat.m 
% Description : Converts CAD geometry into multiple polygons and plots
%               the resulting geometry
% Input       : filename, filename2 -filenames of the geometry to convert
% Output      : p, V, p2, V2 -The corresponding polygons and vertices of
%               the geometry in filename and filename2, respectively.
% Author      : Dr. L.A. Rodriguez
% Date        : 02/04/2014
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Converts CAD data to MATLAB using the cad2ply.m file, which is a 
% modified version of the cad2matdemo.m file located on the 
% Mathworks central file exchange.

% F-faces, V-vertices, C-color
[F,V,C] = cad2mat(filename);
[F2,V2,C2] = cad2mat(filename2);
if strcmp(filename, 'Thigh.stl')
    V(:,2) = V(:,2) - 0.445;
    V(:,2) = V(:,2)*(-1);
    V(:,1) = V(:,1) - 0.05;
    x = V(:,1);
    V(:,1) = V(:,2);
    V(:,2) = x;
    V(:,1) = V(:,1);
    dTheta = 33;
    V = (V * [cosd(dTheta) -sind(dTheta) 0;
             sind(dTheta) cosd(dTheta)   0;
             0                  0        1]);
end
if strcmp(filename2, 'Shank.stl')
    x2 = V2(:,1);
    V2(:,1) = V2(:,2);
    V2(:,2) = x2 - 0.05;
    V2(:,1) = V2(:,1) * -1 + 0.27;
end


h = figure(1);
clf;
p = patch('faces', F, 'vertices' ,V);    % create the polygons
p2 = patch('faces', F2, 'vertices' ,V2); % create the polygons

set(p, 'facec', 'flat');             % Set the face color flat
set(p2, 'facec', 'flat');            % Set the face color flat


set(p, 'FaceVertexCData', C);        % Set the color (from file)
set(p2, 'FaceVertexCData', C);       % Set the color (from file)


set(p, 'EdgeColor','none');          % Set the edge color
set(p2, 'EdgeColor','none');         % Set the edge color

% Color options yellow,magenta,cyan,red,green,blue,white, black
set(p,'FaceColor','red')            % set color of filename geometry
set(p2,'FaceColor','cyan')          % set color of filename2 geometry


light                               % add a default light
daspect([1 1 1])                    % Setting the aspect ratio
view(3)                             % Plot isometric view

xlabel('X'),ylabel('Y'),zlabel('Z')
%title({['Imported Solidworks Geometry from ' filename ' and ' filename2] ' Used to animate a 2-link robot'})
title(['Imported Solidworks Geometry from ' filename ' and ' filename2])
drawnow     
shg

% To use homogenous transformation matrices the n by 3 vertices will be 
% turned to n by 4 vertices by augmenting them with ones, [V;1]

V =  [V ones(length(V),1)]';
V2 = [V2 ones(length(V2),1)]';


