EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 4400 1900 0    50   Input ~ 0
BOOT0
Text GLabel 2800 1550 2    50   Input ~ 0
BOOT0
$Comp
L Switch:SW_DIP_x01 SW?
U 1 1 60D6B69F
P 2500 1250
F 0 "SW?" V 2454 1380 50  0000 L CNN
F 1 "SW_DIP_x01" V 2545 1380 50  0000 L CNN
F 2 "" H 2500 1250 50  0001 C CNN
F 3 "~" H 2500 1250 50  0001 C CNN
	1    2500 1250
	0    1    1    0   
$EndComp
Wire Wire Line
	2800 1550 2500 1550
Wire Wire Line
	2500 1550 2500 1650
Connection ~ 2500 1550
Wire Wire Line
	2500 1850 2500 2000
$Comp
L power:+3V3 #PWR?
U 1 1 60D7578E
P 2500 850
F 0 "#PWR?" H 2500 700 50  0001 C CNN
F 1 "+3V3" H 2515 1023 50  0000 C CNN
F 2 "" H 2500 850 50  0001 C CNN
F 3 "" H 2500 850 50  0001 C CNN
	1    2500 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 850  2500 950 
$Comp
L power:+3.3VA #PWR?
U 1 1 60D79075
P 5300 1300
F 0 "#PWR?" H 5300 1150 50  0001 C CNN
F 1 "+3.3VA" H 5315 1473 50  0000 C CNN
F 2 "" H 5300 1300 50  0001 C CNN
F 3 "" H 5300 1300 50  0001 C CNN
	1    5300 1300
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 60D762D3
P 4900 1300
F 0 "#PWR?" H 4900 1150 50  0001 C CNN
F 1 "+3V3" H 4915 1473 50  0000 C CNN
F 2 "" H 4900 1300 50  0001 C CNN
F 3 "" H 4900 1300 50  0001 C CNN
	1    4900 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 1500 5300 1300
$Comp
L Switch:SW_Push SW?
U 1 1 60D7CFD1
P 1000 1400
F 0 "SW?" H 1000 1685 50  0000 C CNN
F 1 "SW_Push" H 1000 1594 50  0000 C CNN
F 2 "" H 1000 1600 50  0001 C CNN
F 3 "~" H 1000 1600 50  0001 C CNN
	1    1000 1400
	0    -1   -1   0   
$EndComp
Text GLabel 4400 1700 0    50   Input ~ 0
NRST
Text GLabel 1450 1150 2    50   Input ~ 0
NRST
$Comp
L Device:R_Small R?
U 1 1 60D8220F
P 1000 1000
F 0 "R?" H 1059 1046 50  0000 L CNN
F 1 "10k" H 1059 955 50  0000 L CNN
F 2 "" H 1000 1000 50  0001 C CNN
F 3 "~" H 1000 1000 50  0001 C CNN
	1    1000 1000
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 60D84639
P 1000 800
F 0 "#PWR?" H 1000 650 50  0001 C CNN
F 1 "+3V3" H 1015 973 50  0000 C CNN
F 2 "" H 1000 800 50  0001 C CNN
F 3 "" H 1000 800 50  0001 C CNN
	1    1000 800 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60D70F3B
P 2500 2000
F 0 "#PWR?" H 2500 1750 50  0001 C CNN
F 1 "GND" H 2505 1827 50  0000 C CNN
F 2 "" H 2500 2000 50  0001 C CNN
F 3 "" H 2500 2000 50  0001 C CNN
	1    2500 2000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60D8609D
P 1000 1700
F 0 "#PWR?" H 1000 1450 50  0001 C CNN
F 1 "GND" H 1005 1527 50  0000 C CNN
F 2 "" H 1000 1700 50  0001 C CNN
F 3 "" H 1000 1700 50  0001 C CNN
	1    1000 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60D86B68
P 1250 1350
F 0 "C?" H 1342 1396 50  0000 L CNN
F 1 "100n" H 1342 1305 50  0000 L CNN
F 2 "" H 1250 1350 50  0001 C CNN
F 3 "~" H 1250 1350 50  0001 C CNN
	1    1250 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60D87F95
P 1250 1550
F 0 "#PWR?" H 1250 1300 50  0001 C CNN
F 1 "GND" H 1255 1377 50  0000 C CNN
F 2 "" H 1250 1550 50  0001 C CNN
F 3 "" H 1250 1550 50  0001 C CNN
	1    1250 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 1150 1250 1150
Wire Wire Line
	1000 1150 1000 1100
Wire Wire Line
	1000 900  1000 800 
Wire Wire Line
	1000 1150 1000 1200
Connection ~ 1000 1150
Wire Wire Line
	1000 1600 1000 1700
Wire Wire Line
	1250 1150 1250 1250
Connection ~ 1250 1150
Wire Wire Line
	1250 1150 1000 1150
Wire Wire Line
	1250 1450 1250 1550
