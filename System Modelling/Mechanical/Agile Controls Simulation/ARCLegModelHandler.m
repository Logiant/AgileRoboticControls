%Handles configuration of the leg model and inputting values in LegModel.m
%Logan Beaver 10/23/14
clear; clc; close all;
Link1 = 'Thigh.stl';
Link2 = 'Shank.stl';
%read excel data%
CONSTANTS = ReadExcelData();
%assign the 12 read variables
totalWeight = CONSTANTS(1);         % n
bodyLength = CONSTANTS(2);          % m
bodyCg = CONSTANTS(3);              % m from front
L1 = CONSTANTS(4);                  % cm1
iT = CONSTANTS(5);                  % m^4
thighCg = CONSTANTS(6);             % m
tMass = CONSTANTS(7);               % kg
L2 = CONSTANTS(8);                  % cm
iS = CONSTANTS(9);                  % m^4
shankCg = CONSTANTS(10);            % m
sMass = CONSTANTS(11);              % kg
frictionFactor = CONSTANTS(12);     % unitless

%Cylinder velocities/accelerations, not relevant
L12 = L1;   %cm
L21 = 0;    %cm
P1x = -5;   %cm
P1y = 0;    %cm
P11 = L1/2; %cm
P21 = L1/2; %cm
P22 = L2/2;    %cm


sampleDistance = 10; %cm - interpolation value for under-defined gaits
bodyVel = input('Insert Body Velocity In Meters per Second: '); % meters per second
stepDist = input('Insert Step Distance In Meters: '); % seconds
time = stepDist/bodyVel; %time to complete this step at the required speed
fprintf('Time Alloted for Step: %g seconds\n', time);
choice = input('Is this a foot drag (y/N): ', 's'); % seconds
if choice == 'y'
    dragging = true;
    fprintf('Running foot drag simulation...\n');
    func = DragStep;
else
    dragging = false;
    fprintf('Running step simulation...\n');
    func = SemiEllipseStep;
end

%read values from excel sheet
% ---- CONFIGURE STEP HERE BASED ON LEG LENGTHS AND STEP DISTANCE ------- % 
Thetas = LegModel(Link1,Link2,L1,L2,L12,L21,P1x,P1y,P11,P21,P22,func,sampleDistance,time);

t = [0; cumsum(dt)];

theta1 = Thetas(:,1); %grabbing theta 1
theta2 = Thetas(:,2); %grabbing theta 2

dTheta1 = diff(theta1)./dt; %deltaTheta / deltaTime
dTheta2 = diff(theta2)./dt; %deltaTheta / deltaTime

ddTheta1 = diff(dTheta1)./dt(1:length(dt)-1);
ddTheta2 = diff(dTheta2)./dt(1:length(dt)-1);


MatrixDynamics();

%Put forces into moment equations
syms FH1x FH2x FH3x FH4x FH1y FH2y FH3y FH4y;
syms FK1x FK2x FK3x FK4x FK1y FK2y FK3y FK4y;


%Important values ---------------------------------- TOTAL WEIGHT
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

%create and subs forces
F = [FORCES.FK1x; FORCES.FH1x; FORCES.FK2x; FORCES.FH2x;  ...
     FORCES.FK3x; FORCES.FH3x; FORCES.FK4x; FORCES.FH4x; ...
     FORCES.FK1y; FORCES.FH1y; FORCES.FK2y; FORCES.FH2y;  ...
     FORCES.FK3y; FORCES.FH3y; FORCES.FK4y; FORCES.FH4y];


