%positions.m

H = [0; 0];
B = [-35; 0];
P1 = [-17.45; -11];
P2 = [-12.84; -31.3];
K = [27.71; -43];
P3 = [-3.5; -20];

theta = input('Hip Angle: ');
phi = input('Knee Angle: ');
TH = input('Hip Torque: ');
TK = input('Knee Torque: ');

FP = TH*.2032;
FD = TK*.2;

P3 = [cosd(phi) sind(phi); -sind(phi) cosd(phi)]*P3;
P3 = P3+[43; 0];

P1 = [cosd(theta) sind(theta); sind(theta) cosd(theta)]*P1;
P2 = [cosd(theta) sind(theta); sind(theta) cosd(theta)]*P2;
P3 = [cosd(theta) sind(theta); sind(theta) cosd(theta)]*P3;

DP = atand((P1(2)-B(2))/(B(1)-P1(1)));
DT = atand((P3(1)-P2(1))/(P3(2)-P2(2)));
DS = atand((P2(2)-P3(2))/(P2(1)-P3(1)));

FH = FP*[cosd(DP); sind(DP)];
FKt = FD*[-sind(DT); cosd(DT)];
FKs = FD*[cosd(DS); -sind(DS)];