EESchema Schematic File Version 2  date lör  8 feb 2014 00:26:17
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
LIBS:74xgxx
LIBS:DIY_stuff
LIBS:Visualizer-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "7 feb 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 6000 3000 0    60   ~ 0
SIG
Wire Wire Line
	6000 3250 6000 3000
Wire Wire Line
	5350 3300 4900 3300
Connection ~ 2150 3100
Wire Wire Line
	1800 3100 4350 3100
Wire Wire Line
	1800 3100 1800 3000
Wire Wire Line
	2300 4550 2300 4600
Wire Wire Line
	4350 3100 4350 3250
Wire Wire Line
	2150 3100 2150 4700
Wire Wire Line
	2150 4700 2700 4700
Wire Wire Line
	2700 4700 2700 4100
Connection ~ 4350 4000
Wire Wire Line
	4100 4000 4350 4000
Wire Wire Line
	4350 3800 4100 3800
Wire Wire Line
	2700 3850 2300 3850
Wire Wire Line
	2300 3850 2300 4150
Wire Wire Line
	4100 3600 4200 3600
Wire Wire Line
	4200 3600 4200 3300
Wire Wire Line
	4350 4050 4350 3750
Connection ~ 4350 3800
Wire Wire Line
	4200 4000 4200 4850
Connection ~ 4200 4000
Wire Wire Line
	4200 4850 2050 4850
Wire Wire Line
	2050 4850 2050 3600
Wire Wire Line
	2050 3600 2700 3600
Wire Wire Line
	4350 4550 4350 4700
Wire Wire Line
	4350 5200 4350 5100
Wire Wire Line
	5350 3400 5050 3400
Wire Wire Line
	5050 3400 5050 3500
Wire Wire Line
	6000 4250 6000 4400
$Comp
L GND #PWR?
U 1 1 52F56782
P 6000 4400
F 0 "#PWR?" H 6000 4400 30  0001 C CNN
F 1 "GND" H 6000 4330 30  0001 C CNN
	1    6000 4400
	1    0    0    -1  
$EndComp
Text Label 4900 3300 0    60   ~ 0
CLOCK
$Comp
L GND #PWR?
U 1 1 52F5671D
P 5050 3500
F 0 "#PWR?" H 5050 3500 30  0001 C CNN
F 1 "GND" H 5050 3430 30  0001 C CNN
	1    5050 3500
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 52F566DC
P 1800 3000
F 0 "#PWR?" H 1800 3090 20  0001 C CNN
F 1 "+5V" H 1800 3090 30  0000 C CNN
	1    1800 3000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 52F566BE
P 4350 5200
F 0 "#PWR?" H 4350 5200 30  0001 C CNN
F 1 "GND" H 4350 5130 30  0001 C CNN
	1    4350 5200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 52F566B8
P 2300 4600
F 0 "#PWR?" H 2300 4600 30  0001 C CNN
F 1 "GND" H 2300 4530 30  0001 C CNN
	1    2300 4600
	1    0    0    -1  
$EndComp
Text Label 4200 3300 2    60   ~ 0
CLOCK
$Comp
L C C?
U 1 1 52F56629
P 4350 4900
F 0 "C?" H 4400 5000 50  0000 L CNN
F 1 "10nF" H 4400 4800 50  0000 L CNN
	1    4350 4900
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 52F56601
P 4350 4300
F 0 "R?" V 4430 4300 50  0000 C CNN
F 1 "220" V 4350 4300 50  0000 C CNN
	1    4350 4300
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 52F565C4
P 4350 3500
F 0 "R?" V 4430 3500 50  0000 C CNN
F 1 "300" V 4350 3500 50  0000 C CNN
	1    4350 3500
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 52F565A9
P 2300 4350
F 0 "C?" H 2350 4450 50  0000 L CNN
F 1 "0.01uF" H 2350 4250 50  0000 L CNN
	1    2300 4350
	1    0    0    -1  
$EndComp
$Comp
L 4022 U?
U 1 1 52F56462
P 6000 3750
F 0 "U?" H 6000 4300 60  0000 C CNN
F 1 "4022" H 6000 3200 60  0000 C CNN
	1    6000 3750
	1    0    0    -1  
$EndComp
$Comp
L LM555N U?
U 1 1 52F5644E
P 3400 3800
F 0 "U?" H 3400 3900 70  0000 C CNN
F 1 "LM555N" H 3400 3700 70  0000 C CNN
	1    3400 3800
	1    0    0    -1  
$EndComp
$EndSCHEMATC
