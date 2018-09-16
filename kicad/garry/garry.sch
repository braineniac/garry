EESchema Schematic File Version 4
LIBS:garry-cache
EELAYER 26 0
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
$Comp
L Motor:Motor_Servo M?
U 1 1 5B9C020B
P 9400 4100
F 0 "M?" H 9731 4165 50  0000 L CNN
F 1 "Motor_Servo" H 9731 4074 50  0000 L CNN
F 2 "" H 9400 3910 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 9400 3910 50  0001 C CNN
	1    9400 4100
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_Servo M?
U 1 1 5B9C0385
P 9400 3250
F 0 "M?" H 9731 3315 50  0000 L CNN
F 1 "Motor_Servo" H 9731 3224 50  0000 L CNN
F 2 "" H 9400 3060 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 9400 3060 50  0001 C CNN
	1    9400 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery BT?
U 1 1 5B9C04F9
P 7650 5850
F 0 "BT?" H 7758 5896 50  0000 L CNN
F 1 "Battery" H 7758 5805 50  0000 L CNN
F 2 "" V 7650 5910 50  0001 C CNN
F 3 "~" V 7650 5910 50  0001 C CNN
	1    7650 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery BT?
U 1 1 5B9C05E7
P 8350 5850
F 0 "BT?" H 8458 5896 50  0000 L CNN
F 1 "Battery" H 8458 5805 50  0000 L CNN
F 2 "" V 8350 5910 50  0001 C CNN
F 3 "~" V 8350 5910 50  0001 C CNN
	1    8350 5850
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L7805 U?
U 1 1 5B9C09E7
P 8350 5050
F 0 "U?" V 8304 5155 50  0000 L CNN
F 1 "L7805" V 8395 5155 50  0000 L CNN
F 2 "" H 8375 4900 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 8350 5000 50  0001 C CNN
	1    8350 5050
	0    1    1    0   
$EndComp
$Comp
L Regulator_Linear:L7805 U?
U 1 1 5B9C0A83
P 7650 5050
F 0 "U?" H 7650 5292 50  0000 C CNN
F 1 "L7805" H 7650 5201 50  0000 C CNN
F 2 "" H 7675 4900 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 7650 5000 50  0001 C CNN
	1    7650 5050
	0    -1   -1   0   
$EndComp
$Comp
L Motor:Motor_DC M?
U 1 1 5B9C0D98
P 6250 2200
F 0 "M?" H 6408 2196 50  0000 L CNN
F 1 "Motor_DC" H 6408 2105 50  0000 L CNN
F 2 "" H 6250 2110 50  0001 C CNN
F 3 "~" H 6250 2110 50  0001 C CNN
	1    6250 2200
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC M?
U 1 1 5B9C0E96
P 6250 3000
F 0 "M?" H 6408 2996 50  0000 L CNN
F 1 "Motor_DC" H 6408 2905 50  0000 L CNN
F 2 "" H 6250 2910 50  0001 C CNN
F 3 "~" H 6250 2910 50  0001 C CNN
	1    6250 3000
	1    0    0    -1  
$EndComp
$Comp
L UNO_MOTOR_SHIELD:Arduino_Uno_Shield XA?
U 1 1 5B9C3F70
P 2900 2500
F 0 "XA?" H 2900 3887 60  0000 C CNN
F 1 "Arduino_Uno_Shield" H 2900 3781 60  0000 C CNN
F 2 "" H 4700 6250 60  0001 C CNN
F 3 "https://store.arduino.cc/arduino-uno-rev3" H 4700 6250 60  0001 C CNN
	1    2900 2500
	0    -1   -1   0   
$EndComp
NoConn ~ 2950 1200
NoConn ~ 2850 1200
NoConn ~ 2750 1200
NoConn ~ 2550 1200
NoConn ~ 2450 1200
NoConn ~ 3250 1200
NoConn ~ 3150 1200
NoConn ~ 3350 1200
$Comp
L Connector:Raspberry_Pi_2_3 J?
U 1 1 5B9C47E4
P 2850 5500
F 0 "J?" H 2850 6978 50  0000 C CNN
F 1 "Raspberry_Pi_2_3" H 2850 6887 50  0000 C CNN
F 2 "" H 2850 5500 50  0001 C CNN
F 3 "https://www.raspberrypi.org/documentation/hardware/raspberrypi/schematics/rpi_SCH_3bplus_1p0_reduced.pdf" H 2850 5500 50  0001 C CNN
	1    2850 5500
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5B9C5C4C
P 8000 6050
F 0 "#PWR?" H 8000 5800 50  0001 C CNN
F 1 "GND" H 8005 5877 50  0000 C CNN
F 2 "" H 8000 6050 50  0001 C CNN
F 3 "" H 8000 6050 50  0001 C CNN
	1    8000 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8350 6050 8000 6050
