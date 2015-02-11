%Handles configuration of the leg model and inputting values in LegModel.m
%Logan Beaver 10/23/14
clear; clc; close all;
Link1 = 'Link1.stl';
Link2 = 'Link2.stl';
L1 = 52;    %cm
L2 = 24;    %cm
L12 = L1;   %cm
L21 = 0;    %cm
P1x = -5;   %cm
P1y = 0;    %cm
P11 = L1/2; %cm
P21 = L1/2; %cm
P22 = L2/2;    %cm
sampleDistance = 2; %cm
time = 2; %seconds
Thetas = LegModel(Link1,Link2,L1,L2,L12,L21,P1x,P1y,P11,P21,P22,SemiEllipseStep,sampleDistance,time);
%print interesting values here


theta1 = Thetas(:,1);
theta2 = Thetas(:,2);
t = dt;
dt = diff(dt)';
dt = dt(1);

dTheta1 = diff(theta1)/dt;
dTheta2 = diff(theta2)/dt;

ddTheta1 = diff(dTheta1)/dt;
ddTheta2 = diff(dTheta2)/dt;


index1 = find(max(abs(ddTheta1)) == abs(ddTheta1)); %Find discontinuity
index2 = find(max(abs(ddTheta2)) == abs(ddTheta2)); %Find discontinuity

dIndex = min(min(index1), min(index2)) - 15;

index1 = find(max(abs(ddTheta1(1:index1-15))) == abs(ddTheta1(1:index1-15))) - 15; %get max before
index2 = find(max(abs(ddTheta2(1:index1-15))) == abs(ddTheta2(1:index2-15))) - 15; %get max before

thetas1 = [theta1(index1) theta2(index1)];
dThetas1 = [dTheta1(index1) dTheta2(index1)];
ddThetas1 = [ddTheta1(index1) ddTheta2(index1)];


thetas2 = [theta1(index2) theta2(index2)];
dThetas2 = [dTheta1(index2) dTheta2(index2)];
ddThetas2 = [ddTheta1(index2) ddTheta2(index2)];

MatrixDynamics();

%Put forces into moment equations
syms FH1x FH2x FH3x FH4x FH1y FH2y FH3y FH4y;
syms FK1x FK2x FK3x FK4x FK1y FK2y FK3y FK4y;


%Important values ---------------------------------- TOTAL WEIGHT
totalWeight = 138; %N
%subs forces into Torque equations
T = [Ts.TH1; Ts.TH2; Ts.TH3; Ts.TH4; Ts.TK1; Ts.TK2; Ts.TK3; Ts.TK4];


T = subs(T, FK1x, FORCES.FK1x);T = subs(T, FK2x, FORCES.FK2x);
T = subs(T, FK3x, FORCES.FK3x);T = subs(T, FK4x, FORCES.FK4x);
T = subs(T, FK1y, FORCES.FK1y);T = subs(T, FK2y, FORCES.FK2y);
T = subs(T, FK3y, FORCES.FK3y);T = subs(T, FK4y, FORCES.FK4y);
T = subs(T, FH1x, FORCES.FH1x);T = subs(T, FH2x, FORCES.FH2x);
T = subs(T, FH3x, FORCES.FH3x);T = subs(T, FH4x, FORCES.FH4x);
T = subs(T, FH1y, FORCES.FH1y);T = subs(T, FH2y, FORCES.FH2y);
T = subs(T, FH3y, FORCES.FH3y);T = subs(T, FH4y, FORCES.FH4y);



