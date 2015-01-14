%accelerations and moments
%LIMB 1 -- Front Left
%Limb 2 -- Rear Left
%Limb 3 -- Front Right
%Limb 4 -- Rear Right
clear; clc;
syms x y LH1 LH2 LH3 LH4 LK1 LK2 LK3 LK4 LF1 LF2 LF3 LF4; %Pos/Length
syms tb th1 th2 th3 th4 tk1 tk2 tk3 tk4; %Angles
syms T1 T2 T3 T4 S1 S2 S3 S4; %CG Positions
syms xdot ydot tbdot th1dot tk1dot th2dot tk2dot th3dot tk3dot th4dot tk4dot; %angular/body velocities
syms xddot yddot tbddot th1ddot tk1ddot th2ddot tk2ddot th3ddot tk3ddot th4ddot tk4ddot; %angular/body accelerations
syms xH1dot xH2dot xH3dot xH4dot yH1dot yH2dot yH3dot yH4dot; %hip velocity
syms xH1ddot xH2ddot xH3ddot xH4ddot yH1ddot yH2ddot yH3ddot yH4ddot; %hip acceleration
syms xT1dot xT2dot xT3dot xT4dot yT1dot yT2dot yT3dot yT4dot; %thigh velocity
syms xT1ddot xT2ddot xT3ddot xT4ddot yT1ddot yT2ddot yT3ddot yT4ddot; %thigh acceleration
syms xK1dot xK2dot xK3dot xK4dot yK1dot yK2dot yK3dot yK4dot; %knee velocity
syms xK1ddot xK2ddot xK3ddot xK4ddot yK1ddot yK2ddot yK3ddot yK4ddot; %knee acceleration
syms xS1dot xS2dot xS3dot xS4dot yS1dot yS2dot yS3dot yS4dot; %shank velocity
syms xS1ddot xS2ddot xS3ddot xS4ddot yS1ddot yS2ddot yS3ddot yS4ddot; %shank acceleration
syms xF1dot xF2dot xF3dot xF4dot yF1dot yF2dot yF3dot yF4dot; %foot velocity
syms xF1ddot xF2ddot xF3ddot xF4ddot yF1ddot yF2ddot yF3ddot yF4ddot; %foot acceleration
%calculating positions (1 = front left)
xH1 = x + LH1*cos(tb); yH1 = y + LH1*sin(tb);
xT1 = xH1 + T1*cos(th1); yT1 = yH1 + T1*sin(th1);
xK1 = xH1 + LK1*cos(th1); yK1 = yH1 + LK1*sin(th1);
xS1 = xK1 + S1*cos(tk1); yS1 = yK1 + S1*sin(tk1);
xF1 = xK1 + LF1*cos(tk1); yF1 = yK1 + LF1*sin(tk1);
%calculating positions (2 = back left)
xH2 = x + LH2*cos(tb + pi); yH2 = y * LH2*sin(tb);
xT2 = xH2 + T2*cos(th2); yT2 = yH2 + T2*sin(th2);
xK2 = xH2 + LK2*cos(th2); yK2 = yH2 + LK2*sin(th2);
xS2 = xK2 + S2*cos(tk2); yS2 = xK2 + S2*sin(tk2);
xF2 = xK2 + LF2*cos(tk2); yF2 = xK2 + LF2*sin(tk2);
%calculating positions (3 = front right)
xH3 = x + LH3*cos(tb); yH3 = y + LH3*sin(tb);
xT3 = xH3 + T3*cos(th3); yT3 = yH3 + T3*sin(th3);
xK3 = xH3 + LK3*cos(th3); yK3 = yH3 + LK3*sin(th3);
xS3 = xK3 + S3*cos(tk3); yS3 = yK3 + S3*sin(tk3);
xF3 = xK3 + LF3*cos(tk3); yF3 = yK3 + LF3*sin(tk3);
%calculating positions (4 = back right)
xH4 = x + LH4*cos(tb + pi); yH4 = y * LH4*sin(tb);
xT4 = xH4 + T4*cos(th4); yT4 = yH4 + T4*sin(th4);
xK4 = xH4 + LK4*cos(th4); yK4 = yH4 + LK4*sin(th4);
xS4 = xK4 + S4*cos(tk4); yS4 = xK4 + S4*sin(tk4);
xF4 = xK4 + LF4*cos(tk4); yF4 = xK4 + LF4*sin(tk4);



