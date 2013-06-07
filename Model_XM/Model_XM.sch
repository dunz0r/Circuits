EESchema Schematic File Version 2  date tor 28 mar 2013 21:42:47
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Model_XM-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Model XM USB controller"
Date "28 mar 2013"
Rev "0.1"
Comp "Hackoteket"
Comment1 "Gabriel Fornaeus"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATMEGA32-P IC?
U 1 1 5154A076
P 3800 3900
F 0 "IC?" H 3000 5730 50  0000 L BNN
F 1 "ATMEGA32-P" H 4100 2000 50  0000 L BNN
F 2 "DIL40" H 3100 2050 50  0001 C CNN
F 3 "" H 3800 3900 60  0000 C CNN
	1    3800 3900
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X?
U 1 1 5154A20D
P 2300 2900
F 0 "X?" H 2300 3050 60  0000 C CNN
F 1 "CRYSTAL" H 2300 2750 60  0000 C CNN
F 2 "" H 2300 2900 60  0000 C CNN
F 3 "" H 2300 2900 60  0000 C CNN
	1    2300 2900
	0    -1   -1   0   
$EndComp
$Comp
L C C?
U 1 1 5154A21C
P 1750 2600
F 0 "C?" H 1800 2700 50  0000 L CNN
F 1 "C" H 1800 2500 50  0000 L CNN
F 2 "" H 1750 2600 60  0000 C CNN
F 3 "" H 1750 2600 60  0000 C CNN
	1    1750 2600
	0    -1   -1   0   
$EndComp
$Comp
L C C?
U 1 1 5154A229
P 1750 3200
F 0 "C?" H 1800 3300 50  0000 L CNN
F 1 "C" H 1800 3100 50  0000 L CNN
F 2 "" H 1750 3200 60  0000 C CNN
F 3 "" H 1750 3200 60  0000 C CNN
	1    1750 3200
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5154A25E
P 1300 3300
F 0 "#PWR?" H 1300 3300 30  0001 C CNN
F 1 "GND" H 1300 3230 30  0001 C CNN
F 2 "" H 1300 3300 60  0000 C CNN
F 3 "" H 1300 3300 60  0000 C CNN
	1    1300 3300
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5154A321
P 2050 2200
F 0 "R?" V 2130 2200 50  0000 C CNN
F 1 "10k" V 2050 2200 50  0000 C CNN
F 2 "" H 2050 2200 60  0000 C CNN
F 3 "" H 2050 2200 60  0000 C CNN
	1    2050 2200
	0    -1   -1   0   
$EndComp
Text Label 2400 2200 0    60   ~ 0
Reset
$Comp
L VCC #PWR?
U 1 1 5154A341
P 1500 2000
F 0 "#PWR?" H 1500 2100 30  0001 C CNN
F 1 "VCC" H 1500 2100 30  0000 C CNN
F 2 "" H 1500 2000 60  0000 C CNN
F 3 "" H 1500 2000 60  0000 C CNN
	1    1500 2000
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 5154A35B
P 3650 1750
F 0 "#PWR?" H 3650 1850 30  0001 C CNN
F 1 "VCC" H 3650 1850 30  0000 C CNN
F 2 "" H 3650 1750 60  0000 C CNN
F 3 "" H 3650 1750 60  0000 C CNN
	1    3650 1750
	1    0    0    -1  
$EndComp
NoConn ~ 3950 1900
$Comp
L C C?
U 1 1 5154A370
P 3450 1800
F 0 "C?" H 3500 1900 50  0000 L CNN
F 1 "C" H 3500 1700 50  0000 L CNN
F 2 "" H 3450 1800 60  0000 C CNN
F 3 "" H 3450 1800 60  0000 C CNN
	1    3450 1800
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5154A378
P 3250 1900
F 0 "#PWR?" H 3250 1900 30  0001 C CNN
F 1 "GND" H 3250 1830 30  0001 C CNN
F 2 "" H 3250 1900 60  0000 C CNN
F 3 "" H 3250 1900 60  0000 C CNN
	1    3250 1900
	1    0    0    -1  
$EndComp
$Comp
L CONN_20 P?
U 1 1 5154A398
P 5800 3750
F 0 "P?" V 5750 3750 60  0000 C CNN
F 1 "Rows" V 5850 3750 60  0000 C CNN
F 2 "" H 5800 3750 60  0000 C CNN
F 3 "" H 5800 3750 60  0000 C CNN
	1    5800 3750
	1    0    0    -1  
