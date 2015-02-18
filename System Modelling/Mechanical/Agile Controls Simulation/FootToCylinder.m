%A function that takes in the foot position and returns the length of
%cylinder 1 and cylinder 2
%Inputs
%L1 - Link 1, L2 - Link 2
%D1 - Distance along Link 1 where Link 2 is attached
%D2 - Distance along Link 2 where Link 1 is attahced
%P1x, P1y - ground position of cylinder 1
%P11 - Distance along L1 where cylidner 1 is attached
%P21 - postion of Cylinder 2 on link 1, P22 - Position of Cylinder 2 on link 2
%x, y - Foot Position
function lengths = FootToCylinder(D1, D2, P1x, P1y, P11, P21, P22, x, y)
%Calculate inverse kinematics
Theta = InverseKinematics(D1, D2, x, y);
%Length of Cylinder 1
deltaX = -P1x + P11*cosd(90-Theta(1));
deltaY = -P1y + P11*sind(90-Theta(1));
PL1 = Distance(deltaX, deltaY, 0, 0);
%Length of Cylinder 2
Ax = P21*cosd(Theta(1)); %x coordinate of P21
Ay = P21*sind(Theta(1)); %y coordinate of P21
Bx = D1*cosd(Theta(1)) + P22*cosd(Theta(1) + Theta(2));
By = D1*sind(Theta(1)) + P22*sind(Theta(1) + Theta(2));
PL2 = Distance(Ax, Ay, Bx, By);
%Store Lengths in an array
lengths = [PL1 PL2];
end