%values to be set to constant values -------------------------SET ANGLES
syms x y tb th2 th3 th4 tk2 tk3 tk4;
syms xdot ydot tbdot th2dot th3dot th4dot tk2dot tk3dot tk4dot;
syms xddot yddot tbddot th2ddot th3ddot th4ddot tk2ddot tk3ddot tk4ddot;
%body vals---------------------------------------------------BODY ANGLES
T = subs(T, x, 0); T = subs(T, y, 0); T = subs(T, xdot, bodyVel); T = subs(T, ydot, 0);
T = subs(T, xddot, 0);  T = subs(T, yddot, 0);
T = subs(T, tb, 0) ;T = subs(T, tbdot, 0); T = subs(T, tbddot, 0);
F = subs(F, x, 0); F = subs(F, y, 0); F = subs(F, xdot, bodyVel); F = subs(F, ydot, 0);
%forces
F = subs(F, xddot, 0);  F = subs(F, yddot, 0);
F = subs(F, tb, 0) ;F = subs(F, tbdot, 0); F = subs(F, tbddot, 0);
%limb vals-------------------------------------------------3 LIMB ANGLES
T = subs(T, th2, pi); T = subs(T, th3, pi); T = subs(T, th4, pi);
T = subs(T, tk2, 0); T = subs(T, tk3, 0); T = subs(T, tk4, 0);
T = subs(T, th2dot, 0); T = subs(T, th3dot, 0); T = subs(T, th4dot, 0);
T = subs(T, tk2dot, 0); T = subs(T, tk3dot, 0); T = subs(T, tk4dot, 0);
T = subs(T, th2ddot, 0); T = subs(T, th3ddot, 0); T = subs(T, th4ddot, 0);
T = subs(T, tk2ddot, 0); T = subs(T, tk3ddot, 0); T = subs(T, tk4ddot, 0);
%forces
F = subs(F, th2, pi); F = subs(F, th3, pi); F = subs(F, th4, pi);
F = subs(F, tk2, 0); F = subs(F, tk3, 0); F = subs(F, tk4, 0);
F = subs(F, th2dot, 0); F = subs(F, th3dot, 0); F = subs(F, th4dot, 0);
F = subs(F, tk2dot, 0); F = subs(F, tk3dot, 0); F = subs(F, tk4dot, 0);
F = subs(F, th2ddot, 0); F = subs(F, th3ddot, 0); F = subs(F, th4ddot, 0);
F = subs(F, tk2ddot, 0); F = subs(F, tk3ddot, 0); F = subs(F, tk4ddot, 0);
%force values-----------------------------------------------FOOT FORCES
syms FF1x FF1y FF2x FF2y FF3x FF3y FF4x FF4y;
if dragging
    T = subs(T, FF1x, 3*totalWeight/4*frictionFactor); T = subs(T, FF2x, totalWeight/4*frictionFactor); T = subs(T, FF3x, totalWeight/4*frictionFactor); T = subs(T, FF4x, totalWeight/4*frictionFactor);
    T = subs(T, FF1y, totalWeight/4); T = subs(T, FF2y, totalWeight/4); T = subs(T, FF3y, totalWeight/4); T = subs(T, FF4y, totalWeight/4);
    %force
    F = subs(F, FF1x, 3*totalWeight/4*frictionFactor); F = subs(F, FF2x, totalWeight/4*frictionFactor); F = subs(F, FF3x, totalWeight/4*frictionFactor); F = subs(F, FF4x, totalWeight/4*frictionFactor);
    F = subs(F, FF1y, totalWeight/4); F = subs(F, FF2y, totalWeight/4); F = subs(F, FF3y, totalWeight/4); F = subs(F, FF4y, totalWeight/4);
else
    T = subs(T, FF1x, 0); T = subs(T, FF2x, 0); T = subs(T, FF3x, 0); T = subs(T, FF4x, 0);
    T = subs(T, FF1y, 0); T = subs(T, FF2y, totalWeight/3); T = subs(T, FF3y, totalWeight/3); T = subs(T, FF4y, totalWeight/3);
    %force
    F = subs(F, FF1x, 0); F = subs(F, FF2x, 0); F = subs(F, FF3x, 0); F = subs(F, FF4x, 0);
    F = subs(F, FF1y, 0); F = subs(F, FF2y, totalWeight/3); F = subs(F, FF3y, totalWeight/3); F = subs(F, FF4y, totalWeight/3);
end

