%pendulm wave and matlab simulation
%pendulm waves of real model and matlab

x=[0 1 1 4 7 7 8 8 7 4 1 0 0;
   0 0 6 0 6 0 0 8 8 2 8 8 0;
   1 1 1 1 1 1 1 1 1 1 1 1 1];

for h = 0: 0.2*pi: 80*pi 
    %범위의 경우 exp에 적절히 사용만한 -2pi에서 cos에사용하기위해 마지막은 0.5pi에서 마무리했다.
    %exp함수는 그래프상 inf 수렴하기 떄문에 폭을 1/50로 낮추고 -1/50exp()로 (0,1/50)부터 작아진다.
    %cos함수는 좌우로 40번씩 움직이게한다.
    
    k = exp(-1/50*h)*sin(h);
    E = [1 k 0; 0 1 0; 0 0 1 ;];
    
    y = E * x;

    clf;                    %전에 그려져있는 figuer를 지운다
    axis([-5 15 -5 15]);    %축의 크기를 지정
    grid on;                %격자 표시
    line(y(1,:), y(2,:));   %X,Y,Z를 가지고있는 y에서 추출
    
    pause(0.00000001);
end



