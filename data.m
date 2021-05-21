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

%{

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
  axis([0 2000 0 2000]);

  %ylim([-300,300]);
  
  pause(0.01);
  i = i+1;
end
%}




%https://www.digikey.com/en/products/detail/interlink-electronics/34-00071/7672216?utm_adgroup=Touch%20Sensors&utm_source=google&utm_medium=cpc&utm_campaign=Shopping_Product_Sensors%2C%20Transducers_NEW&utm_term=&utm_content=Touch%20Sensors&gclid=EAIaIQobChMIxNHe4tjQ8AIVHjizAB1fsAOTEAQYCiABEgIe2fD_BwE



% plot data
i = 100
while (1)
  data(i) = typecast(srl_read(s, 2), 'uint16');
  plot(data);
  axis([i - 100 i -1000 5096]);
  
  pause(0.002);
  i = i+1;
end


fclose(s);












