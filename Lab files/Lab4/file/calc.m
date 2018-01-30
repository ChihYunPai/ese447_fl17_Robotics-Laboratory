function [Xdot]=calc(v, X)

% J1=0.0012;
% m2=0.127;
% l1_l2=0.2;
% l2=0.3;
% lc2=0.15;
% beta1=0.015;
% beta2=0.002;
% Ra=2.6;
% kt=0.00768;
% kv=0.00768;
% kr=70;
% 
% theta1=(J1+m2*l1_l2^2)*Ra/(kr*kt);
% theta2=(m2*l2^2/3)*Ra/(kr*kt);
% theta3=(m2*l1_l2*l2/2)*Ra/(kr*kt);

% theta4=(m2*lc2)*Ra/(kr*kt);
% theta5=beta1*Ra/(kr*kt) + kr*kv;
% theta6=beta2*Ra/(kr*kt);

q1=X(1);
q1dot=X(2);
q2=X(3);
q2dot=X(4);

theta1=0.030372023809524;
theta2=0.018426339285714;
theta3=0.018426339285714;
theta4=0.092131696428571;
theta5=0.610144642857143;
theta6=0.009672619047619;

m11=theta1+theta2*sin(q2)^2;
m12=theta3*cos(q2);
m21=theta3*cos(q2);
m22=theta2;
c11=2*theta2*sin(q2)*cos(q2)+theta5;
c12=-theta3*sin(q2)*q2dot;
c21=-theta2*sin(q2)*cos(q2)*q1dot;
c22=theta6;
f1=0;
f2=0;
g=9.8;
g1=0;
g2=-theta4*g*sin(q2);

V=[v;0];
M=[m11,m12;m21,m22];
C=[c11,c12;c21,c22];
F=[f1;f2];
G=[g1;g2];
qdot=[q1dot;q2dot];

qdotdot=M\(V-C*qdot-F-G);
Xdot=[q1dot,qdotdot(1),q2dot,qdotdot(2)];
end