$Comp
L power:GND #PWR?
U 1 1 60D8B3B3
P 4900 5200
F 0 "#PWR?" H 4900 4950 50  0001 C CNN
F 1 "GND" H 4905 5027 50  0000 C CNN
F 2 "" H 4900 5200 50  0001 C CNN
F 3 "" H 4900 5200 50  0001 C CNN
	1    4900 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 1500 5400 1400
Wire Wire Line
	5400 1400 5200 1400
Wire Wire Line
	5200 1500 5200 1400
Wire Wire Line
	5000 1500 5000 1400
Connection ~ 5200 1400
Wire Wire Line
	5200 1400 5100 1400
Wire Wire Line
	5100 1400 5000 1400
Connection ~ 5100 1400
Wire Wire Line
	5100 1500 5100 1400
Wire Wire Line
	4900 1400 4900 1300
Wire Wire Line
	4900 1500 4900 1400
Connection ~ 4900 1400
Connection ~ 5000 1400
Wire Wire Line
	5000 1400 4900 1400
Wire Wire Line
	4900 5100 4900 5200
Text Notes 750  4250 0    39   ~ 0
LCn = 2 * (LOAD_CAPACITANCE - STRAY_CAPACITANCE)
Connection ~ 4900 5100
Connection ~ 5000 5100
Wire Wire Line
	5000 5100 4900 5100
Wire Wire Line
	5100 5100 5000 5100
Connection ~ 5100 5100
Connection ~ 5200 5100
Wire Wire Line
	5200 5100 5100 5100
Wire Wire Line
	5300 5100 5200 5100
Wire Wire Line
	1250 3200 1250 3300
Wire Wire Line
	1250 3600 1250 3500
$Comp
L MCU_ST_STM32L4:STM32L476RGTx U?
U 1 1 60D6773E
P 5100 3300
F 0 "U?" H 5800 5200 50  0000 C CNN
F 1 "STM32L476RGTx" H 5800 5100 50  0000 C CNN
F 2 "Package_QFP:LQFP-64_10x10mm_P0.5mm" H 4500 1600 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00108832.pdf" H 5100 3300 50  0001 C CNN
	1    5100 3300
	1    0    0    -1  
$EndComp
Text GLabel 4400 3000 0    50   Input ~ 0
HSE_OUT
Text GLabel 4400 2900 0    50   Input ~ 0
HSE_IN
Text GLabel 1950 3200 2    50   Input ~ 0
HSE_IN
Text GLabel 1950 3600 2    50   Input ~ 0
HSE_OUT
Text GLabel 5800 2900 2    50   Input ~ 0
USB_D+
Text GLabel 5800 2800 2    50   Input ~ 0
USB_D-
Text Notes 15550 -1800 0    50   ~ 0
STM32L4X6 already includes \nan embedded pull-up resistor
Text GLabel 16350 -2650 2    50   Input ~ 0
USB_D-
$Comp
L power:GND #PWR?
U 1 1 60DBFB80
P 15950 -2250
F 0 "#PWR?" H 15950 -2500 50  0001 C CNN
F 1 "GND" H 15955 -2423 50  0000 C CNN
F 2 "" H 15950 -2250 50  0001 C CNN
F 3 "" H 15950 -2250 50  0001 C CNN
	1    15950 -2250
	1    0    0    -1  
$EndComp
NoConn ~ 16250 -2550
NoConn ~ 15850 -2350
Wire Wire Line
	16250 -2950 16350 -2950
Wire Wire Line
	16250 -2750 16350 -2750
Wire Wire Line
	16250 -2650 16350 -2650
Wire Wire Line
	15950 -2350 15950 -2250
Text GLabel 16350 -2750 2    50   Input ~ 0
USB_D+
Text GLabel 5800 3000 2    50   Input ~ 0
SWDIO
Text GLabel 5800 3100 2    50   Input ~ 0
SWCLK
Text GLabel 5800 3700 2    50   Input ~ 0
SWO
$Comp
L Connector:USB_B_Micro J?
U 1 1 60DBEA17
P 15950 -2750
F 0 "J?" H 16007 -2283 50  0000 C CNN
F 1 "USB_B_Micro" H 16007 -2374 50  0000 C CNN
F 2 "" H 16100 -2800 50  0001 C CNN
F 3 "~" H 16100 -2800 50  0001 C CNN
	1    15950 -2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	16350 -2950 16350 -3050
$Comp
L power:+5V #PWR?
U 1 1 60DCE1FB
P 16350 -3050
F 0 "#PWR?" H 16350 -3200 50  0001 C CNN
F 1 "+5V" H 16365 -2877 50  0000 C CNN
F 2 "" H 16350 -3050 50  0001 C CNN
F 3 "" H 16350 -3050 50  0001 C CNN
	1    16350 -3050
	1    0    0    -1  
