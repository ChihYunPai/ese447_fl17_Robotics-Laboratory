function [] = TRANS0_1(theta1)
P0_Org=[0;0;0;1];
P1_Org=[0;0;-1;1];
P2_Org=[0;6;-1;1];
P3_Org=[0;6;0;1];
P4_Org=[0;8;0;1];
P5_Org=[0;12;0;1];
theta1 = theta1 * pi / 180;
N=100;
theta = 0:theta1/N:theta1;

for i = 1:N+1
    T01 = [cos(theta(i)),-sin(theta(i)),0,0;sin(theta(i)),cos(theta(i)),0,0;0,0,1,0;0,0,0,1];
    P1 = T01 * P1_Org;
    P2 = T01 * P2_Org;
    P3 = T01 * P3_Org;
    P4 = T01 * P4_Org;
    
    plot3([P0_Org(1),P1(1),P2(1),P3(1),P4(1)], [P0_Org(2),P1(2),P2(2),P3(2),P4(2)], [P0_Org(3),P1(3),P2(3),P3(3),P4(3)]);
    title('Task-3: Rotation about Z-axis of FRAME-1'); grid on;xlim([-10 10]);ylim([-10 10]);zlim([-10 10]);xlabel('x');ylabel('y');zlabel('z');
    drawnow
end

