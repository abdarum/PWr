% k = 0.0342;
% T = 1;
% Ti = 0.6456;
% Td = 0.0794;


k = 5.2502;
T = 1;
Ti = 0.3684;
Td = 0.0921;

% K= 1.2T/(kTo) =  5.2502
% Ti=2To = 0.3684
% Td=0.5To = 0.0921

obiekt = poly([-4+i,-4-i,-5]);
K_o=tf([1], obiekt);

blok_P = [0, k, 0, 0, 1]; 
K_blok_P=tf(blok_P(1:2), blok_P(3:5));
K_r=K_blok_P;
if Ti ~= 0
    blok_I = [0, 1, 0, Ti, 0]; 
    K_blok_I=tf(blok_I(1:2), blok_I(3:5));
    K_r = parallel(K_r, K_blok_I);
end

if Td ~= 0
    blok_D = [0, Td, 0, 0.001, 0];
    K_blok_D=tf(blok_D(1:2), blok_D(3:5));
    K_r = parallel(K_r, K_blok_D);
end
    



K_feedback = series(K_r, K_o);
K = feedback(1, K_feedback);


%t = 0:0.01:T_final
[E, t] = step(K);

figure(1)
plot(t,E)


[Obj, t_ob] = step(K_o);

figure(2)
plot(t_ob,Obj)


% delta y = 2.349
% delta To = 0.1842
% delta T = 0.9901-0.1842=0.8059

% k=1
% K= 1.2T/(kTo) =  2.235
% Ti=2To = 0.3684
% Td=0.5To = 0.0921