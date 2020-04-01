


clear all;
close all;

A = imread('Leopard-with-noise.jpg');

J=A;
% Ja = im2double(J);
% J = im2double(J);
% J1a = Ja(:,:,1);

ratio = 3
J1=haar(J(:,:,1), ratio);
J2=haar(J(:,:,2), ratio);
J3=haar(J(:,:,3), ratio);

J(:,:,1)=J1;
J(:,:,2)=J2;
J(:,:,3)=J3;

% J = uint8(J*255);
imshow(J)
%imagesc(J)
out_title = strcat('Leopard-with-noise_haar_',strrep(num2str(ratio),'.','_'),'.jpg')
imwrite(J,out_title)
imwrite(A,'Leopard-with-noise_test.jpg')