$EndComp
$Comp
L Device:Ferrite_Bead_Small FB?
U 1 1 60DCEDBD
P 15250 1600
F 0 "FB?" V 15013 1600 50  0000 C CNN
F 1 "600 @ 600MHz" V 15104 1600 50  0000 C CNN
F 2 "" V 15180 1600 50  0001 C CNN
F 3 "~" H 15250 1600 50  0001 C CNN
	1    15250 1600
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60DD2787
P 15450 1800
F 0 "C?" H 15542 1846 50  0000 L CNN
F 1 "10u" H 15542 1755 50  0000 L CNN
F 2 "" H 15450 1800 50  0001 C CNN
F 3 "~" H 15450 1800 50  0001 C CNN
	1    15450 1800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60DD3C02
P 15450 2000
F 0 "#PWR?" H 15450 1750 50  0001 C CNN
F 1 "GND" H 15455 1827 50  0000 C CNN
F 2 "" H 15450 2000 50  0001 C CNN
F 3 "" H 15450 2000 50  0001 C CNN
	1    15450 2000
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 60DD9102
P 3850 -1250
F 0 "#PWR?" H 3850 -1400 50  0001 C CNN
F 1 "+3V3" H 3865 -1077 50  0000 C CNN
F 2 "" H 3850 -1250 50  0001 C CNN
F 3 "" H 3850 -1250 50  0001 C CNN
	1    3850 -1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60DDA9E7
P 3850 -950
F 0 "C?" H 3942 -904 50  0000 L CNN
F 1 "4u7" H 3942 -995 50  0000 L CNN
F 2 "" H 3850 -950 50  0001 C CNN
F 3 "~" H 3850 -950 50  0001 C CNN
	1    3850 -950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60DDB37C
P 4250 -950
F 0 "C?" H 4342 -904 50  0000 L CNN
F 1 "100n" H 4342 -995 50  0000 L CNN
F 2 "" H 4250 -950 50  0001 C CNN
F 3 "~" H 4250 -950 50  0001 C CNN
	1    4250 -950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60DDB684
P 4650 -950
F 0 "C?" H 4742 -904 50  0000 L CNN
F 1 "100n" H 4742 -995 50  0000 L CNN
F 2 "" H 4650 -950 50  0001 C CNN
F 3 "~" H 4650 -950 50  0001 C CNN
	1    4650 -950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60DDC3E4
P 5050 -950
F 0 "C?" H 5142 -904 50  0000 L CNN
F 1 "100n" H 5142 -995 50  0000 L CNN
F 2 "" H 5050 -950 50  0001 C CNN
F 3 "~" H 5050 -950 50  0001 C CNN
	1    5050 -950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60DDD230
P 5450 -950
F 0 "C?" H 5542 -904 50  0000 L CNN
F 1 "100n" H 5542 -995 50  0000 L CNN
F 2 "" H 5450 -950 50  0001 C CNN
F 3 "~" H 5450 -950 50  0001 C CNN
	1    5450 -950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60DDD667
P 5850 -950
F 0 "C?" H 5942 -904 50  0000 L CNN
F 1 "100n" H 5942 -995 50  0000 L CNN
F 2 "" H 5850 -950 50  0001 C CNN
F 3 "~" H 5850 -950 50  0001 C CNN
	1    5850 -950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60DDD9AB
P 3850 -650
F 0 "#PWR?" H 3850 -900 50  0001 C CNN
F 1 "GND" H 3855 -823 50  0000 C CNN
F 2 "" H 3850 -650 50  0001 C CNN
F 3 "" H 3850 -650 50  0001 C CNN
	1    3850 -650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 -1150 3850 -1050
Wire Wire Line
	5850 -1050 5850 -1150
Wire Wire Line
	5850 -1150 5450 -1150
Connection ~ 3850 -1150
Wire Wire Line
	4250 -1050 4250 -1150
Connection ~ 4250 -1150
Wire Wire Line
	4250 -1150 3850 -1150
Wire Wire Line
	4650 -1150 4650 -1050
Connection ~ 4650 -1150
Wire Wire Line
	4650 -1150 4250 -1150
Wire Wire Line
	5050 -1050 5050 -1150
Connection ~ 5050 -1150
Wire Wire Line
	5050 -1150 4650 -1150
Wire Wire Line
	5450 -1050 5450 -1150
Connection ~ 5450 -1150
Wire Wire Line
	5450 -1150 5050 -1150
Wire Wire Line
	5850 -850 5850 -750
Wire Wire Line
	3850 -850 3850 -750
Wire Wire Line
	4250 -850 4250 -750
Connection ~ 4250 -750
Wire Wire Line
	4250 -750 3850 -750
Wire Wire Line
	4650 -850 4650 -750
Wire Wire Line
	4250 -750 4650 -750
Connection ~ 4650 -750
Wire Wire Line
	4650 -750 5050 -750
Wire Wire Line
	5050 -750 5050 -850
Connection ~ 5050 -750
Wire Wire Line
	5050 -750 5450 -750
Wire Wire Line
	5450 -850 5450 -750
Connection ~ 5450 -750
Wire Wire Line
	5450 -750 5850 -750
Wire Wire Line
	3850 -1250 3850 -1150
Wire Wire Line
	3850 -750 3850 -650
