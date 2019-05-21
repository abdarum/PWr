function ret = wavelet(im,v,Q,waves)
         
    b = 8;
    h = size(im,1);
    w = size(im,2);
    hq = h/b;
    wq = w/b;
 
    q2 = pow2(floor(Q * 10));
    X = im2double(im);
 
    [C,S] = wavedec2(X,4,waves);
    C(abs(C) < v) = 0;
    resim = waverec2(C,S,waves);
 
 
    imshow(resim);
    ret = resim;
end