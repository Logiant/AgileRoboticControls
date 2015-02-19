function positions = SemiEllipseStep()
halfStep = 0.25;%m
stepHeight = 0.05;%m
positions = [180:-1:0; 180:-1:0]; %initial semicircle
positions = [cos(positions(1,:)*pi/180)*halfStep; sin(positions(2,:)*pi/180)*stepHeight];
positions(2,:) = positions(2,:) - .7;
positions(1,:) = positions(1,:) + .02;

for i = 2:length(positions)-1;
   positions(2,i) = (positions(2,i-1)*2 + positions(2,i+1)*2)/4;
end
positions = positions' * 100;

%positions = [positions; positions(1,:)];
end