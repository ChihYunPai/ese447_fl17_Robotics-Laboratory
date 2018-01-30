function Theta = calc_theta(X_collect, V_collect);
time = X_collect.time;
n = min(size(time,1), 10800);
X=zeros(n,4);
for i=1:n
    X(i,:)=X_collect.signals.values(:,:,i);
end
V = V_collect.signals.values;
g = 9.81;

h1 = @(q1dot)0.5*q1dot^2;
h2 = @(q1dot, q2, q2dot) 0.5*((q1dot^2)*(sin(q2)^2) + (q2dot^2));
h3 = @(q1dot, q2, q2dot) cos(q2)*q1dot*q2dot;
h4 = @(q2) g*cos(q2);
H_bar = zeros(n-1, 4);
F_bar = zeros(n-1, 2);


% q1 = X(1,1);
q1dot = X(1,2);
q2 = X(1,3);
q2dot = X(1,4);

h1_0 = 0.5*q1dot^2;
h2_0 = 0.5*q1dot^2*(sin(q2)^2) + 0.5*(q2dot^2);
h3_0 = cos(q2)*q1dot*q2dot;
h4_0 = g*cos(q2);

d = zeros(n-1,1);
% A = zeros(n-1,6);

for i = 1:(n-1)
%     q1 = X(i+1,1);
    q1dot = X(i+1,2);
    q2 = X(i+1,3);
    q2dot = X(i+1,4);
    H_bar(i,:) = [h1(q1dot)-h1_0, h2(q1dot, q2, q2dot)-h2_0, h3(q1dot, q2, q2dot)-h3_0, h4(q2)-h4_0];
    F_bar(i,:) = trapz(time(1:i+1), [X(1:i+1, 2).^2, X(1:i+1, 4).^2]);
    d(i,1) = trapz(time(1:i+1), V(1:i+1,1).*X(1:i+1, 2));
end
A = [H_bar, F_bar]; % A: size of (n-1)x6
Theta = A\d;

end