function [ Y ] = decompress_row( X )
%DECOMPRESS_ROW Summary of this function goes here
%   Detailed explanation goes here

    counting_val = 0;
    Y = [];
    
    skip_to_idx = 0;
    overflow_cnt = 0;
    overleaf_const = 255;
    overflow_sequence = [0, 1, 0];
    %overflow_sequence = [0];
    
    %X
    
    for i=1:length(X)
        %starts with 0
        if (skip_to_idx > i)
            continue
        end
        if (X(i) == 0)
            if isequal(X(i:(i+length(overflow_sequence)-1)), overflow_sequence)                
                
                skip_to_idx = i+length(overflow_sequence);
                overflow_cnt = overflow_cnt + 1;
                continue
            end
            if (i == 1)
                counting_val = 1;
                continue
            end
        end


        if (counting_val == 0)
            tmp = zeros(X(i)+overleaf_const*overflow_cnt); tmp = tmp(1,:);
            Y = [Y, tmp];
            counting_val = 1;
            overflow_cnt = 0;
        else
            tmp = ones(X(i)+overleaf_const*overflow_cnt); tmp = tmp(1,:);
            Y = [Y, tmp];
            counting_val = 0;
            overflow_cnt = 0;
        end
    end

end