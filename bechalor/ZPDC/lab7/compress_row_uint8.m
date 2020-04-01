function [ Y ] = compress_row_uint8( X )
%COMPRESS_ROW Summary of this function goes here
%   Detailed explanation goes here

    %starts from zero
    counting_val = 0;
    Y = [];

    last_change_idx = 0;
    overleaf_const = 253;
    
    overflow_sequence = [0, 1, 0];
    %overflow_sequence = [0];
    counter = 0;
    for j = 1:length(X)
        %X(j)
        if (X(j) ~= counting_val)
            Y = [Y, skip_LF_and_CR_uint8(counter)];
            counting_val = X(j);
            last_change_idx = j;
            counter = 1;

        else
            if (counter > overleaf_const)
                Y = [Y, overflow_sequence];                
                counter = counter - overleaf_const+1;
            else
                counter = counter + 1;
            end
        end
        if (j == length(X))
            Y = [Y, skip_LF_and_CR_uint8(counter)];
        end
    end
end