%masses and weights ---------------------------------------MASSES
syms mS1 mS2 mS3 mS4 mT1 mT2 mT3 mT4 g;
T = subs(T, mS1, sMass);T = subs(T, mS2, sMass);T = subs(T, mS3, sMass);T = subs(T, mS4, sMass);
T = subs(T, mT1, tMass);T = subs(T, mT2, tMass);T = subs(T, mT3, tMass);T = subs(T, mT4, tMass);
T = subs(T, g, 9.81);
%forces
F = subs(F, mS1, sMass);F = subs(F, mS2, sMass);F = subs(F, mS3, sMass);F = subs(F, mS4, sMass);
F = subs(F, mT1, tMass);F = subs(F, mT2, tMass);F = subs(F, mT3, tMass);F = subs(F, mT4, tMass);
F = subs(F, g, 9.81);
%Lengths--------------------------------------------------LIMB CGs
syms LH1 LH2 LH3 LH4 LK1 LK2 LK3 LK4 LF1 LF2 LF3 LF4 LT1 LT2 LT3 LT4 LS1 LS2 LS3 LS4;
%L1 L2 L3 L4 are converted to m from cm by dividing by 100
T = subs(T, LK1, L1/100);T = subs(T, LK2, bodyLength-L1/100);T = subs(T, LK3, L1/100);T = subs(T, LK4, bodyLength-L1/100);
T = subs(T, LF1, L2/100);T = subs(T, LF2, L2/100);T = subs(T, LF3, L2/100);T = subs(T, LF4, L2/100);
T = subs(T, LH1, bodyCg);T = subs(T, LH2, bodyCg);T = subs(T, LH3, bodyCg);T = subs(T, LH4, bodyCg);
T = subs(T, LT1, thighCg);T = subs(T, LT2, thighCg);T = subs(T, LT3, thighCg);T = subs(T, LT4, thighCg);
T = subs(T, LS1, shankCg);T = subs(T, LS2, shankCg);T = subs(T, LS3, shankCg);T = subs(T, LS4, shankCg);
%forces
F = subs(F, LK1, L1/100);F = subs(F, LK2, bodyLength-L1/100);F = subs(F, LK3, L1/100);F = subs(F, LK4, bodyLength-L1/100);
F = subs(F, LF1, L2/100);F = subs(F, LF2, L2/100);F = subs(F, LF3, L2/100);F = subs(F, LF4, L2/100);
F = subs(F, LH1, bodyCg);F = subs(F, LH2, bodyCg);F = subs(F, LH3, bodyCg);F = subs(F, LH4, bodyCg);
F = subs(F, LT1, thighCg);F = subs(F, LT2, thighCg);F = subs(F, LT3, thighCg);F = subs(F, LT4, thighCg);
F = subs(F, LS1, shankCg);F = subs(F, LS2, shankCg);TF= subs(F, LS3, shankCg);F = subs(F, LS4, shankCg);
%Moments of Inertia-------------------------------------INERTIA
syms IS1z IT1z IS2z IS3z IS4z IT2z IT3z IT4z;
T = subs(T, IS1z, iS);T = subs(T, IT1z, iT);
F = subs(F, IS1z, iS);F = subs(F, IT1z, iT);

%T = subs(T, IS2z, iS);T = subs(T, IT2z, iT);
%T = subs(T, IS3z, iS);T = subs(T, IT3z, iT);
%T = subs(T, IS4z, iS);T = subs(T, IT4z, iT);

syms th1 tk1 th1dot tk1dot th1ddot tk1ddot

Tindex = 1;
Tval = 0;
Findex = 1;
Fval = 0;

