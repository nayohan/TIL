    %시계방향으로 돌때는 축소를 시키고
%반대 방향으로 돌때는 다시 원래 크기로 돌려라

x=[0 1 1 4 7 7 8 8 7 4 1 0 0;
   0 0 6 0 6 0 0 8 8 2 8 8 0;
   1 1 1 1 1 1 1 1 1 1 1 1 1];

figure(7)
for s=0:2:360
    
    th = s * pi / 180;
    
    h = ((360-s)/180)+1; %3~0

    E = [h 0 0; 0 h 0; 0 0 1];
    
    F_YAW= [cos(th) sin(th) 0; -sin(th) cos(th) 0; 0 0 1];   %YAW
    F_PITCH = [cos(th) 0 sin(th) ; 0 1 0; -sin(th) 0 cos(th)];  %Pitch
    F_ROLL = [1 0 0 ; 0  cos(th) -sin(th); 0 sin(th) cos(th)]; %ROLL
    
    r = F_YAW * F_PITCH * F_ROLL * x; %모든방향으로 회전
    clf; axis([-20 20 -20 20]);
    grid on
    line(r(1,:), r(2,:)); pause(0.00001);
end
    
for s=0:-2:-360
    th = s * pi / 180;
    
    h = (-s/180)+1; %0~3

    E = [h 0 0; 0 h 0; 0 0 1];
    
    F_YAW = [cos(th) sin(th) 0; -sin(th) cos(th) 0; 0 0 1];
    F_PITCH = [cos(th) 0 sin(th) ; 0 1 0; -sin(th) 0 cos(th)];
    F_ROLL = [1 0 0 ; 0  cos(th) -sin(th); 0 sin(th) cos(th)];
    r = F_YAW * F_PITCH * F_ROLL * x;
    clf; axis([-20 20 -20 20]);
    grid on
    line(r(1,:), r(2,:)); pause(0.00001);
end