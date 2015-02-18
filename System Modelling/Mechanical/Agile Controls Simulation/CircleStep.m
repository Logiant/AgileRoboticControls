function positions = CircleStep()
r = 0.10;

positions = [0:1:360; 0:1:360]; %degrees
positions = [cosd(positions(1,:))*r; sind(positions(2,:))*r];
positions(2,:) = positions(2,:) - .26;
positions = positions' * 100;
end