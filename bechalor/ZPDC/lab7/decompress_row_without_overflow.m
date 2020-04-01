function [ Y ] = decompress_row_without_overflow( X )
%DECOMP_FORMAT2_TO_OUT Summary of this function goes here
%   Detailed explanation goes here

    Y = [];
    counting_val = 0;
    for i = 1:length(X)
        if (counting_val == 0)
            tmp = zeros(X(i)); tmp = tmp(1,:);
            Y = [Y, tmp];
            counting_val = 1;
        else
            tmp = ones(X(i)); tmp = tmp(1,:);
            Y = [Y, tmp];
            counting_val = 0;
        end 
    end
end