$EndComp
Text Notes 6150 4050 1    60   ~ 0
Keyboard rows
$Comp
L CONN_8 P?
U 1 1 5154A3AC
P 5850 5250
F 0 "P?" V 5800 5250 60  0000 C CNN
F 1 "Columns" V 5900 5250 60  0000 C CNN
F 2 "" H 5850 5250 60  0000 C CNN
F 3 "" H 5850 5250 60  0000 C CNN
	1    5850 5250
	1    0    0    -1  
$EndComp
Text Notes 6200 5650 1    60   ~ 0
Keyboard columns
NoConn ~ 3850 5900
$Comp
L GND #PWR?
U 1 1 5154A924
P 3750 6150
F 0 "#PWR?" H 3750 6150 30  0001 C CNN
F 1 "GND" H 3750 6080 30  0001 C CNN
F 2 "" H 3750 6150 60  0000 C CNN
F 3 "" H 3750 6150 60  0000 C CNN
	1    3750 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 3300 1300 3200
Wire Wire Line
	1300 3200 1550 3200
Wire Wire Line
	1550 2600 1450 2600
Wire Wire Line
	1450 2600 1450 3200
Connection ~ 1450 3200
Wire Wire Line
	1950 2600 2800 2600
Connection ~ 2300 2600
Wire Wire Line
	1950 3200 2550 3200
Wire Wire Line
	2800 3000 2550 3000
Wire Wire Line
	2550 3000 2550 3200
Connection ~ 2300 3200
Wire Wire Line
	2300 2200 2800 2200
Wire Wire Line
	1500 2000 1500 2200
Wire Wire Line
	1500 2200 1800 2200
Wire Wire Line
	3650 1750 3650 1900
Connection ~ 3650 1800
Wire Wire Line
	3250 1800 3250 1900
Wire Wire Line
	4800 5100 5500 5100
Wire Wire Line
	4800 5200 5500 5200
Wire Wire Line
	5500 5300 4800 5300
Wire Wire Line
	4800 5400 5500 5400
Wire Wire Line
	5500 5500 4800 5500
Wire Wire Line
	4800 5600 5500 5600
Wire Wire Line
	4800 4700 5450 4700
Wire Wire Line
	5450 4600 4800 4600
Wire Wire Line
	4800 4500 5450 4500
Wire Wire Line
	5450 4400 4800 4400
Wire Wire Line
	4800 4300 5450 4300
Wire Wire Line
	5450 4200 4800 4200
Wire Wire Line
	4800 4100 5450 4100
Wire Wire Line
	5450 4000 4800 4000
Wire Wire Line
	4800 3800 4800 3900
Wire Wire Line
	4800 3900 5450 3900
Wire Wire Line
	5450 3800 4900 3800
Wire Wire Line
	4900 3800 4900 3700
Wire Wire Line
	4900 3700 4800 3700
Wire Wire Line
	4800 3600 4950 3600
Wire Wire Line
	4950 3600 4950 3700
Wire Wire Line
	4950 3700 5450 3700
Wire Wire Line
	5450 3600 5000 3600
Wire Wire Line
	5000 3600 5000 3500
Wire Wire Line
	5000 3500 4800 3500
Wire Wire Line
	4800 3400 5100 3400
Wire Wire Line
	5100 3400 5100 3500
Wire Wire Line
	5100 3500 5450 3500
Wire Wire Line
	5450 3400 5150 3400
Wire Wire Line
	5150 3400 5150 3300
Wire Wire Line
	5150 3300 4800 3300
Wire Wire Line
	4800 3200 5200 3200
Wire Wire Line
	5200 3200 5200 3300
Wire Wire Line
	5200 3300 5450 3300
Wire Wire Line
	5450 3200 5300 3200
Wire Wire Line
	5300 3200 5300 3100
Wire Wire Line
	5300 3100 4800 3100
Wire Wire Line
	5450 3100 5350 3100
Wire Wire Line
	5350 3100 5350 3000
Wire Wire Line
	5350 3000 4800 3000
Wire Wire Line
	4800 3000 4800 2900
Wire Wire Line
	4800 2800 5400 2800