%calculating velocities
%hip
xH1dot = jacobian(xH1,[x tb])*[xdot; tbdot]; %Hip 1 X
yH1dot = jacobian(yH1,[y tb])*[ydot; tbdot]; %Hip 1 Y
xH2dot = jacobian(xH2,[x tb])*[xdot; tbdot]; %Hip 2 X
yH2dot = jacobian(yH2,[y tb])*[ydot; tbdot]; %Hip 2 Y
xH3dot = jacobian(xH3,[x tb])*[xdot; tbdot]; %Hip 3 X
yH3dot = jacobian(yH3,[y tb])*[ydot; tbdot]; %Hip 3 Y
xH4dot = jacobian(xH4,[x tb])*[xdot; tbdot]; %Hip 4 X
yH4dot = jacobian(yH4,[y tb])*[ydot; tbdot]; %Hip 4 Y
%thigh
xT1dot = jacobian(xT1,[x tb th1])*[xdot;tbdot;th1dot]; %Thigh 1 X
yT1dot = jacobian(yT1,[y tb th1])*[ydot;tbdot;th1dot]; %Thigh 1 Y
xT2dot = jacobian(xT2,[x tb th2])*[xdot;tbdot;th2dot]; %Thigh 2 X
yT2dot = jacobian(yT2,[y tb th2])*[ydot;tbdot;th2dot]; %Thigh 2 Y
xT3dot = jacobian(xT3,[x tb th3])*[xdot;tbdot;th3dot]; %Thigh 3 X
yT3dot = jacobian(yT3,[y tb th3])*[ydot;tbdot;th3dot]; %Thigh 3 Y
xT4dot = jacobian(xT4,[x tb th4])*[xdot;tbdot;th4dot]; %Thigh 4 X
yT4dot = jacobian(yT4,[y tb th4])*[ydot;tbdot;th4dot]; %Thigh 4 Y
%knee
xK1dot = jacobian(xK1,[x tb th1])*[xdot;tbdot;th1dot]; %Knee 1 X
yK1dot = jacobian(yK1,[y tb th1])*[ydot;tbdot;th1dot]; %Knee 1 Y
xK2dot = jacobian(xK2,[x tb th2])*[xdot;tbdot;th2dot]; %Knee 2 X
yK2dot = jacobian(yK2,[y tb th2])*[ydot;tbdot;th2dot]; %Knee 2 Y
xK3dot = jacobian(xK3,[x tb th3])*[xdot;tbdot;th3dot]; %Knee 3 X
yK3dot = jacobian(yK3,[y tb th3])*[ydot;tbdot;th3dot]; %Knee 3 Y
xK4dot = jacobian(xK4,[x tb th4])*[xdot;tbdot;th4dot]; %Knee 4 X
yK4dot = jacobian(yK4,[y tb th4])*[ydot;tbdot;th4dot]; %Knee 4 Y
%shank
xS1dot = jacobian(xS1,[x tb th1 tk1])*[xdot;tbdot;th1dot;tk1dot]; %Shank 1 X
yS1dot = jacobian(yS1,[y tb th1 tk1])*[ydot;tbdot;th1dot;tk1dot]; %Shank 1 Y
xS2dot = jacobian(xS2,[x tb th2 tk2])*[xdot;tbdot;th2dot;tk2dot]; %Shank 2 X
yS2dot = jacobian(yS2,[y tb th2 tk2])*[ydot;tbdot;th2dot;tk2dot]; %Shank 2 Y
xS3dot = jacobian(xS3,[x tb th3 tk3])*[xdot;tbdot;th3dot;tk3dot]; %Shank 3 X
yS3dot = jacobian(yS3,[y tb th3 tk3])*[ydot;tbdot;th3dot;tk3dot]; %Shank 3 Y
xS4dot = jacobian(xS4,[x tb th4 tk4])*[xdot;tbdot;th4dot;tk4dot]; %Shank 4 X
yS4dot = jacobian(yS4,[y tb th4 tk4])*[ydot;tbdot;th4dot;tk4dot]; %Shank 4 Y
%foot
xF1dot = jacobian(xF1,[x tb th1 tk1])*[xdot;tbdot;th1dot;tk1dot]; %Foot 1 X
yF1dot = jacobian(yF1,[y tb th1 tk1])*[ydot;tbdot;th1dot;tk1dot]; %Foot 1 Y
xF2dot = jacobian(xF2,[x tb th2 tk2])*[xdot;tbdot;th2dot;tk2dot]; %Foot 2 X
yF2dot = jacobian(yF2,[y tb th2 tk2])*[ydot;tbdot;th2dot;tk2dot]; %Foot 2 Y
xF3dot = jacobian(xF3,[x tb th3 tk3])*[xdot;tbdot;th3dot;tk3dot]; %Foot 3 X
yF3dot = jacobian(yF3,[y tb th3 tk3])*[ydot;tbdot;th3dot;tk3dot]; %Foot 3 Y
xF4dot = jacobian(xF4,[x tb th4 tk4])*[xdot;tbdot;th4dot;tk4dot]; %Foot 4 X
yF4dot = jacobian(yF4,[y tb th4 tk4])*[ydot;tbdot;th4dot;tk4dot]; %Foot 4 Y

