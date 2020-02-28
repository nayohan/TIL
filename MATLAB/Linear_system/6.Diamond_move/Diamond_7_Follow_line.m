d = [ 0 5 5 0 -5 5 0 -5 -5 0 5 -5 0;
      0 -5 5 0 5 5 0 5 -5 0 -5 -5 0;
      20 0 0 20 0 0 -20 0 0 -20 0 0 20;
      1 1 1 1 1 1 1 1 1 1 1 1 1;]
p = [1 2 3; 4 5 6; 5 6 7; 8 9 10; 9 10 11; 11 12 13; 1 8 9; 2 3 7];
c = ['b'; 'r'; 'g'; 'w'; 'k'; 'c'; 'm'; 'y';];

x3=0;
r_Rev = 20;
noRev = 2;
noRot1 = 2; %공전
noRot2 = 8; %자전
orbit = [0,0,20];

for deg = 0:2: noRev * 360
    clf;
    if(deg<180)
        x1 = deg/9; 
        psi = noRot1 * 2 * pi * x1/20;
        Rz_u = [cos(psi) -sin(psi) 0 -x1; sin(psi) cos(psi) 0 0; 0 0 1 0 ; 0 0 0 1];
        y = Rz_u * d;
        line(y(1,:),y(2,:),y(3,:));
        orbit = [orbit; y(1,1) y(2,1) y(3,1)];
        [m,n] = size(orbit);
        if(m<=30)
            line(orbit(:,1), orbit(:,2), orbit(:,3), 'LineWidth', 2,'Color',[0 0 1]);    
        else
            for index = 1:30
            line(orbit([m-index m-index+1],1), orbit([m-index m-index+1],2), orbit([m-index m-index+1],3), 'LineWidth',2,'Color',[index/30 index/30 1]);
            end
        end
        for i= 1:1:8
            patch([y(1,p(i,1)) y(1,p(i,2)) y(1,p(i,3))], [y(2,p(i,1)) y(2,p(i,2)) y(2,p(i,3))],...
                  [y(3,p(i,1)) y(3,p(i,2)) y(3,p(i,3))], c(i));
        end
        az = x1/20*90;
        view(az, 45);
        
    else
        x1 = r_Rev * cos(deg*pi/180);
        x2 = r_Rev * sin(deg*pi/180);
        x3 = x3-0.1;
        psi = deg * noRot2 * 2 * pi/180;
        Rz_round = [cos(psi) -sin(psi) 0 x1; sin(psi) cos(psi) 0 x2; 0 0 1 x3 ; 0 0 0 1];
        y = Rz_round * d;
        line(y(1,:),y(2,:),y(3,:));

        orbit = [orbit; y(1,1) y(2,1) y(3,1)];
        [m,n] = size(orbit);
        if(m<=30)
            line(orbit(:,1), orbit(:,2), orbit(:,3), 'LineWidth',2, 'Color',[0 0 1]);    
        else
            for index = 1:30
            line(orbit([m-index m-index+1],1), orbit([m-index m-index+1],2), orbit([m-index m-index+1],3), 'LineWidth',2,'Color',[index/30 index/30 1]);
            end
        end

        for i= 1:1:8
            patch([y(1,p(i,1)) y(1,p(i,2)) y(1,p(i,3))], [y(2,p(i,1)) y(2,p(i,2)) y(2,p(i,3))],...
                  [y(3,p(i,1)) y(3,p(i,2)) y(3,p(i,3))], c(i));
        end
        az = deg/2;
        el = sin(az/180*pi);
        view(az,45 + 30*el);
    end
    
    line([40 0 0], [0 0 0], [0 0 0], 'Color', 'r');
    line([0 0 0], [0 40 0], [0 0 0], 'Color', 'g');
    line([0 0 0], [0 0 0], [0 0 40], 'Color', 'k');
    
    xlabel('x1-axis'); ylabel('x2-axis'), zlabel('x3-axis');
    axis([-60 60 -60 60 -60 60]);
    grid on;
    pause(0.0001);
end