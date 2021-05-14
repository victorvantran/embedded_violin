% initialize
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
