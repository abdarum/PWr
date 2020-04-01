%function [ Q ] = kryteriumQ( k )
function [ Q ] = kryteriumQ( argumenty )
%Kornel Stefañczyk
%nr 235420

%argumenty [k, T, Ti, Td]

% Your function g takes two inputs, x and y, however you supply fminsearch one input, the vector [1 1]. You need to rewrite it so that fminsearch only needs a single vector as input, but then that vector is split into two numbers to input into g.
% 
% fminsearch(@(v) g(v(1),v(2)),[1 1])
% 
% This makes an anonymous function that takes a vector as input (v) and then uses the first element (v(1)) as the first input to g, and the second element as the second input.

k = argumenty(1);
T = argumenty(2);
Ti = argumenty(3);
Td = argumenty(4);


obiekt = poly([-4+i,-4-i,-5]);
K_o=tf([1], obiekt);

blok_P = [0, k, 0, 0, 1]; 
K_blok_P=tf(blok_P(1:2), blok_P(3:5));
K_r=K_blok_P;
if Ti ~= 0
    blok_I = [0, 1, 0, Ti, 0]; 
    K_blok_I=tf(blok_I(1:2), blok_I(3:5));
    K_r = series(K_r, K_blok_I);
end

if Td ~= 0
    blok_D = [0, Td, 0, 0.001, 0];
    K_blok_D=tf(blok_D(1:2), blok_D(3:5));
    K_r = series(K_r, K_blok_D);
end
    



K_feedback = series(K_r, K_o);
K = feedback(1, K_feedback);


%t = 0:0.01:T_final
[E, t] = step(K, 10);


Q = sum(E.*E);
%Q = alfa*sum(E.*E)-(1-alfa)*;
end

