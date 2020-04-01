i = 9
image_title = 'CygnusOlor'
A = imread(strcat(image_title,'.jpg'));
A = imresize(A, 0.5);

loop = 0

if loop>0
    for i=1:8
        var = 2^i
        Y = poissrnd(double(A)/var);
        Y = Y*var;
        Y = uint8(Y);
        imshow(Y)
        var_char =  int2str(var)
        out_title = strcat(image_title, '_scale_', var_char, '.jpg')
        imwrite(Y,out_title)
    end
else
    var = 2^i
    Y = poissrnd(double(A)/var);
    Y = Y*var;
    Y = uint8(Y);
    imshow(Y)
    var_char =  int2str(var)
    out_title = strcat(image_title, '_scale_', var_char, '.jpg')
    imwrite(Y,out_title)
end

