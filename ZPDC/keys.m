function [ y ] = keys( x )
%KEYS Summary of this function goes here
%   Detailed explanation goes here

abs_x = abs(x)
abs_x2 = abs_x.^2
abs_x3 = abs_x.^3

if (le(0, abs_x) & le(abs_x,1))
    y = 3/2*abs_x3 - 5/2*abs_x2 + 1;
elseif (le(1,abs_x) & le(abs_x,2))
    y = -1/2*abs_x3 + 5/2*abs_x2 - 4*abs_x + 2;
else
    y = 0;
end

end

