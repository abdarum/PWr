i = 1
image_title = 'CygnusOlor'


loop = 1

if loop>0
    for i=0:8
        var = 2^i
        var_char =  int2str(var)
        in_title_core = strcat(image_title, '_scale_', var_char)
        in_title = strcat(in_title_core, '.jpg')
        A = imread(in_title);
        imshow(A)
        
        I = rgb2gray(A);
%        [~,threshold] = edge(I,'sobel');
%        fudgeFactor = 0.5;
%        BWs = edge(I,'sobel',threshold * fudgeFactor);

        [~,threshold] = edge(I,'Canny');
        fudgeFactor = 0.5;
        BWs = edge(I,'Canny',threshold * fudgeFactor);
        imshow(BWs)
        out_title = strcat(in_title_core, '_Canny.jpg')
        
        imwrite(BWs,out_title)
    end
else
    var = 2^i
    var_char =  int2str(var)
    in_title_core = strcat(image_title, '_scale_', var_char)
    in_title = strcat(in_title_core, '.jpg')
    A = imread(in_title);
    imshow(A)
    [~,threshold] = edge(A,'sobel');
    fudgeFactor = 0.5;
    BWs = edge(I,'sobel',threshold * fudgeFactor);
    imshow(BWs)

    %imwrite(Y,out_title)
end