%values to be set to constant values -------------------------SET ANGLES
syms x y tb th2 th3 th4 tk2 tk3 tk4;
syms xdot ydot tbdot th2dot th3dot th4dot tk2dot tk3dot tk4dot;
syms xddot yddot tbddot th2ddot th3ddot th4ddot tk2ddot tk3ddot tk4ddot;
%body vals---------------------------------------------------BODY ANGLES
T = subs(T, x, 0); T = subs(T, y, 0); T = subs(T, xdot, 0.5); T = subs(T, ydot, 0.5);
T = subs(T, xddot, 0);  T = subs(T, yddot, 0);
T = subs(T, tb, 0) ;T = subs(T, tbdot, 0); T = subs(T, tbddot, 0);
%limb vals-------------------------------------------------3 LIMB ANGLES
T = subs(T, th2, pi); T = subs(T, th3, pi); T = subs(T, th4, pi);
T = subs(T, tk2, 0); T = subs(T, tk3, 0); T = subs(T, tk4, 0);
T = subs(T, th2dot, 0); T = subs(T, th3dot, 0); T = subs(T, th4dot, 0);
T = subs(T, tk2dot, 0); T = subs(T, tk3dot, 0); T = subs(T, tk4dot, 0);
T = subs(T, th2ddot, 0); T = subs(T, th3ddot, 0); T = subs(T, th4ddot, 0);
T = subs(T, tk2ddot, 0); T = subs(T, tk3ddot, 0); T = subs(T, tk4ddot, 0);
%force values-----------------------------------------------FOOT FORCES
syms FF1x FF1y FF2x FF2y FF3x FF3y FF4x FF4y;
T = subs(T, FF1x, 0); T = subs(T, FF2x, 0); T = subs(T, FF3x, 0); T = subs(T, FF4x, 0);
T = subs(T, FF1y, 0); T = subs(T, FF2y, totalWeight/3); T = subs(T, FF3y, totalWeight/3); T = subs(T, FF4y, totalWeight/3);
%masses and weights ---------------------------------------MASSES
syms mS1 mS2 mS3 mS4 mT1 mT2 mT3 mT4 g;
sMass = .93; tMass = .96; %kg
T = subs(T, mS1, sMass);T = subs(T, mS2, sMass);T = subs(T, mS3, sMass);T = subs(T, mS4, sMass);
T = subs(T, mT1, tMass);T = subs(T, mT2, tMass);T = subs(T, mT3, tMass);T = subs(T, mT4, tMass);
T = subs(T, g, 9.81);
%Lengths--------------------------------------------------LIMB CGs
syms LH1 LH2 LH3 LH4 LK1 LK2 LK3 LK4 LF1 LF2 LF3 LF4 LT1 LT2 LT3 LT4 LS1 LS2 LS3 LS4;
bodyLength = .5; bodyCg = 0.25; thighCg = .12; shankCg = 0.061; %m
%L1 L2 L3 L4 are converted to m from cm by dividing by 100
T = subs(T, LK1, L1/100);T = subs(T, LK2, bodyLength-L1/100);T = subs(T, LK3, L1/100);T = subs(T, LK4, bodyLength-L1/100);
T = subs(T, LF1, L2/100);T = subs(T, LF2, L2/100);T = subs(T, LF3, L2/100);T = subs(T, LF4, L2/100);
T = subs(T, LH1, bodyCg);T = subs(T, LH2, bodyCg);T = subs(T, LH3, bodyCg);T = subs(T, LH4, bodyCg);
T = subs(T, LT1, thighCg);T = subs(T, LT2, thighCg);T = subs(T, LT3, thighCg);T = subs(T, LT4, thighCg);
T = subs(T, LS1, shankCg);T = subs(T, LS2, shankCg);T = subs(T, LS3, shankCg);T = subs(T, LS4, shankCg);
%Moments of Inertia-------------------------------------INERTIA
syms IS1z IT1z IS2z IS3z IS4z IT2z IT3z IT4z;
iS = 0.000224; iT = 0.002562; %moments of inertia
T = subs(T, IS1z, iS);T = subs(T, IT1z, iT);
%T = subs(T, IS2z, iS);T = subs(T, IT2z, iT);
%T = subs(T, IS3z, iS);T = subs(T, IT3z, iT);
%T = subs(T, IS4z, iS);T = subs(T, IT4z, iT);


TI1 = T;
syms th1 tk1 th1dot tk1dot th1ddot tk1ddot
%Insert Values-------------------------------------------ANGLES
TI1 = subs(TI1, th1, thetas1(1));        TI1 = subs(TI1, tk1, thetas1(2));
TI1 = subs(TI1, th1dot, dThetas1(1));    TI1 = subs(TI1, tk1dot, dThetas1(2));
TI1 = subs(TI1, th1ddot, ddThetas1(1));  TI1 = subs(TI1, tk1ddot, ddThetas1(2));

%TI1 = subs(TI1, th2, -thetas1(1));        TI1 = subs(TI1, tk2, -thetas1(2));
%TI1 = subs(TI1, th2dot, -dThetas1(1));    TI1 = subs(TI1, tk2dot, -dThetas1(2));
%TI1 = subs(TI1, th2ddot, -ddThetas1(1));  TI1 = subs(TI1, tk2ddot, -ddThetas1(2));

%TI1 = subs(TI1, th3, -thetas1(1));        TI1 = subs(TI1, tk3, -thetas1(2));
%TI1 = subs(TI1, th3dot, -dThetas1(1));    TI1 = subs(TI1, tk3dot, -dThetas1(2));
%TI1 = subs(TI1, th3ddot, -ddThetas1(1));  TI1 = subs(TI1, tk3ddot, -ddThetas1(2));

%TI1 = subs(TI1, th4, thetas1(1));        TI1 = subs(TI1, tk4, thetas1(2));
%TI1 = subs(TI1, th4dot, dThetas1(1));    TI1 = subs(TI1, tk4dot, dThetas1(2));
%TI1 = subs(TI1, th4ddot, ddThetas1(1));  TI1 = subs(TI1, tk4ddot, ddThetas1(2));

TI2 = T;

TI2 = subs(TI2, th1, thetas2(1));        TI2 = subs(TI2, tk1, thetas2(2));
TI2 = subs(TI2, th1dot, dThetas2(1));    TI2 = subs(TI2, tk1dot, dThetas2(2));
TI2 = subs(TI2, th1ddot, ddThetas2(1));  TI2 = subs(TI2, tk1ddot, ddThetas2(2));


eval(TI1);
eval(TI2);


TTotal = 0;
for i=1:dIndex%Loop to get all the torques added to the sum
 
    Ti = T;
    Ti = subs(Ti, th1, theta1(i));        Ti = subs(Ti, tk1, theta2(i));
    Ti = subs(Ti, th1dot, dTheta1(i));    Ti = subs(Ti, tk1dot, dTheta2(i));
    Ti = subs(Ti, th1ddot, ddTheta1(i));  Ti = subs(Ti, tk1ddot, ddTheta2(i));

    TTotal = TTotal + eval(Ti);
end

%Divide the torques by the dIndex
TTotal = TTotal / dIndex;