Connection ~ 3850 -750
Text Notes 4600 -300 0    50   ~ 0
VDD Filter
Text Notes 7450 -300 0    50   ~ 0
VDDA Filter
$Comp
L Device:L_Small L?
U 1 1 60DFD030
P 7500 -1150
F 0 "L?" V 7685 -1150 50  0000 C CNN
F 1 "27n" V 7594 -1150 50  0000 C CNN
F 2 "" H 7500 -1150 50  0001 C CNN
F 3 "~" H 7500 -1150 50  0001 C CNN
	1    7500 -1150
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60E06BBD
P 7700 -950
F 0 "C?" H 7792 -904 50  0000 L CNN
F 1 "1u" H 7792 -995 50  0000 L CNN
F 2 "" H 7700 -950 50  0001 C CNN
F 3 "~" H 7700 -950 50  0001 C CNN
	1    7700 -950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60E074DC
P 8100 -950
F 0 "C?" H 8192 -904 50  0000 L CNN
F 1 "100n" H 8192 -995 50  0000 L CNN
F 2 "" H 8100 -950 50  0001 C CNN
F 3 "~" H 8100 -950 50  0001 C CNN
	1    8100 -950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60E07812
P 7700 -650
F 0 "#PWR?" H 7700 -900 50  0001 C CNN
F 1 "GND" H 7705 -823 50  0000 C CNN
F 2 "" H 7700 -650 50  0001 C CNN
F 3 "" H 7700 -650 50  0001 C CNN
	1    7700 -650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 -1250 7200 -1150
Wire Wire Line
	7200 -1150 7400 -1150
Wire Wire Line
	7700 -850 7700 -750
Wire Wire Line
	7700 -750 8100 -750
Wire Wire Line
	8100 -850 8100 -750
Wire Wire Line
	7700 -1050 7700 -1150
$Comp
L power:+3V3 #PWR?
U 1 1 60E12925
P 7200 -1250
F 0 "#PWR?" H 7200 -1400 50  0001 C CNN
F 1 "+3V3" H 7215 -1077 50  0000 C CNN
F 2 "" H 7200 -1250 50  0001 C CNN
F 3 "" H 7200 -1250 50  0001 C CNN
	1    7200 -1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 -1150 7600 -1150
$Comp
L power:+3.3VA #PWR?
U 1 1 60E10993
P 8300 -1250
F 0 "#PWR?" H 8300 -1400 50  0001 C CNN
F 1 "+3.3VA" H 8315 -1077 50  0000 C CNN
F 2 "" H 8300 -1250 50  0001 C CNN
F 3 "" H 8300 -1250 50  0001 C CNN
	1    8300 -1250
	1    0    0    -1  
$EndComp
Connection ~ 7700 -1150
Wire Wire Line
	8100 -1150 7700 -1150
Wire Wire Line
	8100 -1050 8100 -1150
Wire Wire Line
	8100 -1150 8300 -1150
Wire Wire Line
	8300 -1150 8300 -1250
Connection ~ 8100 -1150
Wire Wire Line
	7700 -750 7700 -650
Connection ~ 7700 -750
$Comp
L power:GND #PWR?
U 1 1 60E4CE8E
P 1500 2900
F 0 "#PWR?" H 1500 2650 50  0001 C CNN
F 1 "GND" H 1505 2727 50  0000 C CNN
F 2 "" H 1500 2900 50  0001 C CNN
F 3 "" H 1500 2900 50  0001 C CNN
	1    1500 2900
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60E66960
P 1500 3100
F 0 "C?" H 1592 3146 50  0000 L CNN
F 1 "12p" H 1592 3055 50  0000 L CNN
F 2 "" H 1500 3100 50  0001 C CNN
F 3 "~" H 1500 3100 50  0001 C CNN
	1    1500 3100
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 60E6E922
P 1500 3700
F 0 "C?" H 1592 3746 50  0000 L CNN
F 1 "12p" H 1592 3655 50  0000 L CNN
F 2 "" H 1500 3700 50  0001 C CNN
F 3 "~" H 1500 3700 50  0001 C CNN
	1    1500 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60E6F60E
P 1500 3900
F 0 "#PWR?" H 1500 3650 50  0001 C CNN
F 1 "GND" H 1505 3727 50  0000 C CNN
F 2 "" H 1500 3900 50  0001 C CNN
F 3 "" H 1500 3900 50  0001 C CNN
	1    1500 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 3800 1500 3900
Wire Wire Line
	1500 3000 1500 2900
Wire Wire Line
	1250 3600 1500 3600
$Comp
L Device:Crystal_GND24_Small Y?
U 1 1 60E35C9B
P 1250 3400
F 0 "Y?" V 1000 3200 50  0000 L CNN
F 1 "16MHz" V 1100 3100 50  0000 L CNN
F 2 "" H 1250 3400 50  0001 C CNN
F 3 "~" H 1250 3400 50  0001 C CNN
	1    1250 3400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60E86CCE
P 1050 3400
F 0 "#PWR?" H 1050 3150 50  0001 C CNN
F 1 "GND" H 1055 3227 50  0000 C CNN
F 2 "" H 1050 3400 50  0001 C CNN
F 3 "" H 1050 3400 50  0001 C CNN
	1    1050 3400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60E877F3