%calculating accelerations
%hip
xH1ddot = jacobian(xH1dot,[x;tb;xdot;tbdot])*[xdot;tbdot;xddot;tbddot]; %Hip 1 X
yH1ddot = jacobian(yH1dot,[y;tb;ydot;tbdot])*[ydot;tbdot;yddot;tbddot]; %Hip 1 Y
xH2ddot = jacobian(xH2dot,[x;tb;xdot;tbdot])*[xdot;tbdot;xddot;tbddot]; %Hip 2 X
yH2ddot = jacobian(yH2dot,[y;tb;ydot;tbdot])*[ydot;tbdot;yddot;tbddot]; %Hip 2 Y
xH3ddot = jacobian(xH3dot,[x;tb;xdot;tbdot])*[xdot;tbdot;xddot;tbddot]; %Hip 3 X
yH3ddot = jacobian(yH3dot,[y;tb;ydot;tbdot])*[ydot;tbdot;yddot;tbddot]; %Hip 3 Y
xH4ddot = jacobian(xH4dot,[x;tb;xdot;tbdot])*[xdot;tbdot;xddot;tbddot]; %Hip 4 X
yH4ddot = jacobian(yH4dot,[y;tb;ydot;tbdot])*[ydot;tbdot;yddot;tbddot]; %Hip 4 Y
%thigh
xT1ddot = jacobian(xT1dot,[x;tb;th1;xdot;tbdot;th1dot])*[xdot;tbdot;th1dot;xddot;tbddot;th1ddot]; %Thigh 1 X
yT1ddot = jacobian(yT1dot,[y;tb;th1;ydot;tbdot;th1dot])*[ydot;tbdot;th1dot;yddot;tbddot;th1ddot]; %Thigh 1 Y
xT2ddot = jacobian(xT2dot,[x;tb;th2;xdot;tbdot;th2dot])*[xdot;tbdot;th2dot;xddot;tbddot;th2ddot]; %Thigh 2 X
yT2ddot = jacobian(yT2dot,[y;tb;th2;ydot;tbdot;th2dot])*[ydot;tbdot;th2dot;yddot;tbddot;th2ddot]; %Thigh 2 Y
xT3ddot = jacobian(xT3dot,[x;tb;th3;xdot;tbdot;th3dot])*[xdot;tbdot;th3dot;xddot;tbddot;th3ddot]; %Thigh 3 X
yT3ddot = jacobian(yT3dot,[y;tb;th3;ydot;tbdot;th3dot])*[ydot;tbdot;th3dot;yddot;tbddot;th3ddot]; %Thigh 3 Y
xT4ddot = jacobian(xT4dot,[x;tb;th4;xdot;tbdot;th4dot])*[xdot;tbdot;th4dot;xddot;tbddot;th4ddot]; %Thigh 4 X
yT4ddot = jacobian(yT4dot,[y;tb;th4;ydot;tbdot;th4dot])*[ydot;tbdot;th4dot;yddot;tbddot;th4ddot]; %Thigh 4 Y
%knee
xK1ddot = jacobian(xK1dot,[x;tb;th1;xdot;tbdot;th1dot])*[xdot;tbdot;th1dot;xddot;tbddot;th1ddot]; %Knee 1 X
yK1ddot = jacobian(yK1dot,[y;tb;th1;ydot;tbdot;th1dot])*[ydot;tbdot;th1dot;yddot;tbddot;th1ddot]; %Knee 1 Y
xK2ddot = jacobian(xK2dot,[x;tb;th2;xdot;tbdot;th2dot])*[xdot;tbdot;th2dot;xddot;tbddot;th2ddot]; %Knee 2 X
yK2ddot = jacobian(yK2dot,[y;tb;th2;ydot;tbdot;th2dot])*[ydot;tbdot;th2dot;yddot;tbddot;th2ddot]; %Knee 2 Y
xK3ddot = jacobian(xK3dot,[x;tb;th3;xdot;tbdot;th3dot])*[xdot;tbdot;th3dot;xddot;tbddot;th3ddot]; %Knee 3 X
yK3ddot = jacobian(yK3dot,[y;tb;th3;ydot;tbdot;th3dot])*[ydot;tbdot;th3dot;yddot;tbddot;th3ddot]; %Knee 3 Y
xK4ddot = jacobian(xK4dot,[x;tb;th4;xdot;tbdot;th4dot])*[xdot;tbdot;th4dot;xddot;tbddot;th4ddot]; %Knee 4 X
yK4ddot = jacobian(yK4dot,[y;tb;th4;ydot;tbdot;th4dot])*[ydot;tbdot;th4dot;yddot;tbddot;th4ddot]; %Knee 4 Y
%shank
xS1ddot = jacobian(xS1dot,[x;tb;th1;xdot;tbdot;th1dot;tk1dot])*[xdot;tbdot;th1dot;xddot;tbddot;th1ddot;tk1ddot]; %Shank 1 X
yS1ddot = jacobian(yS1dot,[y;tb;th1;ydot;tbdot;th1dot;tk1dot])*[ydot;tbdot;th1dot;yddot;tbddot;th1ddot;tk1ddot]; %Shank 1 Y
xS2ddot = jacobian(xS2dot,[x;tb;th2;xdot;tbdot;th2dot;tk2dot])*[xdot;tbdot;th2dot;xddot;tbddot;th2ddot;tk2ddot]; %Shank 2 X
yS2ddot = jacobian(yS2dot,[y;tb;th2;ydot;tbdot;th2dot;tk2dot])*[ydot;tbdot;th2dot;yddot;tbddot;th2ddot;tk2ddot]; %Shank 2 Y
xS3ddot = jacobian(xS3dot,[x;tb;th3;xdot;tbdot;th3dot;tk3dot])*[xdot;tbdot;th3dot;xddot;tbddot;th3ddot;tk3ddot]; %Shank 3 X
yS3ddot = jacobian(yS3dot,[y;tb;th3;ydot;tbdot;th3dot;tk3dot])*[ydot;tbdot;th3dot;yddot;tbddot;th3ddot;tk3ddot]; %Shank 3 Y
xS4ddot = jacobian(xS4dot,[x;tb;th4;xdot;tbdot;th4dot;tk4dot])*[xdot;tbdot;th4dot;xddot;tbddot;th4ddot;tk4ddot]; %Shank 4 X
yS4ddot = jacobian(yS4dot,[y;tb;th4;ydot;tbdot;th4dot;tk4dot])*[ydot;tbdot;th4dot;yddot;tbddot;th4ddot;tk4ddot]; %Shank 4 Y
%foot
xF1ddot = jacobian(xF1dot,[x;tb;th1;xdot;tbdot;th1dot;tk1dot])*[xdot;tbdot;th1dot;xddot;tbddot;th1ddot;tk1ddot]; %Foot 1 X
yF1ddot = jacobian(yF1dot,[y;tb;th1;ydot;tbdot;th1dot;tk1dot])*[ydot;tbdot;th1dot;yddot;tbddot;th1ddot;tk1ddot]; %Foot 1 Y
xF2ddot = jacobian(xF2dot,[x;tb;th2;xdot;tbdot;th2dot;tk2dot])*[xdot;tbdot;th2dot;xddot;tbddot;th2ddot;tk2ddot]; %Foot 2 X
yF2ddot = jacobian(yF2dot,[y;tb;th2;ydot;tbdot;th2dot;tk2dot])*[ydot;tbdot;th2dot;yddot;tbddot;th2ddot;tk2ddot]; %Foot 2 Y
xF3ddot = jacobian(xF3dot,[x;tb;th3;xdot;tbdot;th3dot;tk3dot])*[xdot;tbdot;th3dot;xddot;tbddot;th3ddot;tk3ddot]; %Foot 3 X
yF3ddot = jacobian(yF3dot,[y;tb;th3;ydot;tbdot;th3dot;tk3dot])*[ydot;tbdot;th3dot;yddot;tbddot;th3ddot;tk3ddot]; %Foot 3 Y
xF4ddot = jacobian(xF4dot,[x;tb;th4;xdot;tbdot;th4dot;tk4dot])*[xdot;tbdot;th4dot;xddot;tbddot;th4ddot;tk4ddot]; %Foot 4 X
yF4ddot = jacobian(yF4dot,[y;tb;th4;ydot;tbdot;th4dot;tk4dot])*[ydot;tbdot;th4dot;yddot;tbddot;th4ddot;tk4ddot]; %Foot 4 Y

