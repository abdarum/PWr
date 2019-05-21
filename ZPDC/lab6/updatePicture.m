function updatePicture()
 
    global vv;
    global qq;
    persistent im;
    if isempty(im)
        im = imread('Leopard-with-noise.jpg');
    end
    persistent oim;
    if isempty(oim)
        oim = imread('Leopard.jpg');
    end
 
    disp('Filtering ... ');
 
    tic;
%     resim = cosinus(im,vv,qq);
%     resim = welhar(im,vv,qq);
%     resim = wavelet(im,vv,qq,'haar');
%     resim = wavelet(im,vv,qq,'bior2.2'); % CDF 5/3
    resim = wavelet(im,vv,qq,'bior4.4'); % CDF 9/7
    
    method = 'CDF_9_7' 
     
    disp(['done' num2str(toc)]);
    resim = im2uint8(resim);
    imse = immse(resim,oim);
    disp(['V: ' num2str(vv) ' Q: ' num2str(qq)]);
    disp(['Mean-squared error: ' num2str(imse)]);
    out_title = strcat('Leopard-output_', method,'_V_', num2str(vv), '_Q_', num2str(qq), '.jpg')
    fid = fopen('values.txt', 'a+');
    fprintf(fid, '%s \t\t%.2f\n', out_title, imse);
    fclose(fid);
    imwrite(resim , out_title);
end
