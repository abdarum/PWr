function [ ] = compress_and_save(A, filename )
%COMPRESS Summary of this function goes here
%   Detailed explanation goes here

    A_siz = size(A);
    A_siz_row = A_siz(1);
    A_siz_cols = A_siz(2);
    fid = fopen(filename, 'w', 'native', 'UTF-8');  %not 'wt' !!
    for i=1:A_siz_row
        progress_compress = i/A_siz_row*100
        B = compress_row_uint8(A(i,:));
        %B = compress_row(A(i,:));   
        
%         if (i > 155 && i<160)
%                i
%                B
%                length(B)
%                
%                input('enter to continue')
%         end

        fprintf(fid, '%s\r\n', B);
    end
    fclose(fid);
end
