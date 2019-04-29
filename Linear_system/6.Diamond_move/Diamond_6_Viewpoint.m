d = [ 0 5 5 0 -5 5 0 -5 -5 0 5 -5 0;
      0 -5 5 0 5 5 0 5 -5 0 -5 -5 0;
      20 0 0 20 0 0 -20 0 0 -20 0 0 20;
      1 1 1 1 1 1 1 1 1 1 1 1 1;]
p = [1 2 3; 4 5 6; 5 6 7; 8 9 10; 9 10 11; 11 12 13; 1 8 9; 2 3 7];
c = ['b'; 'r'; 'g'; 'w'; 'k'; 'c'; 'm'; 'y';];

x3=0; %Z축
r_Rev = 20; %반지름크기
noRot1 = 2; %공전수
noRot2 = 4; %자전
orbit = [0 0 20]
vpoint = [60,60,60];
vgain = 10000;

for deg = 0: 0.05 : 2*pi *noRot1
    clf;
    x1 = r_Rev * cos(deg) + randn(1)/4;
    x2 = r_Rev * sin(deg) + randn(1)/4;
    x3 = x3 - 0.1 + randn(1)/4;
    psi = 2 * noRot2 * deg;                                             % 2 * 2*pi
    Rz = [cos(psi) -sin(psi) 0 x1; sin(psi) cos(psi) 0 x2; 0 0 1 x3; 0 0 0 1];
    y_before = Rz * d;
    dist_vpoint = sqrt((y_before(1,1)-vpoint(1))^2 + (y_before(2,1)-vpoint(2))^2 + (y_before(3,1)-vpoint(3))^2);
    y = y_before./(dist_vpoint^2).*vgain;
    
    line(y(1,:),y(2,:),y(3,:));
    line([40 0 0], [0 0 0], [0 0 0], 'Color', 'r');
    line([0 0 0], [0 40 0], [0 0 0], 'Color', 'g');
    line([0 0 0], [0 0 0], [0 0 40], 'Color', 'k');
    
    orbit = [orbit; y(1,1) y(2,1) y(3,1)];
    line(orbit(:,1), orbit(:,2), orbit(:,3));
    

    for i= 1:1:8
        patch([y(1,p(i,1)) y(1,p(i,2)) y(1,p(i,3))], [y(2,p(i,1)) y(2,p(i,2)) y(2,p(i,3))],...
              [y(3,p(i,1)) y(3,p(i,2)) y(3,p(i,3))], c(i));
    end
    
    xlabel('X1-axis'); ylabel('X2-axis'); zlabel('X3-axis');
    axis([-60 60 -60 60 -60 60]);
    grid on;
    j = deg/(pi*3);
    k = 3*deg/(pi*2);
    view([60*j/2 60*k]);
   %0~90 0~360 
    pause(0.00001);    
end