%Kornel Stefañczyk
%nr 235420

% Y = [];
% for k=0:1:30
%    Y = [Y kryteriumQ(k)]; 
% end
% 
% figure(1)
% plot(Y)
% %fminsearch(@kryteriumQ, 0)

% 
% k = 0.0342;
% T = 1;
% Ti = 0.6456;
% Td = 0.0794;

k = 5.2502;
T = 3;
Ti = 0.3684;
Td = 0.0921;

%[x, val] = fminsearch(@(v) kryteriumQ([v(1), T, Ti, Td]), k);
[x, val] = fminsearch(@(v) kryteriumQ([v(1), T, v(2), v(3)]), [k,Ti,Td]);
%[x_P, val_P] = fminsearch(@(v) kryteriumQ([v(1), T, 1, 1]), 1)
%[x_I, val_I] = fminsearch(@(v) kryteriumQ([-0.7, T, v(1), 1]), 1)

figure(1)
[x_I, val] = fminsearch(@(v) kryteriumQ([k, T, v(1), Td]), Ti);
Y_I = [];
for i_I=0:0.01:1
   Y_I = [Y_I kryteriumQ([k, T, i_I, Td])]; 
end
plot(Y_I)

figure(2)
[x_P, val] = fminsearch(@(v) kryteriumQ([v(1), T, Ti, Td]), k);
Y_P = [];
for i_P=0:1:30
   Y_P = [Y_P kryteriumQ([i_P, 10, Ti, Td])]; 
end
plot(Y_P)


figure(3)
[x_D, val] = fminsearch(@(v) kryteriumQ([k, T, Ti, v(1)]), Td);
Y_D = [];
for i_D=0:0.01:1
   Y_D = [Y_D kryteriumQ([k, T, Ti, i_D])]; 
end
plot(Y_D)


%zbadaæ jak parametry systemu [ 0, 1, a, b, 1] a, b wp³ywaj¹ na system

%Rozszerzyæ do PI lub PD
%zbadaæ jak siê zmienia przbieg q jak zmienie kryterium
