function [] = TRANS1_2(theta2)
L1 = 6;
L2 = 2;
P0_Org=[0;0;0;1];
% P1_Org=[0;0;-1;1];
% P2_Org=[0;6;-1;1];
% P3_Org=[0;6;0;1];
% P4_Org=[0;8;0;1];
P5_Org=[0;12;0;1];

theta2 = theta2 * pi / 180;
N=100;
theta = 0:theta2/N:theta2;

for i = 1:N+1
    T12 = [cos(theta(i)),-sin(theta(i)),0,0;0,0,-1,(L1+L2);sin(theta(i)),cos(theta(i)),0,0;0,0,0,1];
    P5 = T12 * P5_Org;
    
    plot3([P0_Org(1),P5(1)], [P0_Org(2),P5(2)], [P0_Org(3),P5(3)]);
    title('Task-5: Rotation about the Z-axis of FRAME-2'); grid on;xlim([-10 10]);ylim([-10 10]);zlim([-10 10]);xlabel('x');ylabel('y');zlabel('z');
    drawnow
end

