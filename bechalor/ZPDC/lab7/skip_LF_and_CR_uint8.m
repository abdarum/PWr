function [ counter ] = skip_LF_and_CR_uint8( counter )
%SKIP_LF_AND_CR_UINT8 Summary of this function goes here
%   Detailed explanation goes here
    if (counter >= 12) % CR sign
        counter = counter + 2;
    elseif (counter >= 10) % LF sign
        counter = counter + 1;
    end
end