Wire Wire Line
	8000 6050 7650 6050
Connection ~ 8000 6050
Wire Wire Line
	7650 5650 7650 5350
Wire Wire Line
	8350 5350 8350 5650
Wire Wire Line
	8000 6050 8000 5050
Wire Wire Line
	8000 5050 8050 5050
Wire Wire Line
	7950 5050 8000 5050
Connection ~ 8000 5050
Wire Wire Line
	8350 4750 8350 4100
Connection ~ 8350 4100
Wire Wire Line
	8350 4100 8350 3250
Wire Wire Line
	8350 3250 9100 3250
Wire Wire Line
	9100 4100 8350 4100
Wire Wire Line
	3350 6300 3350 6550
Wire Wire Line
	3350 6550 1200 6550
Wire Wire Line
	3450 6300 3450 6750
Wire Wire Line
	3450 6750 1100 6750
Wire Wire Line
	4550 2400 5600 2400
Wire Wire Line
	5600 2400 5600 1850
Wire Wire Line
	5600 1850 6250 1850
Wire Wire Line
	6250 1850 6250 2000
Wire Wire Line
	4550 2550 6250 2550
Wire Wire Line
	6250 2550 6250 2500
Wire Wire Line
	6250 2800 6250 2700
Wire Wire Line
	6250 2700 4550 2700
Wire Wire Line
	6250 3300 5350 3300
Wire Wire Line
	5350 3300 5350 2850
Wire Wire Line
	5350 2850 4550 2850
Wire Wire Line
	8000 1650 5100 1650
Wire Wire Line
	5100 1650 5100 2200
Wire Wire Line
	5100 2200 4550 2200
Wire Wire Line
	8000 1650 8000 3350
Wire Wire Line
	9100 4200 8000 4200
Connection ~ 8000 4200
Wire Wire Line
	8000 4200 8000 5050
Wire Wire Line
	9100 3350 8000 3350
Connection ~ 8000 3350
Wire Wire Line
	8000 3350 8000 4200
Wire Wire Line
	4550 2300 5400 2300
Wire Wire Line
	5400 2300 5400 1750
Wire Wire Line
	5400 1750 7600 1750
Wire Wire Line
	7600 1750 7600 4100
Wire Wire Line
	7600 4100 8350 4100
Wire Wire Line
	4150 5400 6600 5400
Wire Wire Line
	6600 5400 6600 4500
Wire Wire Line
	6600 4500 7650 4500
Wire Wire Line
	7650 4500 7650 4750
Wire Wire Line
	8000 4200 3450 4200
Wire Wire Line
	3450 4200 3450 3800
Connection ~ 6600 4500
Wire Wire Line
	1200 6550 1200 3900
Wire Wire Line
	1200 3900 2150 3900
Wire Wire Line
	2150 3900 2150 3800
Wire Wire Line
	1100 6750 1100 3950
Wire Wire Line
	1100 3950 2250 3950
Wire Wire Line
	2250 3950 2250 3800
Wire Wire Line
	1550 5100 1550 4200
Wire Wire Line
	1550 4200 3450 4200
Connection ~ 3450 4200
Wire Wire Line
	9100 3150 8600 3150
Wire Wire Line
	8600 3150 8600 850 
Wire Wire Line
	8600 850  2150 850 
Wire Wire Line
	2150 850  2150 1200
Wire Wire Line
	2250 1200 2250 950 
Wire Wire Line
	2250 950  8500 950 
Wire Wire Line
	8500 950  8500 4000
Wire Wire Line
	8500 4000 9100 4000
Wire Wire Line
	3850 3800 3850 4500
Wire Wire Line
	3850 4500 6600 4500
$EndSCHEMATC
