% initialize
close all; clear all;

pkg load instrument-control
if (exist('serial') != 3)
  disp('No serial support');
endif


% serial console/object
s = serial('/dev/ttyACM0', 115200);

% open serial port
fopen(s);

%{
srl_flush(s);
rawByte = srl_read(s, 10); 
sData = typecast(rawByte, 'int8
%}


% plot data
i = 1
while (1)
  data(i) = typecast(srl_read(s, 2), 'int16');
  %if (i < 150)
  %  plot(data);
  %else
  %  plot(data);
    %plot(data(end-150:end));
  %plot(data[end-150:end]);

  plot(data);
  %ylim([-300,300]);
  
  pause(0.01);
  i = i+1;
end

fclose(s);












