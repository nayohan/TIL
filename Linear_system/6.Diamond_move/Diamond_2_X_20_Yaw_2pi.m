d = [ 0 5 5 0 -5 5 0 -5 -5 0 5 -5 0;
      0 -5 5 0 5 5 0 5 -5 0 -5 -5 0;
      20 0 0 20 0 0 -20 0 0 -20 0 0 20;
      1 1 1 1 1 1 1 1 1 1 1 1 1;]
p = [1 2 3; 4 5 6; 5 6 7; 8 9 10; 9 10 11; 11 12 13; 1 8 9; 2 3 7];
c = ['b'; 'r'; 'g'; 'w'; 'k'; 'c'; 'm'; 'y';];

noRot1 = 2;
orbit = [0,0,20];
for x1 = 0:0.15:20
    clf;
    psi = noRot1 * 2 * pi * x1/20
    Rz_u = [cos(psi) -sin(psi) 0 x1; sin(psi) cos(psi) 0 0; 0 0 1 0 ; 0 0 0 1];
    y = Rz_u * d;
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
    
    xlabel('x1-axis'); ylabel('x2-axis'), zlabel('x3-axis');
    axis([-60 60 -60 60 -60 60]);
    grid on;
    view([60, 60, 60]);
    pause(0.0001);
end
grid on;