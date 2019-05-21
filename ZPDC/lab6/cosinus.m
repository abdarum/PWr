function ret = cosinus(im,v,Q)
     
    b = 8;
    h = size(im,1);
    w = size(im,2);
    hq = h/b;
    wq = w/b;
 
    q2 = pow2(floor(Q * 10));
    resim = zeros(h,w,3);
 
    for c = 1:3
        for i = 1:hq
            for j = 1:wq
                d = dct2(im((i-1)*b+1:i*b,(j-1)*b+1:j*b,c));
                d(abs(d) < 256 * v) = 0;
                d1 = floor(d / 256 * q2 + 0.5) / q2;
                resim((i-1)*b+1:i*b,(j-1)*b+1:j*b,c) = idct2(d1);
            end
            disp([num2str(100*i*b/h/3 + 100*(c-1)/3) ' %']);
        end
    end
     
    image(resim);
    ret = resim;
end