%Dynamic Calculations
syms mT1 mS1 mT3 mS3 mB mT2 mS2 mT4 mS4; %Link Masses
%Moments of inertia
syms IS1x IS1y IS1z IT1x IT1y IT1z IBx IBy IBz IT2x IT2y IT2z IS2x IS2y IS2z; %Link moments of inertia
syms IS3x IS3y IS3z IT3x IT3y IT3z IT4x IT4y IT4z IS4x IS4y IS4z; %Link moments of inertia

%vector positions and accelerations for each point of interest
%front (1)
rH1 = [xH1 yH1 0]; rH1ddot = [xH1ddot yH1ddot 0]; %hip 1
rT1 = [xT1 yT1 0]; rT1ddot = [xT1ddot yT1ddot 0]; %thigh 1
rK1 = [xK1 yK1 0]; rK1ddot = [xK1ddot yK1ddot 0]; %knee 1
rS1 = [xS1 yS1 0]; rS1ddot = [xS1ddot yS1ddot 0]; %shank 1
rF1 = [xF1 yF1 0]; rF1ddot = [xF1ddot yF1ddot 0]; %foot 1
%front (3)
rH3 = [xH3 yH3 0]; rH3ddot = [xH3ddot yH3ddot 0]; %hip 3
rT3 = [xT3 yT3 0]; rT3ddot = [xT3ddot yT3ddot 0]; %thigh 3
rK3 = [xK3 yK3 0]; rK3ddot = [xK3ddot yK3ddot 0]; %knee 3
rS3 = [xS3 yS3 0]; rS3ddot = [xS3ddot yS3ddot 0]; %shank 3
rF3 = [xF3 yF3 0]; rF3ddot = [xF3ddot yF3ddot 0]; %foot 3
%body
rB = [x y 0]; rBddot = [xddot yddot 0]; %body
%rear (2)
rH2 = [xH2 yH2 0]; rH2ddot = [xH2ddot yH2ddot 0]; %hip 2
rT2 = [xT2 yT2 0]; rT2ddot = [xT2ddot yT2ddot 0]; %thigh 2
rK2 = [xK2 yK2 0]; rK2ddot = [xK2ddot yK2ddot 0]; %knee 2
rS2 = [xS2 yS2 0]; rS2ddot = [xS2ddot yS2ddot 0]; %shank 2
rF2 = [xF2 yF2 0]; rF2ddot = [xF2ddot yF2ddot 0]; %foot 2
%rear (4)
rH4 = [xH4 yH4 0]; rH4ddot = [xH4ddot yH4ddot 0]; %hip 4
rT4 = [xT4 yT4 0]; rT4ddot = [xT4ddot yT4ddot 0]; %thigh 4
rK4 = [xK4 yK4 0]; rK4ddot = [xK4ddot yK4ddot 0]; %knee 4
rS4 = [xS4 yS4 0]; rS4ddot = [xS4ddot yS4ddot 0]; %shank 4
rF4 = [xF4 yF4 0]; rF4ddot = [xF4ddot yF4ddot 0]; %foot 4

