function ret = welhar(im,v,Q)
     
    b = 8;
    h = size(im,1);
    w = size(im,2);
    hq = h/b;
    wq = w/b;
     
    resim = zeros(h,w,3);
    q2 = pow2(floor(Q * 30));
    dim = im2double(im);
     
    for i = 1:hq
        for j = 1:wq
            y = fwht(dim((i-1)*b+1:i*b,(j-1)*b+1:j*b,:));
            y(abs(y) < v /5) = 0;
            y1 = floor(y .* q2 + 0.5) / q2;
            resim((i-1)*b+1:i*b,(j-1)*b+1:j*b,:) = ifwht(y1);
        end
        disp([num2str(100*i*b/h) ' %']);
    end
 
    image(resim);
    ret = resim;
end