P 1450 3400
F 0 "#PWR?" H 1450 3150 50  0001 C CNN
F 1 "GND" H 1455 3227 50  0000 C CNN
F 2 "" H 1450 3400 50  0001 C CNN
F 3 "" H 1450 3400 50  0001 C CNN
	1    1450 3400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1050 3400 1150 3400
Wire Wire Line
	1350 3400 1450 3400
Wire Wire Line
	1500 3200 1250 3200
$Comp
L Device:R_Small R?
U 1 1 60D70494
P 2500 1750
F 0 "R?" H 2559 1796 50  0000 L CNN
F 1 "10k" H 2559 1705 50  0000 L CNN
F 2 "" H 2500 1750 50  0001 C CNN
F 3 "~" H 2500 1750 50  0001 C CNN
	1    2500 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 60EA56BC
P 1750 3200
F 0 "R?" V 1554 3200 50  0000 C CNN
F 1 "47" V 1645 3200 50  0000 C CNN
F 2 "" H 1750 3200 50  0001 C CNN
F 3 "~" H 1750 3200 50  0001 C CNN
	1    1750 3200
	0    1    1    0   
$EndComp
Wire Wire Line
	1950 3200 1850 3200
Wire Wire Line
	1650 3200 1500 3200
Connection ~ 1500 3200
Wire Wire Line
	1500 3600 1950 3600
Connection ~ 1500 3600
Wire Notes Line
	1900 2100 1900 550 
Wire Notes Line
	1900 550  550  550 
Wire Notes Line
	2150 2300 3250 2300
Wire Notes Line
	3250 2300 3250 550 
Wire Notes Line
	3250 550  2150 550 
Wire Notes Line
	2150 550  2150 2300
Wire Notes Line
	650  2600 2550 2600
Wire Notes Line
	2550 4400 650  4400
Wire Notes Line
	650  4400 650  2600
Wire Notes Line
	1900 2100 550  2100
Wire Notes Line
	550  2100 550  550 
Wire Notes Line
	3550 -1600 3550 -150
Wire Notes Line
	3550 -150 6350 -150
Wire Notes Line
	6350 -150 6350 -1600
Wire Notes Line
	6350 -1600 3550 -1600
Wire Notes Line
	7050 -1600 8550 -1600
Wire Notes Line
	8550 -1600 8550 -150
Wire Notes Line
	8550 -150 7050 -150
Wire Notes Line
	7050 -150 7050 -1600
Wire Notes Line
	2550 2600 2550 4400
$Comp
L power:GND #PWR?
U 1 1 60F1B979
P 18350 2400
F 0 "#PWR?" H 18350 2150 50  0001 C CNN
F 1 "GND" H 18355 2227 50  0000 C CNN
F 2 "" H 18350 2400 50  0001 C CNN
F 3 "" H 18350 2400 50  0001 C CNN
	1    18350 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	18350 2300 18350 2400
$Comp
L Custom_Power:MP2359 U?
U 1 1 60F1AF54
P 18350 1450
F 0 "U?" H 18350 1415 50  0000 C CNN
F 1 "MP2359" H 18350 1324 50  0000 C CNN
F 2 "" H 18350 1450 50  0001 C CNN
F 3 "" H 18350 1450 50  0001 C CNN
	1    18350 1450
	1    0    0    -1  
$EndComp
Text GLabel 18050 1750 0    50   Input ~ 0
BUCK_IN
Text GLabel 18050 1850 0    50   Input ~ 0
BUCK_EN
Text GLabel 18650 1850 2    50   Input ~ 0
BUCK_SW
Text GLabel 18650 1950 2    50   Input ~ 0
BUCK_FB
$Comp
L Transistor_FET:AO3401A Q?
U 1 1 60F411AA
P 14000 1700
F 0 "Q?" V 14342 1700 50  0000 C CNN
F 1 "AO3401A" V 14251 1700 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 14200 1625 50  0001 L CIN
F 3 "http://www.aosmd.com/pdfs/datasheet/AO3401A.pdf" H 14000 1700 50  0001 L CNN
	1    14000 1700
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60F460B6
P 14000 2000
F 0 "#PWR?" H 14000 1750 50  0001 C CNN
F 1 "GND" H 14005 1827 50  0000 C CNN
F 2 "" H 14000 2000 50  0001 C CNN
F 3 "" H 14000 2000 50  0001 C CNN
	1    14000 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	13700 1600 13800 1600
Wire Wire Line
	14000 1900 14000 2000
Text GLabel 15700 1600 2    50   Input ~ 0
BUCK_IN
Wire Wire Line
	15350 1600 15450 1600
Wire Wire Line
	15450 1600 15450 1700
Connection ~ 15450 1600
Wire Wire Line
	15450 1600 15700 1600
Wire Wire Line
	15450 1900 15450 2000
