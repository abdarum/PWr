median_size = 7

A = imread('Leopard-with-noise.jpg');  
figure(1)
imshow(A);


J = A;
J(:,:,1)=medfilt2(J(:,:,1), [median_size median_size]);
J(:,:,2)=medfilt2(J(:,:,2), [median_size median_size]);
J(:,:,3)=medfilt2(J(:,:,3), [median_size median_size]);
figure(2)
imshow(J);


figure(2)
imshow(J);