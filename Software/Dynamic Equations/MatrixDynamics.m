function [ output_args ] = MatrixDynamics( input_args )
%DYNAMICSFUNCTION Summary of this function goes here
%   Detailed explanation goes here

%       __________________
%      /  |            |  \
%     /   |            |   \
%    /    |            |    \
%    \    \            |    /
%     \    \          /    /
%      \    \        /   /
%      (2)  (4)      (3)   (1)
%
% 1 - front right, 3 - front left
% 2 - rear right,  4 - rear left

%kinematic symbols
syms x y LH1 LH2 LH3 LH4 LT1 LT2 LT3 LT4 LK1 LK2 LK3 LK4 LS1 LS2 LS3 LS4 LF1 LF2 LF3 LF4
syms tb th1 th2 th3 th4 tk1 tk2 tk3 tk4
syms xdot ydot tbdot th1dot th2dot th3dot th4dot tk1dot tk2dot tk3dot tk4dot
syms xddot yddot tbddot th1ddot th2ddot th3ddot th4ddot tk1ddot tk2ddot tk3ddot tk4ddot


%Leg 1 - FR, Leg 2 - RR, Leg 3 - FL, Leg 4 - RL
xH1 = x + LH1*cos(2*pi-(tb)); yH1 = y + LH1*sin(2*pi-(tb));
xH2 = x + LH2*cos((tb+pi)); yH2 = y + LH2*sin((tb+pi));
xH3 = x + LH3*cos(2*pi-(tb)); yH3 = y + LH3*sin(2*pi-(tb));
xH4 = x + LH4*cos((tb+pi)); yH4 = y + LH4*sin((tb+pi));

xT1 = x + LH1*cos(2*pi-(tb)) + LT1*cos(2*pi-(th1+tb)); yT1 = y + LH1*sin(2*pi-(tb)) + LT1*sin(2*pi-(th1+tb));
xT2 = x + LH2*cos((tb+pi)) + LT2*cos((th2+tb+pi)); yT2 = y + LH2*sin((tb+pi)) + LT1*sin((th2+tb+pi));
xT3 = x + LH3*cos(2*pi-(tb)) + LT3*cos(2*pi-(th3+tb)); yT3 = y + LH3*sin(2*pi-(tb)) + LT1*sin(2*pi-(th3+tb));
xT4 = x + LH4*cos((tb+pi)) + LT4*cos((th4+tb+pi)); yT4 = y + LH4*sin((tb+pi)) + LT1*sin((th4+tb+pi));

xK1 = x + LH1*cos(2*pi-(tb)) + LK1*cos(2*pi-(th1+tb)); yK1 = y + LH1*sin(2*pi-(tb)) + LK1*sin(2*pi-(th1+tb));
xK2 = x + LH2*cos(tb+pi) + LK2*cos(th2+tb+pi); yK2 = y + LH2*sin(tb+pi) + LK2*sin(th2+tb+pi);
xK3 = x + LH3*cos(2*pi-(tb)) + LK3*cos(2*pi-(th3+tb)); yK3 = y + LH3*sin(2*pi-(tb)) + LK3*sin(2*pi-(th3+tb));
xK4 = x + LH4*cos(tb+pi) + LK4*cos(th4+tb+pi); yK4 = y + LH4*sin(tb+pi) + LK4*sin(th4+tb+pi);

xS1 = x + LH1*cos(2*pi-(tb)) + LK1*cos(2*pi-(th1+tb)) + LS1*cos(2*pi-(tk1+th1+tb)); yS1 = y + LH1*sin(2*pi-(tb)) + LK1*sin(2*pi-(th1+tb)) + LS1*sin(2*pi-(tk1+th1+tb));
xS2 = x + LH2*cos(tb+pi) + LK2*cos(th2+tb+pi) + LS2*cos(tk2+th2+tb+pi); yS2 = y + LH2*sin(tb+pi) + LK2*sin(th2+tb+pi) + LS2*cos(tk2+th2+tb+pi);
xS3 = x + LH3*cos(2*pi-(tb)) + LK3*cos(2*pi-(th3+tb)) + LS3*cos(2*pi-(tk3+th3+tb)); yS3 = y + LH3*sin(2*pi-(tb)) + LK3*sin(2*pi-(th3+tb)) + LS3*sin(2*pi-(tk3+th3+tb));
xS4 = x + LH4*cos(tb+pi) + LK4*cos(th4+tb+pi) + LS4*cos(tk4+th4+tb+pi); yS4 = y + LH4*sin(tb+pi) + LK4*sin(th4+tb+pi) + LS4*cos(tk4+th4+tb+pi);

