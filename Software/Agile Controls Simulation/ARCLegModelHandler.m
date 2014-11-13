%Handles configuration of the leg model and inputting values in LegModel.m
%Logan Beaver 10/23/14
Link1 = .stl;
Link2 = .stl
L1 = 10;    %cm
L2 = 10;    %cm
L12 = L1;   %cm
L21 = L2/3; %cm
P1x = 0;    %cm
P1y = -5;   %cm
P11 = L1/2; %cm
P21 = L1/2;    %cm
P22 = 0;    %cm
maxVals = LegModel(0,0,0,0,0,0,0,0,0,0,0);