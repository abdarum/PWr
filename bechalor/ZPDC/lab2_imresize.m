scale = 25;
% type = 'nearest';
% type = 'bilinear';
% type = 'bicubic';
A = imread('Lampart.jpg');
B = imresize(A, 1/scale, 'nearest');
B = imresize(B, scale, 'nearest');
C = imresize(A, 1/scale, 'bilinear');
C = imresize(C, scale, 'bilinear');
D = imresize(A, 1/scale, 'bicubic');
D = imresize(D, scale, 'bicubic');
figure(1)
imshow(A)
figure(2)
imshow(B)
figure(3)
imshow(C)
figure(4)
imshow(D)