xF1 = x + LH1*cos(2*pi-(tb)) + LK1*cos(2*pi-(th1+tb)) + LF1*cos(2*pi-(tk1+th1+tb)); yF1 = y + LH1*sin(2*pi-(tb)) + LK1*sin(2*pi-(th1+tb)) + LF1*sin(2*pi-(tk1+th1+tb));
xF2 = x + LH2*cos(tb+pi) + LK2*cos(th2+tb+pi) + LF2*cos(tk2+th2+tb+pi); yF2 = y + LH2*sin(tb+pi) + LK2*sin(th2+tb+pi) + LF2*cos(tk2+th2+tb+pi);
xF3 = x + LH3*cos(2*pi-(tb)) + LK3*cos(2*pi-(th3+tb)) + LF3*cos(2*pi-(tk3+th3+tb)); yF3 = y + LH3*sin(2*pi-(tb)) + LK3*sin(2*pi-(th3+tb)) + LF3*sin(2*pi-(tk3+th3+tb));
xF4 = x + LH4*cos(tb+pi) + LK4*cos(th4+tb+pi) + LF4*cos(tk4+th4+tb+pi); yF4 = y + LH4*sin(tb+pi) + LK4*sin(th4+tb+pi) + LF4*cos(tk4+th4+tb+pi);


xH1dot = derivative(xH1, [x tb], [xdot;tbdot]);
yH1dot = derivative(yH1, [y tb], [ydot;tbdot]);
xH2dot = derivative(xH2, [x tb], [xdot;tbdot]);
yH2dot = derivative(yH2, [y tb], [ydot;tbdot]);
xH3dot = derivative(xH3, [x tb], [xdot;tbdot]);
yH3dot = derivative(yH3, [y tb], [ydot;tbdot]);
xH4dot = derivative(xH4, [x tb], [xdot;tbdot]);
yH4dot = derivative(yH4, [y tb], [ydot;tbdot]);

xT1dot = derivative(xT1, [x tb th1], [xdot;tbdot;th1dot]);
yT1dot = derivative(yT1, [y tb th1], [ydot;tbdot;th1dot]);
xT2dot = derivative(xT2, [x tb th2], [xdot;tbdot;th2dot]);
yT2dot = derivative(yT2, [y tb th2], [ydot;tbdot;th2dot]);
xT3dot = derivative(xT3, [x tb th3], [xdot;tbdot;th3dot]);
yT3dot = derivative(yT3, [y tb th3], [ydot;tbdot;th3dot]);
xT4dot = derivative(xT4, [x tb th4], [xdot;tbdot;th4dot]);
yT4dot = derivative(yT4, [y tb th4], [ydot;tbdot;th4dot]);

xK1dot = derivative(xK1, [x tb th1], [xdot;tbdot;th1dot]);
yK1dot = derivative(yK1, [y tb th1], [ydot;tbdot;th1dot]);
xK2dot = derivative(xK2, [x tb th2], [xdot;tbdot;th2dot]);
yK2dot = derivative(yK2, [y tb th2], [ydot;tbdot;th2dot]);
xK3dot = derivative(xK3, [x tb th3], [xdot;tbdot;th3dot]);
yK3dot = derivative(yK3, [y tb th3], [ydot;tbdot;th3dot]);
xK4dot = derivative(xK4, [x tb th4], [xdot;tbdot;th4dot]);
yK4dot = derivative(yK4, [y tb th4], [ydot;tbdot;th4dot]);

