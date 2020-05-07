/*
 * main.h
 *
 *  Created on: Apr 30, 2020
 *      Author: adina
 */


#ifndef MAIN_H_
#define MAIN_H_

#include "driverlib.h"

//D E F I N E  V A R I A B L E S
    unsigned int count = 0;
    unsigned int batteryStatus = 0;
    unsigned char S1buttonDebounce = 0;
    unsigned char S2buttonDebounce = 0;
    char switchCases = 0;
    int i = 0;
    int countName = 2; // How many times do you want to see your Name?


extern Timer_A_initUpModeParam initUpParam_A0;

// D E F I N E   C A S E S
#define InitialMode     0
#define TextMode        1
#define BatteryMode     2
#define BatterySwitch   3

void Init_GPIO();
void Init_Clock();
void Init_RTC();

#endif /* MAIN_H_ */
