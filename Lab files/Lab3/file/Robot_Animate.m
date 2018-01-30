function []=Robot_Animate(theta1,theta2);
if(theta1==0)
    theta1 = 0.001;
end
if(theta2==0)
    theta2 = 0.001;
end

L1 = 6;
L2 = 2;
P0_Org=[0;0;0;1];
P1_Org=[0;0;-1;1];
P2_Org=[0;6;-1;1];
P3_Org=[0;6;0;1];
P4_Org=[0;8;0;1];
P5_Org=[0;12;0;1];

theta1 = theta1 * pi / 180;
theta2 = theta2 * pi / 180;
N=100;
theta1_ = 0:theta1/N:theta1;
theta2_ = 0:theta2/N:theta2;

for i = 1:N+1
    T01 = [cos(theta1_(i)),-sin(theta1_(i)),0,0;sin(theta1_(i)),cos(theta1_(i)),0,0;0,0,1,0;0,0,0,1];
    P1 = T01 * P1_Org;
    P2 = T01 * P2_Org;
    P3 = T01 * P3_Org;
    P4 = T01 * P4_Org;
    T12 = [cos(theta2_(i)),-sin(theta2_(i)),0,0;0,0,-1,(L1+L2);sin(theta2_(i)),cos(theta2_(i)),0,0;0,0,0,1];
    P5 = T01 * T12 * P5_Org;
    
    plot3([P0_Org(1),P1(1),P2(1),P3(1),P4(1),P5(1)], [P0_Org(2),P1(2),P2(2),P3(2),P4(2),P5(2)], [P0_Org(3),P1(3),P2(3),P3(3),P4(3),P5(3)],'-o');
    title('Task-6: Robot animation on both FRAME-1 and FRAME-2'); grid on;xlim([-10 10]);ylim([-10 10]);zlim([-10 10]);xlabel('x');ylabel('y');zlabel('z');
    drawnow
end


end