xS1dot = derivative(xS1, [x tb th1 tk1], [xdot;tbdot;th1dot;tk1dot]);
yS1dot = derivative(yS1, [y tb th1 tk1], [ydot;tbdot;th1dot;tk1dot]);
xS2dot = derivative(xS2, [x tb th2 tk2], [xdot;tbdot;th2dot;tk2dot]);
yS2dot = derivative(yS2, [y tb th2 tk2], [ydot;tbdot;th2dot;tk2dot]);
xS3dot = derivative(xS3, [x tb th3 tk3], [xdot;tbdot;th3dot;tk3dot]);
yS3dot = derivative(yS3, [y tb th3 tk3], [ydot;tbdot;th3dot;tk3dot]);
xS4dot = derivative(xS4, [x tb th4 tk4], [xdot;tbdot;th4dot;tk4dot]);
yS4dot = derivative(yS4, [y tb th4 tk4], [ydot;tbdot;th4dot;tk4dot]);

xF1dot = derivative(xF1, [x tb th1 tk1], [xdot;tbdot;th1dot;tk1dot]);
yF1dot = derivative(yF1, [y tb th1 tk1], [ydot;tbdot;th1dot;tk1dot]);
xF2dot = derivative(xF2, [x tb th2 tk2], [xdot;tbdot;th2dot;tk2dot]);
yF2dot = derivative(yF2, [y tb th2 tk2], [ydot;tbdot;th2dot;tk2dot]);
xF3dot = derivative(xF3, [x tb th3 tk3], [xdot;tbdot;th3dot;tk3dot]);
yF3dot = derivative(yF3, [y tb th3 tk3], [ydot;tbdot;th3dot;tk3dot]);
xF4dot = derivative(xF4, [x tb th4 tk4], [xdot;tbdot;th4dot;tk4dot]);
yF4dot = derivative(yF4, [y tb th4 tk4], [ydot;tbdot;th4dot;tk4dot]);