$Comp
L Device:Polyfuse_Small F?
U 1 1 60F6CD27
P 14700 1600
F 0 "F?" V 14495 1600 50  0000 C CNN
F 1 "250mA" V 14586 1600 50  0000 C CNN
F 2 "" H 14750 1400 50  0001 L CNN
F 3 "~" H 14700 1600 50  0001 C CNN
	1    14700 1600
	0    1    1    0   
$EndComp
Text Notes 14950 4350 0    50   ~ 0
Voltage divider to step down via \npotential divider from BUCK_IN to [1.2V, 6V)\n
$Comp
L Device:R_Small R?
U 1 1 60FCE96D
P 15400 3800
F 0 "R?" V 15204 3800 50  0000 C CNN
F 1 "100k" V 15295 3800 50  0000 C CNN
F 2 "" H 15400 3800 50  0001 C CNN
F 3 "~" H 15400 3800 50  0001 C CNN
	1    15400 3800
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 60FCF908
P 15900 3800
F 0 "R?" V 15704 3800 50  0000 C CNN
F 1 "68k" V 15795 3800 50  0000 C CNN
F 2 "" H 15900 3800 50  0001 C CNN
F 3 "~" H 15900 3800 50  0001 C CNN
	1    15900 3800
	0    1    1    0   
$EndComp
Wire Wire Line
	15200 3800 15300 3800
Wire Wire Line
	15500 3800 15650 3800
Wire Wire Line
	16000 3800 16100 3800
Wire Wire Line
	16100 3800 16100 3900
Text GLabel 16000 3400 2    50   Input ~ 0
BUCK_EN
$Comp
L power:GND #PWR?
U 1 1 60FCFACE
P 16100 3900
F 0 "#PWR?" H 16100 3650 50  0001 C CNN
F 1 "GND" H 16105 3727 50  0000 C CNN
F 2 "" H 16100 3900 50  0001 C CNN
F 3 "" H 16100 3900 50  0001 C CNN
	1    16100 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	15650 3800 15650 3400
Wire Wire Line
	15650 3400 16000 3400
Connection ~ 15650 3800
Wire Wire Line
	15650 3800 15800 3800
Text GLabel 19750 1800 0    50   Input ~ 0
BUCK_SW
$Comp
L Device:L_Small L?
U 1 1 61028066
P 20200 1800
F 0 "L?" V 20385 1800 50  0000 C CNN
F 1 "10u" V 20294 1800 50  0000 C CNN
F 2 "" H 20200 1800 50  0001 C CNN
F 3 "~" H 20200 1800 50  0001 C CNN
	1    20200 1800
	0    -1   -1   0   
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 6102B405
P 20900 1650
F 0 "#PWR?" H 20900 1500 50  0001 C CNN
F 1 "+3V3" H 20915 1823 50  0000 C CNN
F 2 "" H 20900 1650 50  0001 C CNN
F 3 "" H 20900 1650 50  0001 C CNN
	1    20900 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky_Small D?
U 1 1 610384E6
P 19900 2000
F 0 "D?" V 19854 2070 50  0000 L CNN
F 1 "B5819W" V 19945 2070 50  0000 L CNN
F 2 "" V 19900 2000 50  0001 C CNN
F 3 "~" V 19900 2000 50  0001 C CNN
	1    19900 2000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6104D315
P 19900 2200
F 0 "#PWR?" H 19900 1950 50  0001 C CNN
F 1 "GND" H 19905 2027 50  0000 C CNN
F 2 "" H 19900 2200 50  0001 C CNN
F 3 "" H 19900 2200 50  0001 C CNN
	1    19900 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 61034DA5
P 20600 2200
F 0 "#PWR?" H 20600 1950 50  0001 C CNN
F 1 "GND" H 20605 2027 50  0000 C CNN
F 2 "" H 20600 2200 50  0001 C CNN
F 3 "" H 20600 2200 50  0001 C CNN
	1    20600 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 6102DE33
P 20600 2000
F 0 "C?" H 20692 2046 50  0000 L CNN
F 1 "10u" H 20692 1955 50  0000 L CNN
F 2 "" H 20600 2000 50  0001 C CNN
F 3 "~" H 20600 2000 50  0001 C CNN
	1    20600 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	19750 1800 19900 1800
Wire Wire Line
	19900 1800 19900 1900
Wire Wire Line
	19900 2100 19900 2200
Wire Wire Line
	19900 1800 20100 1800
Wire Wire Line
	20900 1800 20900 1650
Connection ~ 19900 1800
Wire Wire Line
	20600 2100 20600 2200
$Comp
L power:GND #PWR?
U 1 1 61087E6D
P 20900 2200
F 0 "#PWR?" H 20900 1950 50  0001 C CNN
F 1 "GND" H 20905 2027 50  0000 C CNN
F 2 "" H 20900 2200 50  0001 C CNN
F 3 "" H 20900 2200 50  0001 C CNN
	1    20900 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 6108B6DC
P 20900 2000
F 0 "C?" H 20992 2046 50  0000 L CNN
F 1 "10u" H 20992 1955 50  0000 L CNN
F 2 "" H 20900 2000 50  0001 C CNN
F 3 "~" H 20900 2000 50  0001 C CNN
	1    20900 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	20600 1800 20600 1900
