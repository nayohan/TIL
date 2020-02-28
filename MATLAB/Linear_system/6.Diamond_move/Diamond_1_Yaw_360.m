d = [ 0 5 5 0 -5 5 0 -5 -5 0 5 -5 0;
      0 -5 5 0 5 5 0 5 -5 0 -5 -5 0;
      20 0 0 20 0 0 -20 0 0 -20 0 0 20;
      1 1 1 1 1 1 1 1 1 1 1 1 1;]
p = [1 2 3; 4 5 6; 5 6 7; 8 9 10; 9 10 11; 11 12 13; 1 8 9; 2 3 7];
c = ['b'; 'r'; 'g'; 'w'; 'k'; 'c'; 'm'; 'y';];
%blue red gree white black cyan magenta yellow

for psi = 0:0.04:2*pi
    clf;
    Rz = [cos(psi) -sin(psi) 0 0; sin(psi) cos(psi) 0 0; 0 0 1 0 ; 0 0 0 1];
    y = Rz * d;
    line(y(1,:),y(2,:),y(3,:));
    
    for i= 1:1:8
        patch([y(1,p(i,1)) y(1,p(i,2)) y(1,p(i,3))], [y(2,p(i,1)) y(2,p(i,2)) y(2,p(i,3))],...
              [y(3,p(i,1)) y(3,p(i,2)) y(3,p(i,3))], c(i));
    end
    
    axis([-20 20 -20 20 -20 20]);
    grid on;
    view([60 60]);
    pause(0.0001);
end