%calculating accelerations
%hip
xH1ddot = derivative(xH1dot,[x tb xdot tbdot], [xdot;tbdot;xddot;tbddot]); %Hip 1 X
yH1ddot = derivative(yH1dot,[y tb ydot tbdot], [ydot;tbdot;yddot;tbddot]); %Hip 1 Y
xH2ddot = derivative(xH2dot,[x tb xdot tbdot], [xdot;tbdot;xddot;tbddot]); %Hip 2 X
yH2ddot = derivative(yH2dot,[y tb ydot tbdot], [ydot;tbdot;yddot;tbddot]); %Hip 2 Y
xH3ddot = derivative(xH3dot,[x tb xdot tbdot], [xdot;tbdot;xddot;tbddot]); %Hip 3 X
yH3ddot = derivative(yH3dot,[y tb ydot tbdot], [ydot;tbdot;yddot;tbddot]); %Hip 3 Y
xH4ddot = derivative(xH4dot,[x tb xdot tbdot], [xdot;tbdot;xddot;tbddot]); %Hip 4 X
yH4ddot = derivative(yH4dot,[y tb ydot tbdot], [ydot;tbdot;yddot;tbddot]); %Hip 4 Y
%thigh
xT1ddot = derivative(xT1dot, [x tb th1 xdot tbdot th1dot], [xdot;tbdot;th1dot;xddot;tbddot;th1ddot]); %Thigh 1 X
yT1ddot = derivative(yT1dot, [y tb th1 ydot tbdot th1dot], [ydot;tbdot;th1dot;yddot;tbddot;th1ddot]); %Thigh 1 Y
xT2ddot = derivative(xT2dot, [x tb th2 xdot tbdot th2dot], [xdot;tbdot;th2dot;xddot;tbddot;th2ddot]); %Thigh 2 X
yT2ddot = derivative(yT2dot, [y tb th2 ydot tbdot th2dot], [ydot;tbdot;th2dot;yddot;tbddot;th2ddot]); %Thigh 2 Y
xT3ddot = derivative(xT3dot, [x tb th3 xdot tbdot th3dot], [xdot;tbdot;th3dot;xddot;tbddot;th3ddot]); %Thigh 3 X
yT3ddot = derivative(yT3dot, [y tb th3 ydot tbdot th3dot], [ydot;tbdot;th3dot;yddot;tbddot;th3ddot]); %Thigh 3 Y
xT4ddot = derivative(xT4dot, [x tb th4 xdot tbdot th4dot], [xdot;tbdot;th4dot;xddot;tbddot;th4ddot]); %Thigh 4 X
yT4ddot = derivative(yT4dot, [y tb th4 ydot tbdot th4dot], [ydot;tbdot;th4dot;yddot;tbddot;th4ddot]); %Thigh 4 Y
%knee
xK1ddot = derivative(xK1dot,[x tb th1 xdot tbdot th1dot], [xdot;tbdot;th1dot;xddot;tbddot;th1ddot]); %Knee 1 X
yK1ddot = derivative(yK1dot,[y tb th1 ydot tbdot th1dot], [ydot;tbdot;th1dot;yddot;tbddot;th1ddot]); %Knee 1 Y
xK2ddot = derivative(xK2dot,[x tb th2 xdot tbdot th2dot], [xdot;tbdot;th2dot;xddot;tbddot;th2ddot]); %Knee 2 X
yK2ddot = derivative(yK2dot,[y tb th2 ydot tbdot th2dot], [ydot;tbdot;th2dot;yddot;tbddot;th2ddot]); %Knee 2 Y
xK3ddot = derivative(xK3dot,[x tb th3 xdot tbdot th3dot], [xdot;tbdot;th3dot;xddot;tbddot;th3ddot]); %Knee 3 X
yK3ddot = derivative(yK3dot,[y tb th3 ydot tbdot th3dot], [ydot;tbdot;th3dot;yddot;tbddot;th3ddot]); %Knee 3 Y
xK4ddot = derivative(xK4dot,[x tb th4 xdot tbdot th4dot], [xdot;tbdot;th4dot;xddot;tbddot;th4ddot]); %Knee 4 X
yK4ddot = derivative(yK4dot,[y tb th4 ydot tbdot th4dot], [ydot;tbdot;th4dot;yddot;tbddot;th4ddot]); %Knee 4 Y
%shank
xS1ddot = derivative(xS1dot,[x tb th1 tk1 xdot tbdot th1dot tk1dot], [xdot;tbdot;th1dot;tk1dot;xddot;tbddot;th1ddot;tk1ddot]); %Shank 1 X
yS1ddot = derivative(yS1dot,[y tb th1 tk1 ydot tbdot th1dot tk1dot], [ydot;tbdot;th1dot;tk1dot;yddot;tbddot;th1ddot;tk1ddot]); %Shank 1 Y
xS2ddot = derivative(xS2dot,[x tb th2 tk2 xdot tbdot th2dot tk2dot], [xdot;tbdot;th2dot;tk2dot;xddot;tbddot;th2ddot;tk2ddot]); %Shank 2 X
yS2ddot = derivative(yS2dot,[y tb th2 tk2 ydot tbdot th2dot tk2dot], [ydot;tbdot;th2dot;tk2dot;yddot;tbddot;th2ddot;tk2ddot]); %Shank 2 Y
xS3ddot = derivative(xS3dot,[x tb th3 tk3 xdot tbdot th3dot tk3dot], [xdot;tbdot;th3dot;tk3dot;xddot;tbddot;th3ddot;tk3ddot]); %Shank 3 X
yS3ddot = derivative(yS3dot,[y tb th3 tk3 ydot tbdot th3dot tk3dot], [ydot;tbdot;th3dot;tk3dot;yddot;tbddot;th3ddot;tk3ddot]); %Shank 3 Y
xS4ddot = derivative(xS4dot,[x tb th4 tk4 xdot tbdot th4dot tk4dot], [xdot;tbdot;th4dot;tk4dot;xddot;tbddot;th4ddot;tk4ddot]); %Shank 4 X
yS4ddot = derivative(yS4dot,[y tb th4 tk4 ydot tbdot th4dot tk4dot], [ydot;tbdot;th4dot;tk4dot;yddot;tbddot;th4ddot;tk4ddot]); %Shank 4 Y
%foot
xF1ddot = derivative(xF1dot,[x tb th1 tk1 xdot tbdot th1dot tk1dot], [xdot;tbdot;th1dot;tk1dot;xddot;tbddot;th1ddot;tk1ddot]); %Foot 1 X
yF1ddot = derivative(yF1dot,[y tb th1 tk1 ydot tbdot th1dot tk1dot], [ydot;tbdot;th1dot;tk1dot;yddot;tbddot;th1ddot;tk1ddot]); %Foot 1 Y
xF2ddot = derivative(xF2dot,[x tb th2 tk2 xdot tbdot th2dot tk2dot], [xdot;tbdot;th2dot;tk2dot;xddot;tbddot;th2ddot;tk2ddot]); %Foot 2 X
yF2ddot = derivative(yF2dot,[y tb th2 tk2 ydot tbdot th2dot tk2dot], [ydot;tbdot;th2dot;tk2dot;yddot;tbddot;th2ddot;tk2ddot]); %Foot 2 Y
xF3ddot = derivative(xF3dot,[x tb th3 tk3 xdot tbdot th3dot tk3dot], [xdot;tbdot;th3dot;tk3dot;xddot;tbddot;th3ddot;tk3ddot]); %Foot 3 X
yF3ddot = derivative(yF3dot,[y tb th3 tk3 ydot tbdot th3dot tk3dot], [ydot;tbdot;th3dot;tk3dot;yddot;tbddot;th3ddot;tk3ddot]); %Foot 3 Y
xF4ddot = derivative(xF4dot,[x tb th4 tk4 xdot tbdot th4dot tk4dot], [xdot;tbdot;th4dot;tk4dot;xddot;tbddot;th4ddot;tk4ddot]); %Foot 4 X
yF4ddot = derivative(yF4dot,[y tb th4 tk4 ydot tbdot th4dot tk4dot], [ydot;tbdot;th4dot;tk4dot;yddot;tbddot;th4ddot;tk4ddot]); %Foot 4 Y

