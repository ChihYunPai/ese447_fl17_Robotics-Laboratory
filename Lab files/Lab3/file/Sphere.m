function []=Sphere();
% [x,y,z] = sphere
% r = sqrt(12^2 + 8^2);
% x = x(1:end,:);
% y = y(1:end,:);
% z = z(1:end,:);
% surf(r.*x, r.*y, r.*z);
% axis equal


r1 = 8;
r2 = 12;
r = sqrt(r1^2+r2^2);
phi = atan(r1/r2);
phi_ = atan(r2/r1);

theta1 = linspace(phi, phi + phi_*2, 100);
theta2 = linspace(0, 2*pi, 100);
[theta1,theta2] = meshgrid(theta1,theta2);

%% Spherical coordinate:
x=r.*sin(theta1).*cos(theta2);
y=r.*sin(theta1).*sin(theta2);
z=r.*cos(theta1);
mesh(x,y,z);
hold on
grid on;xlim([-10 10]);ylim([-10 10]);zlim([-10 10]);xlabel('x');ylabel('y');zlabel('z');
% title('Task-6: Robot work space plot - compare'); 
grid on;xlim([-10 10]);ylim([-10 10]);zlim([-10 10]);xlabel('x');ylabel('y');zlabel('z');
end