%calculating effective moments
EffecMomentS1 = cross(rS1,mS1*rS1ddot)+ [IS1x*0 IS1y*0 IS1z*tk1ddot]; %shank 1
EffecMomentT1 = cross(rT1,mT1*rT1ddot)+ [IT1x*0 IT1y*0 IT1z*th1ddot]; %thigh 1
EffecMomentS3 = cross(rS3,mS3*rS3ddot)+ [IS3x*0 IS3y*0 IS3z*tk3ddot]; %shank 3
EffecMomentT3 = cross(rT3,mT3*rT3ddot)+ [IT3x*0 IT3y*0 IT3z*th3ddot]; %thigh 3
EffecMomentB = cross(rB,mB*rBddot) + [IBx*0 IBy*0 IBz*tbddot]; %body
EffecMomentT2 = cross(rT2,mT2*rT2ddot)+ [IT2x*0 IT2y*0 IT2z*th2ddot]; %thigh 2
EffecMomentS2 = cross(rS2,mS2*rS2ddot)+ [IS2x*0 IS2y*0 IS2z*tk2ddot]; %shank 2
EffecMomentT4 = cross(rT4,mT4*rT4ddot)+ [IT4x*0 IT4y*0 IT4z*th4ddot]; %thigh 2
EffecMomentS4 = cross(rS4,mS4*rS4ddot)+ [IS4x*0 IS4y*0 IS4z*tk4ddot]; %shank 2
%sum(moment) = EffecMomentT1 = cross(rH1, FH) + cross (RK1, FK) + cross(rT,
%w) + [0 0 hipTorque] + [0 0 kneeTorque]

