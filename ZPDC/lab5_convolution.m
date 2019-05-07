tipi = @(x) (1-abs(x)).*(abs(x)<1);
x = linspace(-1,1,9);
t = tipi(x);
tipi_kernel = t'*t;

hat = @(x) abs(round(1-abs(x)));
x = linspace(-1,1,7);
h = hat(x);
hat_kernel = h'*h;

x = linspace(-2,2,15);
y = zeros(1,length(x));
reshape(y,size(x));
x(x < 0.0) = -x(x < 0.0);
q = (x <= 1);           
y(q) = ((1.5 * x(q) - 2.5) .* x(q)) .* x(q) + 1.0;
q = (1 < x & x <= 2);    
y(q) = ((-0.5 * x(q) + 2.5) .* x(q) - 4.0) .* x(q) + 2.0;
keys_kernel = y'*y;


A = imread('Leopard-with-noise.jpg');  

kernel = tipi_kernel;
kernel_sum = sum(kernel);
kernel_sum = sum(kernel_sum);
kernel_multiplier=1;
kernel = kernel .* (kernel_multiplier/kernel_sum)


A_size = size(A);
kernel_size = size(kernel);
kernel_size_half = floor(kernel_size./ 2)

B = zeros(A_size(1), A_size(2), A_size(3));
B = uint8(B);

figure(1)
imshow(A);

J = A;
wR=kernel;
wG=kernel;
wB=kernel;
J(:,:,1)=imfilter(J(:,:,1),wR,0);
J(:,:,2)=imfilter(J(:,:,2),wG,0);
J(:,:,3)=imfilter(J(:,:,3),wB,0);
figure(2)
imshow(J);

% for x=1:A_size(1)
%     progress = x/A_size(1) * 100
%     for y=1:A_size(2)
%         for c=1:3
%             weighted_pixel_sum = 0;
%         
%             for k_x=-kernel_size_half(1) :kernel_size_half(1) 
%                for k_y=-kernel_size_half(2):kernel_size_half(2) 
%                    pixel = 0;
%                    pixel_x = x - k_x;
%                    pixel_y = y - k_y;
%                    
%                    if (pixel_y >= 1) && (pixel_y <= A_size(2)) && (pixel_x >= 1) && (pixel_x <= A_size(1))
%                        pixel = A(pixel_x, pixel_y, c);
%                    end
%                    weight = kernel( k_x +kernel_size_half(1)+1, k_y + kernel_size_half(2)+1);
% 
%                    weighted_pixel_sum = weighted_pixel_sum + pixel * weight;
%                end
%             end
%             B(x,y,c) = weighted_pixel_sum;
%         end
%     end
% end
% 
% figure(3)
% imshow(B);









% filtr medianowy, splotowy
%za tydzie? filtr bilateralny

%conv2D
%filter2D t2D = t'*t;






%https://www.sciencedirect.com/science/article/pii/S002240491200299X
%https://stackoverflow.com/questions/26815141/bicubic-interpolation-matlab-to-c
%https://stackoverflow.com/questions/26823140/imresize-trying-to-understand-the-bicubic-interpolation
%https://github.com/fatheral/matlab_imresize/blob/master/imresize.py