%Dynamic calculations
syms mB mT1 mT2 mT3 mT4 mS1 mS2 mS3 mS4 g; %mass and weight
%Moments of inertia
syms IS1x IS1y IS1z IT1x IT1y IT1z IBx IBy IBz IT2x IT2y IT2z IS2x IS2y IS2z; %Link moments of inertia
syms IS3x IS3y IS3z IT3x IT3y IT3z IT4x IT4y IT4z IS4x IS4y IS4z; %Link moments of inertia
%Forces
syms FH1x FH2x FH3x FH4x FK1x FK2x FK3x FK4x FF1x FF2x FF3x FF4x;
syms FH1y FH2y FH3y FH4y FK1y FK2y FK3y FK4y FF1y FF2y FF3y FF4y;
%torques
syms TH1 TH2 TH3 TH4 TK1 TK2 TK3 TK4;

%weight equations
T1w = [0 -mT1 * g 0]; S1w = [0 -mS1 * g 0]; %weights
T2w = [0 -mT2 * g 0]; S2w = [0 -mS2 * g 0]; %weights
T3w = [0 -mT3 * g 0]; S3w = [0 -mS3 * g 0]; %weights
T4w = [0 -mT4 * g 0]; S4w = [0 -mS4 * g 0]; %weights
%force vectors
FH1 = [FH1x FH1y 0]; FH2 = [FH2x FH2y 0]; FH3 = [FH3x FH3y 0]; FH4 = [FH4x FH4y 0];
FK1 = [FK1x FK1y 0]; FK2 = [FK2x FK2y 0]; FK3 = [FK3x FK3y 0]; FK4 = [FK4x FK4y 0];
FF1 = [FF1x FF1y 0]; FF2 = [FF2x FF2y 0]; FF3 = [FF3x FF3y 0]; FF4 = [FF4x FF4y 0];

