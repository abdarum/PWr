IMAGE = [1, 3, 1
        3, 5, 3
        1, 3, 1]
Test = [1, 5, 9, 7, 9];
    
A = imread('Lampart.jpg');

window_basic = 1;


WINDOW_TYPE = window_basic;
IMG=Test;
IMG_O = zeros(1,9);
scale = length(IMG_O)/length(IMG);
for i=1:length(IMG_O)
    
    for j = 1:length(IMG_O)
        if eq(WINDOW_TYPE, window_basic)
            if (ge(-1/2*scale+i, j) && lt(j, -1/2*scale+i))
                IMG_O(i) = IMG_O(i) + IMG(j);
                i
                j
                
            end
        end
    end    
end
IMG_O