Wire Wire Line
	20600 1800 20900 1800
Wire Wire Line
	20900 1800 20900 1900
Wire Wire Line
	20900 2100 20900 2200
Connection ~ 20900 1800
Wire Wire Line
	20300 1800 20600 1800
Connection ~ 20600 1800
Wire Wire Line
	20100 3350 20100 3450
Connection ~ 20100 3350
Wire Wire Line
	19900 3350 20100 3350
Wire Wire Line
	20100 2850 20100 3050
Wire Wire Line
	20100 3250 20100 3350
$Comp
L power:+3V3 #PWR?
U 1 1 610FB95E
P 20100 2850
F 0 "#PWR?" H 20100 2700 50  0001 C CNN
F 1 "+3V3" H 20115 3023 50  0000 C CNN
F 2 "" H 20100 2850 50  0001 C CNN
F 3 "" H 20100 2850 50  0001 C CNN
	1    20100 2850
	1    0    0    -1  
$EndComp
Text Notes 19350 4500 0    50   ~ 0
R2 = R1/((Vout/0.81V) - 1)
Wire Wire Line
	20100 3950 20100 4050
$Comp
L Device:R_Small R?
U 1 1 610A9648
P 20100 3850
F 0 "R?" H 20159 3896 50  0000 L CNN
F 1 "270" H 20159 3805 50  0000 L CNN
F 2 "" H 20100 3850 50  0001 C CNN
F 3 "~" H 20100 3850 50  0001 C CNN
	1    20100 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	20100 3650 20100 3750
$Comp
L power:GND #PWR?
U 1 1 6106AF89
P 20100 4050
F 0 "#PWR?" H 20100 3800 50  0001 C CNN
F 1 "GND" H 20105 3877 50  0000 C CNN
F 2 "" H 20100 4050 50  0001 C CNN
F 3 "" H 20100 4050 50  0001 C CNN
	1    20100 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 6102A407
P 20100 3150
F 0 "R?" H 20159 3196 50  0000 L CNN
F 1 "47k" H 20159 3105 50  0000 L CNN
F 2 "" H 20100 3150 50  0001 C CNN
F 3 "~" H 20100 3150 50  0001 C CNN
	1    20100 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 6102F557
P 20100 3550
F 0 "R?" H 20159 3596 50  0000 L CNN
F 1 "15k" H 20159 3505 50  0000 L CNN
F 2 "" H 20100 3550 50  0001 C CNN
F 3 "~" H 20100 3550 50  0001 C CNN
	1    20100 3550
	1    0    0    -1  
$EndComp
Text GLabel 19900 3350 0    50   Input ~ 0
BUCK_FB
Wire Wire Line
	20950 500  20950 600 
Wire Wire Line
	20950 200  20950 300 
Text GLabel 20950 600  0    50   Input ~ 0
BUCK_SW
Text GLabel 20950 200  0    50   Input ~ 0
BUCK_BST
$Comp
L Device:C_Small C?
U 1 1 610214E1
P 20950 400
F 0 "C?" H 21042 446 50  0000 L CNN
F 1 "10u" H 21042 355 50  0000 L CNN
F 2 "" H 20950 400 50  0001 C CNN
F 3 "~" H 20950 400 50  0001 C CNN
	1    20950 400 
	1    0    0    -1  
$EndComp
Text GLabel 18650 1750 2    50   Input ~ 0
BUCK_BST
$Comp
L Power_Protection:USBLC6-2SC6 U?
U 1 1 611618C7
P 18100 -2700
F 0 "U?" H 18100 -2119 50  0000 C CNN
F 1 "USBLC6-2SC6" H 18100 -2210 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 18100 -3200 50  0001 C CNN
F 3 "https://www.st.com/resource/en/datasheet/usblc6-2.pdf" H 18300 -2350 50  0001 C CNN
	1    18100 -2700
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky_Small D?
U 1 1 61175200
P 13700 1050
F 0 "D?" V 13746 980 50  0000 R CNN
F 1 "B5819W" V 13655 980 50  0000 R CNN
F 2 "" V 13700 1050 50  0001 C CNN
F 3 "~" V 13700 1050 50  0001 C CNN
	1    13700 1050
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 611795AA
P 13700 850
F 0 "#PWR?" H 13700 700 50  0001 C CNN
F 1 "+5V" H 13715 1023 50  0000 C CNN
F 2 "" H 13700 850 50  0001 C CNN
F 3 "" H 13700 850 50  0001 C CNN
	1    13700 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	13700 850  13700 950 
Wire Wire Line
	13700 1150 13700 1600
Wire Wire Line
	14800 1600 15150 1600
$Comp
L Device:D_Schottky_Small D?
U 1 1 6119B256
P 13200 1050
F 0 "D?" V 13246 980 50  0000 R CNN
F 1 "B5819W" V 13155 980 50  0000 R CNN
F 2 "" V 13200 1050 50  0001 C CNN
F 3 "~" V 13200 1050 50  0001 C CNN
	1    13200 1050
	0    -1   -1   0   
