function positions = SemiEllipseStep()
halfStep = 0.25;%m
stepHeight = 0.05;%m
positions = [180:-1:0; 180:-1:0]; %initial semicircle
positions = [cos(positions(1,:)*pi/180)*halfStep; sin(positions(2,:)*pi/180)*stepHeight];
pos2 = [0:180; 0:180];
pos2 = [cos(pos2(1,:)*pi/180)*halfStep; positions(2,:)*0]; %set Y to zero
positions = [positions, pos2];
positions(2,:) = positions(2,:) - .5;
positions(1,:) = positions(1,:) + .02;

for i = 2:length(positions)-1;
   positions(2,i) = (positions(2,i-1)*2 + positions(2,i+1)*2)/4;
end
positions = positions' * 100;

end