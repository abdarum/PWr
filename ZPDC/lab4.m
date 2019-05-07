%A = imread('Pasikonik-w-kwadracie.jpg');  
%A = imread('Lampart.jpg');
A = imread('4demosaicking.bmp');

%A = imread('blue.png');

A_size = size(A);

B = zeros(A_size(1), A_size(2), A_size(3));
B = uint8(B);
C = zeros(A_size(1), A_size(2), A_size(3));
C = uint8(C);

% 1 - R; 2 - G; 3 - B
X_Trans = [2 3 2 2 1 2
    1 2 1 3 2 3
    2 3 2 2 1 2
    2 1 2 2 3 2
    3 2 3 1 2 1
    2 1 2 2 3 2];
Bayer = [3 2; 2 1];
X = zeros(6, 6, 3);
X = uint8(X);
Y = zeros(2, 2, 3);
Y = uint8(Y);
for x=1:2
    for y=1:2
        Y(x,y,Bayer(x,y))=255;
    end
end
imshow(X)
for x=1:A_size(1)
    for y=1:A_size(2)
        color_bayer = Bayer(mod((x-1),2)+1, mod((y-1),2)+1);
        B(x,y,color_bayer) = A(x,y,color_bayer);
        color_x_trans= X_Trans(mod((x-1),6)+1, mod((y-1),6)+1);
        C(x,y,color_x_trans) = A(x,y,color_x_trans);
    end
end
figure(1)
imshow(A)
figure(2)
imshow(B)
figure(3)
imshow(C)

J = B;
wR=[0.25 0.5 0.25
   0.5   1   0.5
   0.25 0.5 0.25];

wG=[0    0.25 0
   0.25  1    0.25
   0     0.25 0];
J(:,:,1)=imfilter(J(:,:,1),wR,0);
J(:,:,2)=imfilter(J(:,:,2),wG,0);
J(:,:,3)=imfilter(J(:,:,3),wR,0);

figure(4)
imshow(J);

J = C;
wR=[0.25 0.5 0.25
   0.5   1   0.5
   0.25 0.5 0.25];

wG=[0    0.25 0
   0.25  1    0.25
   0     0.25 0];
J(:,:,1)=imfilter(J(:,:,1),wR,0);
J(:,:,2)=imfilter(J(:,:,2),wG,0);
J(:,:,3)=imfilter(J(:,:,3),wR,0);

figure(5)
imshow(J);