$EndComp
$Comp
L power:+9V #PWR?
U 1 1 60F30A17
P 13200 850
F 0 "#PWR?" H 13200 700 50  0001 C CNN
F 1 "+9V" H 13215 1023 50  0000 C CNN
F 2 "" H 13200 850 50  0001 C CNN
F 3 "" H 13200 850 50  0001 C CNN
	1    13200 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	13200 850  13200 950 
Wire Wire Line
	13200 1150 13200 1600
Wire Wire Line
	14200 1600 14600 1600
Wire Wire Line
	13200 1600 13700 1600
Connection ~ 13700 1600
Text GLabel 16000 3200 2    50   Input ~ 0
BUCK_IN
Wire Wire Line
	16000 3200 15200 3200
Wire Wire Line
	15200 3200 15200 3800
$Comp
L Connector:Screw_Terminal_01x02 J?
U 1 1 60D8248A
P 13400 -300
F 0 "J?" H 13480 -308 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 13480 -399 50  0000 L CNN
F 2 "" H 13400 -300 50  0001 C CNN
F 3 "~" H 13400 -300 50  0001 C CNN
	1    13400 -300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60D91ACB
P 13200 -100
F 0 "#PWR?" H 13200 -350 50  0001 C CNN
F 1 "GND" H 13205 -273 50  0000 C CNN
F 2 "" H 13200 -100 50  0001 C CNN
F 3 "" H 13200 -100 50  0001 C CNN
	1    13200 -100
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR?
U 1 1 60D92452
P 13200 -400
F 0 "#PWR?" H 13200 -550 50  0001 C CNN
F 1 "+9V" H 13215 -227 50  0000 C CNN
F 2 "" H 13200 -400 50  0001 C CNN
F 3 "" H 13200 -400 50  0001 C CNN
	1    13200 -400
	1    0    0    -1  
$EndComp
Wire Wire Line
	13200 -400 13200 -300
Wire Wire Line
	13200 -200 13200 -100
$Comp
L power:+3V3 #PWR?
U 1 1 60DA51CE
P 750 -1050
F 0 "#PWR?" H 750 -1200 50  0001 C CNN
F 1 "+3V3" H 765 -877 50  0000 C CNN
F 2 "" H 750 -1050 50  0001 C CNN
F 3 "" H 750 -1050 50  0001 C CNN
	1    750  -1050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60DA9156
P 750 -450
F 0 "#PWR?" H 750 -700 50  0001 C CNN
F 1 "GND" H 755 -623 50  0000 C CNN
F 2 "" H 750 -450 50  0001 C CNN
F 3 "" H 750 -450 50  0001 C CNN
	1    750  -450
	1    0    0    -1  
$EndComp
Wire Wire Line
	750  -950 750  -1050
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J?
U 1 1 60D9CA3C
P 1250 -750
F 0 "J?" H 1300 -333 50  0000 C CNN
F 1 "Conn_02x05_Odd_Even" H 1300 -424 50  0000 C CNN
F 2 "" H 1250 -750 50  0001 C CNN
F 3 "~" H 1250 -750 50  0001 C CNN
	1    1250 -750
	1    0    0    -1  
$EndComp
NoConn ~ 1050 -650
Wire Wire Line
	750  -850 750  -750
Wire Wire Line
	1050 -950 750  -950
Wire Wire Line
	1050 -850 750  -850
Wire Wire Line
	1050 -750 750  -750
Connection ~ 750  -750
Wire Wire Line
	750  -750 750  -550
Wire Wire Line
	750  -550 1050 -550
Connection ~ 750  -550
Wire Wire Line
	750  -550 750  -450
Text GLabel 1550 -950 2    50   Input ~ 0
SWDIO
Text GLabel 1550 -850 2    50   Input ~ 0
SWCLK
Text GLabel 1550 -750 2    50   Input ~ 0
SWO
NoConn ~ 1550 -650
Text GLabel 1550 -550 2    50   Input ~ 0
NRST
Wire Notes Line
	500  -1550 500  -100
Wire Notes Line
	500  -100 2000 -100
Wire Notes Line
	2000 -100 2000 -1550
Wire Notes Line
	2000 -1550 500  -1550
Text GLabel 5800 4200 2    50   Input ~ 0
I2C1_SCL
Text GLabel 5800 4100 2    50   Input ~ 0
I2C1_SDA
$Comp
L Regulator_Linear:MAX604 U?
U 1 1 60DEFDA8
P 22050 -2050
F 0 "U?" H 22050 -1708 50  0000 C CNN
F 1 "MAX604" H 22050 -1799 50  0000 C CNN
F 2 "" H 22050 -1725 50  0001 C CIN
F 3 "http://datasheets.maximintegrated.com/en/ds/MAX603-MAX604.pdf" H 22050 -2100 50  0001 C CNN
	1    22050 -2050
	1    0    0    -1  
$EndComp
$EndSCHEMATC