%vector positions and accelerations for each point of interest
%front (1)
rH1 = [xH1 yH1 0];% rH1ddot = [xH1ddot yH1ddot 0]; %hip 1
rT1 = [xT1 yT1 0]; rT1ddot = [xT1ddot yT1ddot 0]; %thigh 1
rK1 = [xK1 yK1 0];% rK1ddot = [xK1ddot yK1ddot 0]; %knee 1
rS1 = [xS1 yS1 0]; rS1ddot = [xS1ddot yS1ddot 0]; %shank 1
rF1 = [xF1 yF1 0];% rF1ddot = [xF1ddot yF1ddot 0]; %foot 1
%front (3)
rH3 = [xH3 yH3 0];% rH3ddot = [xH3ddot yH3ddot 0]; %hip 3
rT3 = [xT3 yT3 0]; rT3ddot = [xT3ddot yT3ddot 0]; %thigh 3
rK3 = [xK3 yK3 0];% rK3ddot = [xK3ddot yK3ddot 0]; %knee 3
rS3 = [xS3 yS3 0]; rS3ddot = [xS3ddot yS3ddot 0]; %shank 3
rF3 = [xF3 yF3 0];% rF3ddot = [xF3ddot yF3ddot 0]; %foot 3
%body
rB = [x y 0]; rBddot = [xddot yddot 0]; %body
%rear (2)
rH2 = [xH2 yH2 0];% rH2ddot = [xH2ddot yH2ddot 0]; %hip 2
rT2 = [xT2 yT2 0]; rT2ddot = [xT2ddot yT2ddot 0]; %thigh 2
rK2 = [xK2 yK2 0];% rK2ddot = [xK2ddot yK2ddot 0]; %knee 2
rS2 = [xS2 yS2 0]; rS2ddot = [xS2ddot yS2ddot 0]; %shank 2
rF2 = [xF2 yF2 0];% rF2ddot = [xF2ddot yF2ddot 0]; %foot 2
%rear (4)
rH4 = [xH4 yH4 0];% rH4ddot = [xH4ddot yH4ddot 0]; %hip 4
rT4 = [xT4 yT4 0]; rT4ddot = [xT4ddot yT4ddot 0]; %thigh 4
rK4 = [xK4 yK4 0];% rK4ddot = [xK4ddot yK4ddot 0]; %knee 4
rS4 = [xS4 yS4 0]; rS4ddot = [xS4ddot yS4ddot 0]; %shank 4
rF4 = [xF4 yF4 0];% rF4ddot = [xF4ddot yF4ddot 0]; %foot 4

%force calculations
EffecMomentS1 = cross(rS1,mS1*rS1ddot)+ [IS1x*0 IS1y*0 IS1z*tk1ddot]; %shank 1
EffecMomentT1 = cross(rT1,mT1*rT1ddot)+ [IT1x*0 IT1y*0 IT1z*th1ddot]; %thigh 1
EffecMomentS3 = cross(rS3,mS3*rS3ddot)+ [IS3x*0 IS3y*0 IS3z*tk3ddot]; %shank 3
EffecMomentT3 = cross(rT3,mT3*rT3ddot)+ [IT3x*0 IT3y*0 IT3z*th3ddot]; %thigh 3
%EffecMomentB  = cross(rB,mB*rBddot)   + [IBx*0 IBy*0 IBz*tbddot];     %body
EffecMomentT2 = cross(rT2,mT2*rT2ddot)+ [IT2x*0 IT2y*0 IT2z*th2ddot]; %thigh 2
EffecMomentS2 = cross(rS2,mS2*rS2ddot)+ [IS2x*0 IS2y*0 IS2z*tk2ddot]; %shank 2
EffecMomentT4 = cross(rT4,mT4*rT4ddot)+ [IT4x*0 IT4y*0 IT4z*th4ddot]; %thigh 2
EffecMomentS4 = cross(rS4,mS4*rS4ddot)+ [IS4x*0 IS4y*0 IS4z*tk4ddot]; %shank 2

%creating the 1D Force Matrix {F}
F = [FK1y; FH1y; FK2y; FH2y; FK3y; FH3y; FK4y; FH4y; ...
     FK1x; FH1x; FK2x; FH2x; FK3x; FH3x; FK4x; FH4x];

%The "other crap" on the right half {B}
Kin = [mS1*yS1ddot+S1w(2)+FF1y; mT1*yT1ddot+T1w(2); mS2*yS2ddot+S2w(2)+FF2y; mT2*yT2ddot+T2w(2); ...
       mS3*yS3ddot+S3w(2)+FF3y; mT3*yT3ddot+T3w(2); mS4*yS4ddot+S4w(2)+FF4y; mT4*yT4ddot+T4w(2); ...
       mS1*xS1ddot+FF1x; mT1*xT1ddot; mS2*xS2ddot+FF2x; mT2*xT2ddot; ...
       mS3*xS3ddot+FF3x; mT3*xT3ddot; mS4*xS4ddot+FF4x; mT4*xT4ddot];
       