Wire Wire Line
	5400 2800 5400 3000
Wire Wire Line
	5400 3000 5450 3000
Wire Wire Line
	5450 2900 4900 2900
Wire Wire Line
	4900 2900 4900 2700
Wire Wire Line
	4900 2700 4800 2700
Wire Wire Line
	5450 2800 5450 2600
Wire Wire Line
	5450 2600 4800 2600
Wire Wire Line
	4800 4900 5500 4900
Wire Wire Line
	4800 5000 5500 5000
Wire Wire Line
	3750 6150 3750 5900
$Comp
L 74HC595 U?
U 1 1 5154AA5F
P 6600 2000
F 0 "U?" H 6750 2600 70  0000 C CNN
F 1 "74HC595" H 6600 1400 70  0000 C CNN
F 2 "" H 6600 2000 60  0000 C CNN
F 3 "" H 6600 2000 60  0000 C CNN
	1    6600 2000
	1    0    0    -1  
$EndComp
$Comp
L CONN_17 P?
U 1 1 5154ABAB
P 8350 2400
F 0 "P?" V 8310 2400 60  0000 C CNN
F 1 "Lcd connector" V 8430 2400 60  0000 C CNN
F 2 "" H 8350 2400 60  0000 C CNN
F 3 "" H 8350 2400 60  0000 C CNN
	1    8350 2400
	1    0    0    -1  
$EndComp
Text Notes 8700 2900 1    60   ~ 0
16x2 HD44780 LCD
Wire Wire Line
	5900 1550 4950 1550
Wire Wire Line
	4950 1550 4950 2200
Wire Wire Line
	4950 2200 4800 2200
Wire Wire Line
	5100 2050 5900 2050
Wire Wire Line
	5100 1750 5900 1750
Wire Wire Line
	5100 1750 5100 2300
Wire Wire Line
	5100 2300 4800 2300
Wire Wire Line
	5900 2150 5900 2350
$Comp
L GND #PWR?
U 1 1 5154AD3E
P 5900 2350
F 0 "#PWR?" H 5900 2350 30  0001 C CNN
F 1 "GND" H 5900 2280 30  0001 C CNN
F 2 "" H 5900 2350 60  0000 C CNN
F 3 "" H 5900 2350 60  0000 C CNN
	1    5900 2350
	1    0    0    -1  
$EndComp
Connection ~ 5100 2050
Wire Wire Line
	5900 1850 5850 1850
Wire Wire Line
	5850 1850 5850 2000
Wire Wire Line
	5850 2000 5650 2000
Wire Wire Line
	5650 2000 5650 1950
$Comp
L VCC #PWR?
U 1 1 5154AE8C
P 5650 1950
F 0 "#PWR?" H 5650 2050 30  0001 C CNN
F 1 "VCC" H 5650 2050 30  0000 C CNN
F 2 "" H 5650 1950 60  0000 C CNN
F 3 "" H 5650 1950 60  0000 C CNN
	1    5650 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 1950 7550 1950
Wire Wire Line
	7700 1550 7700 2600
Wire Wire Line
	7700 1550 7300 1550
Wire Wire Line
	7300 1650 7600 1650
Wire Wire Line
	7600 1650 7600 2700
Wire Wire Line
	7550 1950 7550 1850
Wire Wire Line
	7750 1850 7750 1900
Wire Wire Line
	7550 1850 7750 1850
Wire Wire Line
	7750 1900 8000 1900
Wire Wire Line
	7700 2600 8000 2600
Wire Wire Line
	7600 2700 8000 2700
Wire Wire Line
	7300 1750 7500 1750
Wire Wire Line
	7500 1750 7500 2800
Wire Wire Line
	7500 2800 8000 2800
Wire Wire Line
	7300 1850 7400 1850
Wire Wire Line
	7400 1850 7400 2900
Wire Wire Line
	7400 2900 8000 2900
$Comp
L USB J?
U 1 1 5154B5F6
P 1300 6850
F 0 "J?" H 1250 7250 60  0000 C CNN
F 1 "USB" V 1050 7000 60  0000 C CNN
F 2 "" H 1300 6850 60  0000 C CNN
F 3 "" H 1300 6850 60  0000 C CNN
	1    1300 6850
	1    0    0    -1  
$EndComp
$EndSCHEMATC