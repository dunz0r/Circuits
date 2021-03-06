EESchema Schematic File Version 2  date Mon 19 Mar 2012 17:18:51 CET
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
LIBS:h-bridge-cache
EELAYER 25  0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "19 mar 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L OPTO-TRANSISTOR4 U1
U 1 1 4F6756EE
P 3500 1200
F 0 "U1" H 3700 1450 60  0000 C CNN
F 1 "OPTO-TRANSISTOR4" H 3500 950 60  0000 C CNN
	1    3500 1200
	1    0    0    -1  
$EndComp
$Comp
L OPTO-TRANSISTOR4 U2
U 1 1 4F675703
P 3550 1950
F 0 "U2" H 3750 2200 60  0000 C CNN
F 1 "OPTO-TRANSISTOR4" H 3550 1700 60  0000 C CNN
	1    3550 1950
	1    0    0    -1  
$EndComp
$Comp
L CONN_4 P1
U 1 1 4F675832
P 1700 1300
F 0 "P1" V 1650 1300 50  0000 C CNN
F 1 "CONN_4" V 1750 1300 50  0000 C CNN
	1    1700 1300
	-1   0    0    1   
$EndComp
$Comp
L R R2
U 1 1 4F675841
P 2650 2100
F 0 "R2" V 2730 2100 50  0000 C CNN
F 1 "100" V 2650 2100 50  0000 C CNN
	1    2650 2100
	0    -1   -1   0   
$EndComp
$Comp
L R R1
U 1 1 4F675858
P 2600 1350
F 0 "R1" V 2680 1350 50  0000 C CNN
F 1 "100" V 2600 1350 50  0000 C CNN
	1    2600 1350
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR01
U 1 1 4F6758BE
P 4150 1600
F 0 "#PWR01" H 4150 1600 30  0001 C CNN
F 1 "GND" H 4150 1530 30  0001 C CNN
	1    4150 1600
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 4F675A4E
P 4350 1050
F 0 "R4" V 4430 1050 50  0000 C CNN
F 1 "10K" V 4350 1050 50  0000 C CNN
	1    4350 1050
	0    -1   -1   0   
$EndComp
$Comp
L R R3
U 1 1 4F675A5D
P 4400 1800
F 0 "R3" V 4480 1800 50  0000 C CNN
F 1 "10k" V 4400 1800 50  0000 C CNN
	1    4400 1800
	0    1    1    0   
$EndComp
$Comp
L GND #PWR02
U 1 1 4F6758CD
P 3200 2150
F 0 "#PWR02" H 3200 2150 30  0001 C CNN
F 1 "GND" H 3200 2080 30  0001 C CNN
	1    3200 2150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 4F675BCE
P 2600 1700
F 0 "#PWR03" H 2600 1700 30  0001 C CNN
F 1 "GND" H 2600 1630 30  0001 C CNN
	1    2600 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 1050 4700 1050
Wire Wire Line
	4700 1800 4700 800 
Wire Wire Line
	4700 1800 4650 1800
Wire Wire Line
	4700 800  2050 800 
Wire Wire Line
	2050 800  2050 1150
Connection ~ 4700 1050
Wire Wire Line
	2050 1450 2350 1450
Wire Wire Line
	2350 1350 2350 2100
Wire Wire Line
	2350 2100 2400 2100
Connection ~ 2350 1450
Wire Wire Line
	2850 1050 2850 800 
Connection ~ 2850 800 
Wire Wire Line
	2900 1800 2900 1200
Wire Wire Line
	2900 1200 2700 1200
Wire Wire Line
	2700 1200 2700 800 
Connection ~ 2700 800 
Wire Wire Line
	2600 1700 2600 1650
Wire Wire Line
	2600 1650 2350 1650
Connection ~ 2350 1650
Wire Wire Line
	4100 1350 4150 1350
Wire Wire Line
	4150 1350 4150 1600
Wire Wire Line
	4150 2100 4150 1950
Wire Wire Line
	4150 1950 4000 1950
Wire Wire Line
	4000 1950 4000 1550
Wire Wire Line
	4000 1550 4150 1550
Connection ~ 4150 1550
Wire Wire Line
	2050 1250 3100 1250
Wire Wire Line
	3100 1250 3100 900 
Wire Wire Line
	3100 900  4100 900 
Wire Wire Line
	4100 900  4100 1050
Wire Wire Line
	2050 1350 2250 1350
Wire Wire Line
	2250 1350 2250 1600
Wire Wire Line
	2250 1600 3900 1600
Wire Wire Line
	3900 1600 3900 1750
Wire Wire Line
	3900 1750 4150 1750
Wire Wire Line
	4150 1750 4150 1800
Connection ~ 4150 2100
Connection ~ 4150 1800
$EndSCHEMATC
