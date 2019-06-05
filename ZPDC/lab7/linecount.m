function n = linecount(filename)
    n = 0;
    fid=fopen(filename, 'r', 'native', 'UTF-8');
    tline = fgetl(fid);
    while ischar(tline)
        tline = fgetl(fid);
        n = n+1;
    end
    fclose(fid);
end