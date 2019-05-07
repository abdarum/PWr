median_size = 7

A = imread('Leopard-with-noise.jpg');  
figure(1)
imshow(A);


J = A;
J = bif(A,3,0.2,0)
% J(:,:,1)=medfilt2(J(:,:,1));
% J(:,:,2)=medfilt2(J(:,:,2));
% J(:,:,3)=medfilt2(J(:,:,3));
figure(2)
imshow(J);


figure(2)
imshow(J);