%The matrix relating internal forces to accelerations {A}
Mat =[-1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0;
       1 -1  0  0  0  0  0  0  0  0  0  0  0  0  0  0;
       0  0 -1  0  0  0  0  0  0  0  0  0  0  0  0  0;
       0  0  1 -1  0  0  0  0  0  0  0  0  0  0  0  0;
       0  0  0  0 -1  0  0  0  0  0  0  0  0  0  0  0;
       0  0  0  0  1 -1  0  0  0  0  0  0  0  0  0  0;
       0  0  0  0  0  0 -1  0  0  0  0  0  0  0  0  0;
       0  0  0  0  0  0  1 -1  0  0  0  0  0  0  0  0;
       0  0  0  0  0  0  0  0 -1  0  0  0  0  0  0  0;
       0  0  0  0  0  0  0  0  1 -1  0  0  0  0  0  0;
       0  0  0  0  0  0  0  0  0  0 -1  0  0  0  0  0;
       0  0  0  0  0  0  0  0  0  0  1 -1  0  0  0  0;
       0  0  0  0  0  0  0  0  0  0  0  0 -1  0  0  0;
       0  0  0  0  0  0  0  0  0  0  0  0  1 -1  0  0;
       0  0  0  0  0  0  0  0  0  0  0  0  0  0 -1  0;
       0  0  0  0  0  0  0  0  0  0  0  0  0  0  1 -1];
   
%solving {A}{F}={B} for {F}
FORCES = solve(F == inv(Mat)*Kin, FK1x, FK1y, FK2x, FK2y, FK3x, FK3y, FK4x, FK4y, ...
                             FH1x, FH1y, FH2x, FH2y, FH3x, FH3y, FH4x, FH4y);

%Torque array {T}
%These are negative because on the diagram the moments are assumed negative
T = [-TK1; -TH1; -TK2; -TH2; -TK3; -TH3; -TK4; -TH4];

%Matric {C} relating torques to movement
TMat = [1  0  0  0  0  0  0  0;
       -1  1  0  0  0  0  0  0;
        0  0  1  0  0  0  0  0;
        0  0 -1  1  0  0  0  0;
        0  0  0  0  1  0  0  0;
        0  0  0  0 -1  1  0  0;
        0  0  0  0  0  0  1  0;
        0  0  0  0  0  0 -1  1];

%The "other crap" from the sum of the torques, matrix {D}
TorqueT = [EffecMomentS1 - cross(rF1,  FF1) - cross(rK1, -FK1) - cross(rS1, S1w);  
           EffecMomentT1 - cross(rH1, -FH1) - cross(rK1,  FK1) - cross(rT1, T1w);
           EffecMomentS2 - cross(rF2,  FF2) - cross(rK2, -FK2) - cross(rS2, S2w);
           EffecMomentT2 - cross(rH2, -FH2) - cross(rK2,  FK2) - cross(rT2, T2w);
           EffecMomentS3 - cross(rF3,  FF3) - cross(rK3, -FK3) - cross(rS3, S3w);
           EffecMomentT3 - cross(rH3, -FH3) - cross(rK3,  FK3) - cross(rT3, T3w);
           EffecMomentS4 - cross(rF4,  FF4) - cross(rK4, -FK4) - cross(rS4, S4w);
           EffecMomentT4 - cross(rH4, -FH4) - cross(rK4,  FK4) - cross(rT4, T4w)];
    
%Grabbing the Z direction of {D}
TorqueT = TorqueT(:,3);

%Solving {C}{T}={D} for {T}
Ts = solve(TMat*T == TorqueT, TK1, TH1, TK2, TH2, TK3, TH3, TK4, TH4);

