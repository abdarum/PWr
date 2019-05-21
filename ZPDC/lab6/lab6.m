clear all;
f = figure;
p = uipanel(f, 'Position',[0.1 0.1 1 0.1]);
 
sliderV = uicontrol(p,'Style','slider','Position',[20 0 420 20]);
sliderV.Value = 0.5;
sliderV.Callback = @sliderVMovement;
 
sliderQ = uicontrol(p,'Style','slider','Position',[20 20 420 20]);
sliderQ.Value = 0.5;
sliderQ.Callback = @sliderQMovement;
 
global vv;
vv = 0.5;
global qq;
qq = 0.5;
 


 

 
 

 
