function []=WorkSpace();
theta1 = 360;
theta2 = 360;

L1 = 6;
L2 = 2;
P5_Org=[0;12;0;1];

theta1 = theta1 * pi / 180;
theta2 = theta2 * pi / 180;
N=100;
theta1_ = 0:theta1/N:theta1;
theta2_ = 0:theta2/N:theta2;

%% using robot animation to plot
for i = 1:N+1
    T01 = [cos(theta1_(i)),-sin(theta1_(i)),0,0;sin(theta1_(i)),cos(theta1_(i)),0,0;0,0,1,0;0,0,0,1];
    for j = 1:N+1
        T12 = [cos(theta2_(j)),-sin(theta2_(j)),0,0;0,0,-1,(L1+L2);sin(theta2_(j)),cos(theta2_(j)),0,0;0,0,0,1];
        P5 = T01 * T12 * P5_Org;

        plot3([P5(1)], [P5(2)], [P5(3)],'o');
        title('Task-6: Robot work space plot'); grid on;xlim([-10 10]);ylim([-10 10]);zlim([-10 10]);xlabel('x');ylabel('y');zlabel('z');
        hold on
    end
end