fprintf('Calculaing Average and Maximum Torque/Force...\n');
for i=1:length(ddTheta1)%Loop to get all the torques added to the sum
 
    Ti = T;
    Ti = subs(Ti, th1, theta1(i));        Ti = subs(Ti, tk1, theta2(i));
    Ti = subs(Ti, th1dot, dTheta1(i));    Ti = subs(Ti, tk1dot, dTheta2(i));
    Ti = subs(Ti, th1ddot, ddTheta1(i));  Ti = subs(Ti, tk1ddot, ddTheta2(i));

    
    Fi = F;
    Fi = subs(Fi, th1, theta1(i));        Fi = subs(Fi, tk1, theta2(i));
    Fi = subs(Fi, th1dot, dTheta1(i));    Fi = subs(Fi, tk1dot, dTheta2(i));
    Fi = subs(Fi, th1ddot, ddTheta1(i));  Fi = subs(Fi, tk1ddot, ddTheta2(i));

    if i == 1
        FTotal = eval(Fi);
        TTotal = eval(Ti);
    else
        FTotal(:,i) = eval(Fi);
        TTotal(:,i) = eval(Ti);
    end
    if mean(FTotal(:,i)) > mean(Fval) && (i > 1) %probably should find equivilant force instead of max average...
        Fval = FTotal(:,i);
        Findex = i;
    end
    if mean(TTotal(:,i)) > mean(Tval) && (i > 1)%compare the max singular torque instead?
        Tval = mean(TTotal(:,i));
        Tindex = i;
    end
end

fprintf('Fetching robot state at critical points\n');

%Divide the torques by the number of vals - average
avgT = (trapz(t(2:length(t)-1),TTotal') / sum(dt))';
avgF = (trapz(t(2:length(t)-1),FTotal') / sum(dt))';

thetas1 = [theta1(Tindex) theta2(Tindex)];
dThetas1 = [dTheta1(Tindex) dTheta2(Tindex)];
ddThetas1 = [ddTheta1(Tindex) ddTheta2(Tindex)];

thetas2 = [theta1(Findex) theta2(Findex)];
dThetas2 = [dTheta1(Findex) dTheta2(Findex)];
ddThetas2 = [ddTheta1(Findex) ddTheta2(Findex)];

fprintf('Calculaing Forces and Torques...\n');

FI1 = F;
TI1 = T;
%Insert Values-------------------------------------------ANGLES
TI1 = subs(TI1, th1, thetas1(1));        TI1 = subs(TI1, tk1, thetas1(2));
TI1 = subs(TI1, th1dot, dThetas1(1));    TI1 = subs(TI1, tk1dot, dThetas1(2));
TI1 = subs(TI1, th1ddot, ddThetas1(1));  TI1 = subs(TI1, tk1ddot, ddThetas1(2));
%forces
FI1 = subs(FI1, th1, thetas1(1));        FI1 = subs(FI1, tk1, thetas1(2));
FI1 = subs(FI1, th1dot, dThetas1(1));    FI1 = subs(FI1, tk1dot, dThetas1(2));
FI1 = subs(FI1, th1ddot, ddThetas1(1));  FI1 = subs(FI1, tk1ddot, ddThetas1(2));

FI2 = F;
TI2 = T;
%Insert Values-------------------------------------------ANGLES
TI2 = subs(TI2, th1, thetas2(1));        TI2 = subs(TI2, tk1, thetas2(2));
TI2 = subs(TI2, th1dot, dThetas2(1));    TI2 = subs(TI2, tk1dot, dThetas2(2));
TI2 = subs(TI2, th1ddot, ddThetas2(1));  TI2 = subs(TI2, tk1ddot, ddThetas2(2));
%forces
FI2 = subs(FI2, th1, thetas2(1));        FI2 = subs(FI2, tk1, thetas2(2));
FI2 = subs(FI2, th1dot, dThetas2(1));    FI2 = subs(FI2, tk1dot, dThetas2(2));
FI2 = subs(FI2, th1ddot, ddThetas2(1));  FI2 = subs(FI2, tk1ddot, ddThetas2(2));


TI1=eval(TI1);
TI2=eval(TI2);
FI1=eval(FI1);
FI2=eval(FI2);
if ~dragging
    fprintf('Calculating step impulse force\n');
    %F = mLeg * vLeg - impulse momentum equations
end


fprintf('Simulation complete!\n');

