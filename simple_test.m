D=importdata('s1.txt');
p = randperm(size(D,1));
D=D(p,:);
B=stkmpp(D', 100);
figure
plot(B(:,1),B(:,2),'k.')
pause (1)
figure
plot(D(:,1),D(:,2),'k.')
hold on

[C, A] = streamkm(D, 15, 500);
plot(C(:,1),C(:,2),'ro')
