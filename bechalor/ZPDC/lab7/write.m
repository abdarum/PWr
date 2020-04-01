function [  ] = write(A, filename )
%WRITE Summary of this function goes here
%   Detailed explanation goes here

    A_siz = size(A);
    A_siz_row = A_siz(1);
    fid = fopen(filename, 'w');  %not 'wt' !!
    for i=1:A_siz_row
        if i == A_siz_row
            fprintf(fid, '%s', A(i,:));
        else 
            fprintf(fid, '%s\r\n', A(i,:));
        end
    end
    %fwrite(fid, A, '*uint8');
    fclose(fid);
end

