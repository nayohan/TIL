figure(2);
x = [zeros(1,100); (0.1:0.1:10); ones(1,100)];    %3x3행렬로 1행에 x 2행에 y 3행에 1을 담고잇음
y = x;    %출력할 행렬

 for i= 0 : 0.05*pi : 10*pi
    power = 1; %강도 0.1~1.57값 변경가능
    E = [1 exp(-1/10*i)*sin(i) 0; 0 -1 0; 0 0 1;];  
    Ecp = E;
    
    for m = 1:1:100 %각각의 원소에 접근해 sin(l(E(1,2))했다. sin90안쪽에서 사용해야한다.1.57이하의 값
        l = power * m/100;
        Ecp(1,2) = sin(l*E(1,2));
        Ecp(2,2) = -cos(l*E(1,2));
        y(:,m) = Ecp * x(:,m);
    end
        Ecp(1,2) = sin(l*E(1,2));
        %Ecp(2,2) = -cos(l*E(1,2));
    clf;
    axis([-5 5, -10 0])
    hold on;
    plot(y(1,:),y(2,:),'-'); 
    grid on; 
    pause(0.00001)
end