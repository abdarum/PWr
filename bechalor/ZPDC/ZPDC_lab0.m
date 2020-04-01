close all
x=0:0.01*pi:2*pi;
part_of_image_line = 1/24;
resolution_x = 960;
resolution_y = 960;

cycles = 1;
m_min = -30;
m_max = ceil(1/part_of_image_line)*cycles+m_min-1;

number_of_wings = 5

figure(1)
set(gcf, 'Position', [100, 100, resolution_x, resolution_y])
y=sin(0*x);
polar(x,y);
output_image = frame2im(getframe);
figure(2)
set(gcf, 'Position', [100+resolution_x, 100, resolution_x, resolution_y]) 
polar(x,y);

image_height = size(output_image);
image_height = image_height(1);
step_line = ceil(image_height*part_of_image_line);
current_step = 1;

tmp1 = [  ]
tmp2 = [  ]
show_tmp_array = 0
           

for m=m_min:1:m_max
    figure(2)
    y=sin(number_of_wings*x+(m*pi()/10));
    polar(x,y);
    current_image = frame2im(getframe);
    
    if current_step*step_line > image_height
        low = (current_step-1)*step_line + 1;
        high = image_height;
        if show_tmp_array == 1
            tmp1=[tmp1 low]
            tmp2=[tmp2 high]
        end
        output_image(low:high, :, :) = current_image(low:high, :, :);
     else
        low = (current_step-1)*step_line + 1;
        high = current_step*step_line + 1;
        if show_tmp_array == 1
            tmp1=[tmp1 low]
            tmp2=[tmp2 high]
        end
        output_image(low:high, :, :) = current_image(low:high, :, :);
     end
     
     
     figure(1)
     imshow(output_image)
     pause(0.1);
    
    current_step = current_step + 1;
    if current_step > 1/part_of_image_line
        current_step = 1;
    end
     
end


