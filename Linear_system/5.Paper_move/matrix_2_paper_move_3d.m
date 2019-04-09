figure(2);
hold on;
 one = ones(100);
 x = [one(1,:); (0.1:0.1:10); one(1,:); one(1,:)];    %3x3행렬로 1행에 x 2행에 y 3행에 1을 담고잇음
 y = [one(1,:); (0.1:0.1:10); one(1,:); one(1,:)];    %출력할 행렬

 for i= 0 : 0.1*pi : 10*pi
    power = 1;
    E = [1 power*exp(-1/10*i)*sin(i) 0 0; 0 -1 0 0;0 0 1 0; 0 0 0 1];
    Ecp = [1 power*exp(-1/10*i)*sin(i) 0 0; 0 -1 0 0;0 0 1 0; 0 0 0 1];
    the = i;
    Ry = [1 0 0 0;0 0 cos(the) -sin(the);0 0 sin(the) cos(the);0 0 0 1];
   
    for m = 1:1:100 %각각의 원소에 접근해 sin(l(E(1,2))했다. 문제는 sin90안쪽에서 사용해야한다.1.57이하의 값
        l = m/100;
        le =l*E(1,2);
        Ecp(1,2) = sin(le);
        Ecp(2,2) = -cos(le);
        y(:,m) = Ecp * x(:,m);
    end

    y1 = E * x;
    clf;
    axis([-5 5, 0 10, -12 0])
    xlabel('x1 axis'); ylabel('x2 aixs'); zlabel('x3 axis');
    grid on; hold on;
    for z = 1:0.1:10
        plot3(y(1,:),y(3,:)+z,y(2,:),'Color','black');
    end
    view(-30, 10);
   % plot(y1(1,:),y1(2,:),'.');
    pause(0.00001)
end


