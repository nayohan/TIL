x=[0 1 1 4 7 7 8 8 7 4 1 0 0;
   0 0 6 0 6 0 0 8 8 2 8 8 0;
   1 1 1 1 1 1 1 1 1 1 1 1 1];
line(x(1,:),x(2,:))
axis([0 14 0 11])

figure(1);
A = [1 0 0 ; 0 -1 0; 0 0 1]; %x축 대칭
y = A*x;
line (x(1,:), x(2,:))
line (y(1,:), y(2,:))
axis([-10 10 -10 10]); grid on; 
pause(1)

figure(2);
A = [-1 0 0; 0 1 0; 0 0 1]; %y축 대칭
y = A*x;
line (x(1,:), x(2,:))
line (y(1,:), y(2,:))
axis([-10 10 -10 10]); grid on;
pause(1)

figure(3);
A = [-1 0 0; 0 -1 0; 0 0 1]; %원점 대칭
y = A*x;
line (x(1,:), x(2,:))
line (y(1,:), y(2,:))
axis([-10 10 -10 10]); grid on;
pause(1)

figure(4);
A = [1 2 0; 0 1 0; 0 0 1]; %기울임체로 그리기
y = A*x;
line (x(1,:), x(2,:))
line (y(1,:), y(2,:))
axis([-10 10 -10 10]); grid on;
pause(1)

figure(5);
A = [1 0 2; 0 1 3; 0 0 1]; %이동하여 그리기
y = A*x;
line (x(1,:), x(2,:))
line (y(1,:), y(2,:))
axis([-10 10 -10 10]); grid on;
pause(1)

figure(6);
A = [1 0.5 0; 0 1 0; 0 0 1]; %이동 + 기울임체
B = [1 0 2; 0 1 3; 0 0 1];
y = B*A*x;
line (x(1,:), x(2,:))
line (y(1,:), y(2,:))
axis([-10 10 -10 10]); grid on;
pause(1)

figure(7);
k1 = 0.3; k2 =1.3;
C= [k1 0 0; 0 k1 0; 0 0 1]; %확대 축소
D= [k2 0 0; 0 k2 0; 0 0 1];
v = C*x;
figure(4); clf;
line(v(1,:), v(2,:));
hold on;
axis([0 14 0 11]);
u = D*x;
line(u(1,:), u(2,:));
axis([0 14 0 11]); grid on;
pause(1)

figure(8);
for h= 0.1: 0.02:3
    E = [h 0 0; 0 h 0; 0 0 1]; % 확대 <-> 축소
    t = E * x;
    clf;
    axis([0 30 0 30]);
    line(t(1,:), t(2,:));
    hold on; grid on;
    pause(0.0001)
end
for h= 3:-0.02:0.1
    E = [h 0 0; 0 h 0; 0 0 1];
    t = E * x;
    clf;
    axis([0 30 0 30]);
    line(t(1,:), t(2,:));
    hold on; grid on;
   pause(0.0001)
end

figure(9)
for s=0:2:360   % 회전
    th = s * pi / 180;
    F = [cos(th) sin(th) 0; -sin(th) cos(th) 0; 0 0 1];
    r = F * x;
    clf; axis([-20 20 -20 20]);
    line(r(1,:), r(2,:)); 
    hold on; grid on; pause(0.00001);
end  
for s=0:-2:-360
    th = s * pi / 180;
    F = [cos(th) sin(th) 0; -sin(th) cos(th) 0; 0 0 1];
    r = F * x;
    clf; axis([-20 20 -20 20]);
    line(r(1,:), r(2,:)); 
    hold on; grid on; pause(0.00001);
end

figure(10)
for s=0:2:360  %회전하면서 확대 축소
    th = s * pi / 180;
    
    h = ((360-s)/180)+1; %3~0

    E = [h 0 0; 0 h 0; 0 0 1];
    
    F = [cos(th) sin(th) 0; -sin(th) cos(th) 0; 0 0 1];
    r = F * E * x;
    clf; axis([-20 20 -20 20]);
    line(r(1,:), r(2,:)); 
    hold on; grid on; pause(0.00001);
end
for s=0:-2:-360
    th = s * pi / 180;
    
    h = (-s/180)+1; %0~3

    E = [h 0 0; 0 h 0; 0 0 1];
    
    F = [cos(th) sin(th) 0; -sin(th) cos(th) 0; 0 0 1];
    r = F * E * x;
    clf; axis([-20 20 -20 20]);
    line(r(1,:), r(2,:)); 
    hold on; grid on; pause(0.00001);
end