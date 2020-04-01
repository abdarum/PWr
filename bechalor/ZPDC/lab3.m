A = imread('Wiosna-winniczka.jpg'); 
%A = imread('Pasikonik-w-kwadracie.jpg');  
%A = imread('Lampart.jpg');
A_size = size(A);
B = zeros(A_size(1), A_size(2), A_size(3));
B = uint8(B);
C = zeros(A_size(1), A_size(2), A_size(3));
C = uint8(C);
angle = pi/4;
center_x = round(A_size(1)/2);
center_y = round(A_size(2)/2);


for x=1:A_size(1)
    for y=1:A_size(2)
%         new_x = round(cos(angle)*(x-center_x)-sin(angle)*(y-center_y))+center_x;
%         new_y = round(sin(angle)*(x-center_x)+cos(angle)*(y-center_y))+center_y;
        new_x = round(cos(angle)*(x-center_x))-round(sin(angle)*(y-center_y))+center_x;
        new_y = round(sin(angle)*(x-center_x))+round(cos(angle)*(y-center_y))+center_y;
        if new_x > 0 && new_x <= A_size(1) && new_y > 0 && new_y <= A_size(2)
            B(new_x,new_y,:) = A(x,y,:);
        end
        
        new_x = round(cos(angle)*(x-center_x)-sin(angle)*(y-center_y))+center_x;
        new_y = round(sin(angle)*(x-center_x)+cos(angle)*(y-center_y))+center_y;
%        new_x = round(cos(angle)*(x-center_x))-round(sin(angle)*(y-center_y))+center_x;
%        new_y = round(sin(angle)*(x-center_x))+round(cos(angle)*(y-center_y))+center_y;
        if new_x > 0 && new_x <= A_size(1) && new_y > 0 && new_y <= A_size(2)
            C(new_x,new_y,:) = A(x,y,:);
        end
    end
end


figure(1)
image(A)
figure(2)
image(B)
figure(3)
image(C)z