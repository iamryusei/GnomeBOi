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
Wire Wire Line
	1850 600  3750 600 
Connection ~ 3750 600 
Wire Wire Line
	3750 600  4500 600 
Connection ~ 4500 600 
Wire Wire Line
	4500 600  5200 600 
Connection ~ 5200 600 
Wire Wire Line
	5200 600  5900 600 
Connection ~ 3000 1950
Wire Wire Line
	3000 4050 3000 1950
$Comp
L Device:R_Small_US R1
U 1 1 5F3549C3
P 3000 4150
F 0 "R1" H 3068 4196 50  0000 L CNN
F 1 "R_Small_US" H 3068 4105 50  0000 L CNN
F 2 "Resistor_THT:R_Box_L8.4mm_W2.5mm_P5.08mm" H 3000 4150 50  0001 C CNN
F 3 "~" H 3000 4150 50  0001 C CNN
	1    3000 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 1950 3000 1950
Wire Wire Line
	4100 2050 4100 1950
Wire Wire Line
	5900 1950 5900 600 
$Comp
L Switch:SW_Push_Dual_x2 SW2
U 2 1 5F4300F0
P 5700 1950
F 0 "SW2" H 5700 2235 50  0000 C CNN
F 1 "SW_Push_Dual_x2" H 5700 2144 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 5700 2150 50  0001 C CNN
F 3 "~" H 5700 2150 50  0001 C CNN
	2    5700 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 2250 5500 1950
Wire Wire Line
	5200 1950 5200 600 
$Comp
L Switch:SW_Push_Dual_x2 SW2
U 1 1 5F4300E4
P 5000 1950
F 0 "SW2" H 5000 2235 50  0000 C CNN
F 1 "SW_Push_Dual_x2" H 5000 2144 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 5000 2150 50  0001 C CNN
F 3 "~" H 5000 2150 50  0001 C CNN
	1    5000 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 1950 4500 600 
$Comp
L Switch:SW_Push_Dual_x2 SW1
U 1 1 5F42F260
P 4300 1950
F 0 "SW1" H 4300 2235 50  0000 C CNN
F 1 "SW_Push_Dual_x2" H 4300 2144 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 4300 2150 50  0001 C CNN
F 3 "~" H 4300 2150 50  0001 C CNN
	1    4300 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 1950 3750 600 
$Comp
L Switch:SW_Push_Dual_x2 SW1
U 2 1 5F34E379
P 3550 1950
F 0 "SW1" H 3550 2235 50  0000 C CNN
F 1 "SW_Push_Dual_x2" H 3550 2144 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 3550 2150 50  0001 C CNN
F 3 "~" H 3550 2150 50  0001 C CNN
	2    3550 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 1950 4800 2150
Wire Wire Line
	3600 4400 3600 4250
$Comp
L Device:R_Small_US R2
U 1 1 5F459518
P 3600 4150
F 0 "R2" H 3668 4196 50  0000 L CNN
F 1 "R_Small_US" H 3668 4105 50  0000 L CNN
F 2 "Resistor_THT:R_Box_L8.4mm_W2.5mm_P5.08mm" H 3600 4150 50  0001 C CNN
F 3 "~" H 3600 4150 50  0001 C CNN
	1    3600 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 4400 4200 4250
$Comp
L Device:R_Small_US R3
U 1 1 5F459E52
P 4200 4150
F 0 "R3" H 4268 4196 50  0000 L CNN
F 1 "R_Small_US" H 4268 4105 50  0000 L CNN
F 2 "Resistor_THT:R_Box_L8.4mm_W2.5mm_P5.08mm" H 4200 4150 50  0001 C CNN
F 3 "~" H 4200 4150 50  0001 C CNN
	1    4200 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R4
U 1 1 5F459E5E
P 4800 4150
F 0 "R4" H 4868 4196 50  0000 L CNN
F 1 "R_Small_US" H 4868 4105 50  0000 L CNN
F 2 "Resistor_THT:R_Box_L8.4mm_W2.5mm_P5.08mm" H 4800 4150 50  0001 C CNN
F 3 "~" H 4800 4150 50  0001 C CNN
	1    4800 4150
	1    0    0    -1  
$EndComp
Connection ~ 3600 4400
Wire Wire Line
	3600 4400 4200 4400
Wire Wire Line
	4800 4400 4800 4250
Wire Wire Line
	3600 4050 3600 2050
Connection ~ 3600 2050
Wire Wire Line
	3600 2050 4100 2050
Wire Wire Line
	4200 4050 4200 2150
Connection ~ 4200 2150
Wire Wire Line
	4200 2150 4800 2150
Wire Wire Line
	4800 4050 4800 2250
Connection ~ 4800 2250
Wire Wire Line
	4800 2250 5500 2250
Wire Wire Line
	4800 4400 4200 4400
Connection ~ 4200 4400
$Comp
L Switch:SW_Push_Dual_x2 SW4
U 2 1 5F479DCE
P 8600 1950
F 0 "SW4" H 8600 2235 50  0000 C CNN
F 1 "SW_Push_Dual_x2" H 8600 2144 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 8600 2150 50  0001 C CNN
F 3 "~" H 8600 2150 50  0001 C CNN
	2    8600 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 1950 8800 600 
Wire Wire Line
	8100 1950 8100 600 
Wire Wire Line
	7400 1950 7400 600 
Wire Wire Line
	6650 1950 6650 600 
Wire Wire Line
	5900 600  6650 600 
