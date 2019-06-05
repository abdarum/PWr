A1 = [ 1 1 1 1 1 0 1 0 1 0
      0 1 0 1 0 1 0 1 0 1 
      1 1 1 1 1 0 1 0 1 0
      0 1 0 1 0 1 0 1 0 1
      1 1 1 1 1 0 1 0 1 0
      0 1 0 1 0 1 0 1 0 1
      1 1 1 1 1 0 1 0 1 0
      0 1 0 1 0 1 0 1 0 1 ];

A = imread('Lysy-w-lipcu-losowy.gif'); 
B = imread('Lysy-w-lipcu-wzorek.gif'); 
%A= 150*A;

% write(A,filename);
% Y = read(filename);


filename = 'test_compare.txt';
write(A1,filename);
filename = 'test_compressed.txt';
compress_and_save(A1, filename);


filename = 'Lysy-w-lipcu-losowy_compare.txt';
write(A,filename);
filename = 'Lysy-w-lipcu-losowy_compressed.txt';
compress_and_save(A, filename);
YA = read_and_decompress( filename );

equalA = isequal(YA,A)
figure(1)
imshow(A*200)
figure(2)
imshow(YA*200)



filename = 'Lysy-w-lipcu-wzorek_compare.txt';
write(B,filename);
filename = 'Lysy-w-lipcu-wzorek_compressed.txt';
compress_and_save(B, filename);
YB = read_and_decompress( filename );

equalB = isequal(YB,B)
figure(3)
imshow(B*200)
figure(4)
imshow(YB*200)
