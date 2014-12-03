%Handles configuration of the leg model and inputting values in LegModel.m
%Logan Beaver 10/23/14
Link1 = '.stl';
Link2 = '.stl';
L1 = 10;    %cm
L2 = 10;    %cm
L12 = L1;   %cm
L21 = L2/3; %cm
P1x = 0;    %cm
P1y = -5;   %cm
P11 = L1/2; %cm
P21 = L1/2; %cm
P22 = 0;    %cm
theta1 = 0;theta2 = 0;
maxVals = LegModel(Link1,Link2,L1,L2,L12,L21,P1x,P1y,P11,P21,P22,theta1,theta2, BoxStep);
