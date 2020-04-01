function [ Y ] = read_and_decompress( filename )
%READ_AND_DECOMPRESS Summary of this function goes here
%   Detailed explanation goes here


    line_cnt = linecount(filename);
    fid=fopen(filename, 'r', 'native', 'UTF-8');
    tline = fgetl(fid);
    tline = double(tline)
    Y1 = decompress_row_uint8(tline);
    %Y1 = decompress_row(tline);
    i=2;
    while ~feof(fid)
        progress_decompress = i/line_cnt*100
        try
            tline = fgetl(fid);
            tline = double(tline);
            tmp = decompress_row_uint8(tline);
            %tmp = decompress_row(tline);
            tmp2 = [Y1;tmp];
            Y1 = tmp2;
            s1 = size(Y1);
            s1 = s1(1);
        catch
            i
            size_tmp_vec = size(tmp)
            length_tline = length(tline)
            tline
            input('enter to continue')
        end
        i = i + 1;
    end
    fclose(fid);
    Y = double(Y1);
    line_cnt
end