%solve([TM F=MA], q)

%applied forces/torques
syms g; %gravitational acceleration
syms FH1x FH1y FK1x FK1y FF1y TH1 TK1; %1
syms FH2x FH2y FK2x FK2y FF2y TH2 TK2; %2
syms FH3x FH3y FK3x FK3y FF3y TH3 TK3; %2
syms FH4x FH4y FK4x FK4y FF4y TH4 TK4; %2
syms FF1x FF2x FF3x FF4x; %friction in the X


%weight equations
Bw = mB * g;
S1w = mS1 * g; T1w = mT1 * g; %weights
T2w = mT2 * g; S2w = mS2 * g; %weights
T3w = mT3 * g; S3w = mS3 * g; %weights
T4w = mT4 * g; S4w = mS4 * g; %weights
%Forces - joint forces and weights
FH1 = [FH1x, FH1y, 0]; %hip 1 (internal)
FK1 = [FK1x, FK1y, 0]; %knee 1 (internal)
FF1 = [FF1x, FF1y, 0]; %foot 1
T1w = [0, -T1w, 0]; %thigh 1 weight
S1w = [0, -S1w, 0]; %shank 1 weight
FH3 = [FH3x, FH3y, 0]; %hip 3 (internal)
FK3 = [FK3x, FK3y, 0]; %knee 3 (internal)
FF3 = [FF3x, FF3y, 0]; %foot 3
T3w = [0, -T3w, 0]; %thigh 3 weight
S3w = [0, -S3w, 0]; %shank 3 weight
Bw = [0, -Bw, 0]; %body weight
FH2 = [FH2x, FH2y, 0]; %hip 2 (internal)
FK2 = [FK2x, FK2y, 0]; %knee 2 (internal)
FF2 = [FF2x, FF2y, 0]; %foot 2
T2w = [0, -T2w, 0]; %thigh 2 weight
S2w = [0, -S2w, 0]; %shank 2 weight
FH4 = [FH4x, FH4y, 0]; %hip 4 (internal)
FK4 = [FK4x, FK4y, 0]; %knee 4 (internal)
FF4 = [FF4x, FF4y, 0]; %foot 4
T4w = [0, -T4w, 0]; %thigh 4 weight
S4w = [0, -S4w, 0]; %shank 4 weight

