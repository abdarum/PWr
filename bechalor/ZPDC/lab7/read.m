function [ Y ] = read( filename )
%READ Summary of this function goes here
%   Detailed explanation goes here

    fid=fopen(filename);
    tline = fgetl(fid);
    Y1 = tline;
    while ischar(tline)
        try
            disp(tline);
            tline = fgetl(fid);
            tmp = [Y1;tline];
            Y1 = tmp;
        catch
        end
    end
    fclose(fid);
    Y = double(Y1);
end

