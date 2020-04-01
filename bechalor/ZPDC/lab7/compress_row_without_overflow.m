function [ Y ] = compress_row_without_overflow( X )
%COMPRESS_ROW Summary of this function goes here
%   Detailed explanation goes here

    %starts from zero
    counting_val = 0;
    Y = [];

    counter = 0;
    for j = 1:length(X)
        if (X(j) ~= counting_val)
            Y = [Y, counter];
            counting_val = X(j);
            counter = 1;

        else
            counter = counter + 1;
        end
        if (j == length(X))
            Y = [Y, counter];
        end
    end
end