%Creating TH1F (Hip Torque 1) in the form shown by Dr Rodriguez by renaming and zeroing
%variables
TH1F = Ts.TH1;
TH1F = subs(TH1F, ydot, 0); TH1F = subs(TH1F, yddot, 0); TH1F = subs(TH1F, th1dot, 0);
TH1F = subs(TH1F, th1ddot, 0); TH1F = subs(TH1F, tk1dot, 0); TH1F = subs(TH1F, tk1ddot, 0);
TH1F = subs(TH1F, tbdot, 0); TH1F = subs(TH1F, tbddot, 0);
TH1F = subs(TH1F, xdot, 0); TH1F = subs(TH1F, xddot, 0); 
TH1F = subs(TH1F, LH1, 0); 
TH1F = subs(TH1F, tb, 0); 
TH1F = subs(TH1F, x, 0); 
TH1F = subs(TH1F, y, 0);
TH1F = subs(TH1F, LS1, LF1/2);
TH1F = subs(TH1F, LT1, LK1/2);
%Creating TK1F (Knee Torque 1) in the form shown by Dr Rodriguez by renaming and zeroing
%variables
TK1F = Ts.TK1;
TK1F = subs(TK1F, ydot, 0); TK1F = subs(TK1F, yddot, 0); TK1F = subs(TK1F, th1dot, 0);
TK1F = subs(TK1F, th1ddot, 0); TK1F = subs(TK1F, tk1dot, 0); TK1F = subs(TK1F, tk1ddot, 0);
TK1F = subs(TK1F, tbdot, 0); TK1F = subs(TK1F, tbddot, 0);
TK1F = subs(TK1F, xdot, 0); TK1F = subs(TK1F, xddot, 0);
TK1F = subs(TK1F, LH1, 0); 
TK1F = subs(TK1F, tb, 0); 
TK1F = subs(TK1F, x, 0); 
TK1F = subs(TK1F, y, 0);
%Creating TH2F (Hip Torque 2) in the form shown by Dr Rodriguez by renaming and zeroing
%variables
TH2F = Ts.TH2;
TH2F = subs(TH2F, ydot, 0); TH2F = subs(TH2F, yddot, 0); TH2F = subs(TH2F, th2dot, 0);
TH2F = subs(TH2F, th2ddot, 0); TH2F = subs(TH2F, tk2dot, 0); TH2F = subs(TH2F, tk2ddot, 0);
TH2F = subs(TH2F, tbdot, 0); TH2F = subs(TH2F, tbddot, 0);
TH2F = subs(TH2F, xdot, 0); TH2F = subs(TH2F, xddot, 0); 
TH2F = subs(TH2F, LH2, 0); 
TH2F = subs(TH2F, tb, 0); 
TH2F = subs(TH2F, x, 0); 
TH2F = subs(TH2F, y, 0);
%Creating TK1F (Knee Torque 1) in the form shown by Dr Rodriguez by renaming and zeroing
%variables
TK2F = Ts.TK2;
TK2F = subs(TK2F, ydot, 0); TK2F = subs(TK2F, yddot, 0); TK2F = subs(TK2F, th2dot, 0);
TK2F = subs(TK2F, th2ddot, 0); TK2F = subs(TK2F, tk2dot, 0); TK2F = subs(TK2F, tk2ddot, 0);
TK2F = subs(TK2F, tbdot, 0); TK2F = subs(TK2F, tbddot, 0);
TK2F = subs(TK2F, xdot, 0); TK2F = subs(TK2F, xddot, 0);
TK2F = subs(TK2F, LH2, 0); 
TK2F = subs(TK2F, tb, 0); 
TK2F = subs(TK2F, x, 0); 
TK2F = subs(TK2F, y, 0);
%Print form variables to console
TH1F
TK1F
TH2F
TK2F
%Assigning variables to workspace
assignin('base', 'TK1F', TK1F);
assignin('base', 'TH1F', TH1F);
%Assigning force matrices to workspace
assignin('base', 'Kin', Kin);
assignin('base', 'F', F);
assignin('base', 'Mat', Mat);
assignin('base', 'FORCES', FORCES);
%Assigning torque matrices to workspace
assignin('base', 'T', T);
assignin('base', 'TorqueT', TorqueT);
assignin('base', 'TMat', TMat);
assignin('base', 'Ts', Ts);

end

%inputs the function eqtn, row array of variables, column array of variable
%time derivatives
function dt = derivative(eqtn, variables, timeDerivs)
%calculates the row-major jacobian of the equation and multiplies it by the
%time derivative of each varial to find the equations derivative
dt = jacobian(eqtn,variables)*timeDerivs;
end