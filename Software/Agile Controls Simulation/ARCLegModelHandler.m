%Handles configuration of the leg model and inputting values in LegModel.m
%Logan Beaver 10/23/14
clear; clc; close all;
Link1 = 'Link1.stl';
Link2 = 'Link2.stl';
L1 = 40;    %cm
L2 = 20;    %cm
L12 = L1;   %cm
L21 = 0;    %cm
P1x = -5;   %cm
P1y = 0;    %cm
P11 = L1/2; %cm
P21 = L1/2; %cm
P22 = L2/2;    %cm
sampleDistance = 1; %cm
time = 0.5; %seconds
maxVals = LegModel(Link1,Link2,L1,L2,L12,L21,P1x,P1y,P11,P21,P22,SemiEllipseStep,sampleDistance,time);
%print interesting values here