Connection ~ 5900 600 
Connection ~ 6650 600 
Wire Wire Line
	6650 600  7400 600 
Connection ~ 7400 600 
Wire Wire Line
	7400 600  8100 600 
Connection ~ 8100 600 
Wire Wire Line
	8100 600  8800 600 
$Comp
L Switch:SW_Push_Dual_x2 SW3
U 2 1 5F479DE5
P 7200 1950
F 0 "SW3" H 7200 2235 50  0000 C CNN
F 1 "SW_Push_Dual_x2" H 7200 2144 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 7200 2150 50  0001 C CNN
F 3 "~" H 7200 2150 50  0001 C CNN
	2    7200 1950
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_Dual_x2 SW4
U 1 1 5F479DDA
P 7900 1950
F 0 "SW4" H 7900 2235 50  0000 C CNN
F 1 "SW_Push_Dual_x2" H 7900 2144 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 7900 2150 50  0001 C CNN
F 3 "~" H 7900 2150 50  0001 C CNN
	1    7900 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 3150 6250 1950
$Comp
L Switch:SW_Push_Dual_x2 SW3
U 1 1 5F479DF0
P 6450 1950
F 0 "SW3" H 6450 2235 50  0000 C CNN
F 1 "SW_Push_Dual_x2" H 6450 2144 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 6450 2150 50  0001 C CNN
F 3 "~" H 6450 2150 50  0001 C CNN
	1    6450 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 1950 7000 3250
Wire Wire Line
	7700 1950 7700 3350
Wire Wire Line
	8400 1950 8400 3450
Wire Wire Line
	1850 600  1850 750 
Wire Wire Line
	2450 3150 5400 3150
Wire Wire Line
	2450 2250 4800 2250
Wire Wire Line
	2450 2150 4200 2150
Wire Wire Line
	2450 2050 3600 2050
Wire Wire Line
	3000 1950 2450 1950
Wire Wire Line
	2450 3350 6600 3350
Wire Wire Line
	2450 3250 6000 3250
Wire Wire Line
	3000 4400 3600 4400
Wire Wire Line
	3000 4400 3000 4250
Connection ~ 3000 4400
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U1
U 1 1 5F37103E
P 1850 2250
F 0 "U1" H 1206 2296 50  0000 R CNN
F 1 "ATmega328P-PU" H 1206 2205 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 1850 2250 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 1850 2250 50  0001 C CNN
	1    1850 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 4400 6600 4250
$Comp
L Device:R_Small_US R7
U 1 1 5F4B1528
P 6600 4150
F 0 "R7" H 6668 4196 50  0000 L CNN
F 1 "R_Small_US" H 6668 4105 50  0000 L CNN
F 2 "Resistor_THT:R_Box_L8.4mm_W2.5mm_P5.08mm" H 6600 4150 50  0001 C CNN
F 3 "~" H 6600 4150 50  0001 C CNN
	1    6600 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R8
U 1 1 5F4B1532
P 7200 4150
F 0 "R8" H 7268 4196 50  0000 L CNN
F 1 "R_Small_US" H 7268 4105 50  0000 L CNN
F 2 "Resistor_THT:R_Box_L8.4mm_W2.5mm_P5.08mm" H 7200 4150 50  0001 C CNN
F 3 "~" H 7200 4150 50  0001 C CNN
	1    7200 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 4400 7200 4250
Wire Wire Line
	6000 4400 6000 4250
Wire Wire Line
	5400 4400 5400 4250
$Comp
L Device:R_Small_US R6
U 1 1 5F4B151D
P 6000 4150
F 0 "R6" H 6068 4196 50  0000 L CNN
F 1 "R_Small_US" H 6068 4105 50  0000 L CNN
F 2 "Resistor_THT:R_Box_L8.4mm_W2.5mm_P5.08mm" H 6000 4150 50  0001 C CNN
F 3 "~" H 6000 4150 50  0001 C CNN
	1    6000 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R5
U 1 1 5F4B1512
P 5400 4150
F 0 "R5" H 5468 4196 50  0000 L CNN
F 1 "R_Small_US" H 5468 4105 50  0000 L CNN
F 2 "Resistor_THT:R_Box_L8.4mm_W2.5mm_P5.08mm" H 5400 4150 50  0001 C CNN
F 3 "~" H 5400 4150 50  0001 C CNN
	1    5400 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 4400 5400 4400
Connection ~ 4800 4400
Connection ~ 5400 4400
Wire Wire Line
	5400 4400 6000 4400
Connection ~ 6000 4400
Wire Wire Line
	6000 4400 6600 4400
Connection ~ 6600 4400
Wire Wire Line
	6600 4400 7200 4400
Wire Wire Line
	5400 3150 5400 4050
Connection ~ 5400 3150
Wire Wire Line
	5400 3150 6250 3150
Wire Wire Line
	6000 3250 6000 4050
Connection ~ 6000 3250
Wire Wire Line
	2450 3450 7200 3450
Wire Wire Line
	6000 3250 7000 3250
Wire Wire Line
	6600 3350 6600 4050
Connection ~ 6600 3350
Wire Wire Line
	6600 3350 7700 3350
Wire Wire Line
	7200 3450 7200 4050
Connection ~ 7200 3450
Wire Wire Line
	7200 3450 8400 3450
Wire Wire Line
	1850 3750 1850 4400
Wire Wire Line
	1850 4400 3000 4400
$EndSCHEMATC
