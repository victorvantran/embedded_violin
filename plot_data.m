% initialize
%{
close all; clear all;

pkg load instrument-control
if (exist('serial') != 3)
  disp('No serial support');
endif

x = [0:0.01:16];
y = sin(3*x);

figure(1);hold all
Dx = 50; y1 = -1.2; y2 = 1.2;

for n = 1:1:numel(x)
  plot(x,y);
  axis([x(n) x(n + Dx) y1 y2]);
  drawnow;
endfor
%}


close all; clear all;

pkg load instrument-control
if (exist('serial') != 3)
  disp('No serial support');
endif

% serial console/object
s = serial('/dev/ttyACM0', 115200);

% open serial port
fopen(s);

x = [1:1:1600];
data = x;


figure(1);hold all
Dx = 50; y1 = 0; y2 = 2000;

for n = 1:1:numel(x)
  data(x) = typecast(srl_read(s, 2), 'int16');
  plot(x,data);
  
  %y = typecast(srl_read(s, 2), 'int16');
  %plot(x(n),y);
  
  
  
  axis([x(n) x(n + Dx) y1 y2]);
  %axis([x(n) x(n + Dx) y1 y2]);
  
  pause(0.01);
 
  
  %plot(x,y);
  %axis([x(n) x(n + Dx) y1 y2]);
  drawnow;
endfor