%Sum (E) of the Forces (F) in the Link (L) n (#) in Direction (d)
%Shank 1
EFS1x = -FK1x + FF1x; %x force sum = ma
EFS1y = S1w(2) + FF1y - FK1y; %y force sum = ma
ETS1 = TK1 + cross(rK1, -FK1) + cross(rS1, S1w) + cross(rF1, FF1); %sum of the torque = effectiveMoment
ETS1 = ETS1(3); %get z component
%Thigh 1
EFT1x = -FH1x + FK1x; %x force sum = ma
EFT1y = T1w(2) - FH1y + FK1y; %y force sum = ma
ETT1 = TH1 + TK1 + cross(rH1, -FH1) + cross(rT1, T1w) + cross(rK1, FK1); %sum of the torque = effectiveMoment
ETT1 = ETT1(3); %get z component
%Shank 3
EFS3x = -FK3x + FF3x; %x force sum = ma
EFS3y = S3w(2) + FF3y - FK3y; %y force sum = ma
ETS3 = TK3 + cross(rK3, -FK3) + cross(rS3, S3w) + cross(rF3, FF3); %sum of the torque = effectiveMoment
ETS3 = ETS3(3); %get z component
%Thigh 3
EFT3x = -FH3x + FK3x; %x force sum = ma
EFT3y = T3w(2) - FH3y + FK3y; %y force sum = ma
ETT3 = TH3 + TK3 + cross(rH3, -FH3) + cross(rT3, T3w) + cross(rK3, FK3); %sum of the torque = effectiveMoment
ETT3 = ETT3(3); %get z component
%Body
EFBx = FH1x + FH2x; %x force sum = ma
EFBy = Bw(2) + FH1y + FH2y; %y force sum = ma
ETB = TH1 + cross(rH1, FH1) + cross(rH2, FH2) + cross(rB, Bw); %sum of the torque = effectiveMoment
ETB = ETB(3); %get z component
%Thigh 2
EFT2x = -FH2x + FK2x; %x force sum = ma
EFT2y = T2w(2) - FH2y + FK2y; %y force sum = ma
ETT2 = TH2 + TK2 + cross(rH2, -FH2) + cross(rT2, T2w) + cross(rK2, FK2); %sum of the torque = effectiveMoment
ETT2 = ETT2(3); %get z component
%Shank 2
EFS2x = -FK2x + FF2x; %x force sum = ma
EFS2y = S2w(2) + FF2y - FK2y; %y force sum = ma
ETS2 = TK2 + cross(rK2, -FK2) + cross(rS2, S2w) + cross(rF2, FF2); %sum of the torque = effectiveMoment
ETS2 = ETS2(3); %get z component
%Thigh 4
EFT4x = -FH4x + FK4x; %x force sum = ma
EFT4y = T4w(2) - FH4y + FK4y; %y force sum = ma
ETT4 = TH4 + TK4 + cross(rH4, -FH4) + cross(rT4, T4w) + cross(rK4, FK4); %sum of the torque = effectiveMoment
ETT4 = ETT4(3); %get z component
%Shank 4
EFS4x = -FK4x + FF4x; %x force sum = ma
EFS4y = S4w(2) + FF4y - FK4y; %y force sum = ma
ETS4 = TK4 + cross(rK4, -FK4) + cross(rS4, S4w) + cross(rF4, FF4); %sum of the torque = effectiveMoment
ETS4 = ETS4(3); %get z component


%Build 9 1x3 arrays of each link for 27 equations - 2D robot with 2 legs
Shank1Funcs = [EFS1x == mS1*xS1ddot, EFS1y == mS1*yS1ddot, ETS1 == EffecMomentS1(3)];
Thigh1Funcs = [EFT1x == mT1*xT1ddot, EFT1y == mT1*yT1ddot, ETT1 == EffecMomentT1(3)];
Shank3Funcs = [EFS3x == mS3*xS3ddot, EFS3y == mS3*yS3ddot, ETS3 == EffecMomentS3(3)];
Thigh3Funcs = [EFT3x == mT3*xT3ddot, EFT3y == mT3*yT3ddot, ETT3 == EffecMomentT3(3)];
BodyFuncs = [EFBx == mB*xddot, EFBy == mB*yddot, ETB == EffecMomentB(3)];
Thigh2Funcs = [EFT2x == mT2*xT2ddot, EFT2y == mT2*yT2ddot, ETT2 == EffecMomentT2(3)];
Shank2Funcs = [EFS2x == mS1*xS2ddot, EFS2y == mS2*yS2ddot, ETS2 == EffecMomentS2(3)];
Thigh4Funcs = [EFT4x == mT4*xT4ddot, EFT4y == mT4*yT4ddot, ETT4 == EffecMomentT4(3)];
Shank4Funcs = [EFS4x == mS1*xS4ddot, EFS4y == mS4*yS4ddot, ETS4 == EffecMomentS4(3)];
reactions = [Shank1Funcs(1:2), Thigh1Funcs(1:2), Shank2Funcs(1:2), Thigh2Funcs(1:2), Shank3Funcs(1:2), Thigh3Funcs(1:2), ...
    Thigh4Funcs(1:2), Shank4Funcs(1:2)];

%Solve simultaneous equations
S = solve(reactions,FH1x, FH2x, FH3x, FH4x, FH1y, FH2y, FH3y, FH4y, FK1x, FK2x, FK3x, FK4x, FK1y, FK2y, FK3y, FK4y);
FH1x = S.FH1x; FH2x = S.FH2x; FH3x = S.FH3x; FH4x = S.FH4x;
FH1y = S.FH1y; FH2y = S.FH2y; FH3y = S.FH3y; FH4y = S.FH4y;

funcs = [Shank1Funcs(3), Thigh1Funcs(3), Shank2Funcs(3), Thigh2Funcs(3), Shank3Funcs(3), Thigh3Funcs(3), ...
    Thigh4Funcs(3), Shank4Funcs(3), BodyFuncs];
Torque = solve(funcs, TH1, TH2, TH3, TH4, TK1, TK2, TK3, TK4);
Q = solve(funcs, xddot, yddot, tbddot, th1ddot, th2ddot, th3ddot, th4ddot, tk1ddot, tk2ddot, tk3ddot, tk4ddot);