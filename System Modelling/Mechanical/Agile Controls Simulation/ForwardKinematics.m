%Calculates the forward kinematics of a variable configuration 2R
%robotic arm
%Logan Beaver 11/28/14
%D1 = Distance along link 1 of joint 1 from the base
%D2 = Distance along link 2 of joint 1 from the foot
%T1 = Theta 1; T2 = Theta 2
function footPos = ForwardKinematics(D1,D2,T1,T2)
x = D1*cosd(T1) + D2*cosd(T1+T2);
y = D1*sind(T1) + D2*sind(T1+T2);
footPos = [x, y];
end

