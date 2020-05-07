/*
 * battery.h
 *
 *  Created on: May 6, 2020
 *      Author: adina
 */

#include "driverlib.h"

#ifndef BATTERY_H_
#define BATTERY_H_

#define noLine        0
#define oneLine       1
#define twoLines      2
#define threeLines    3
#define fourLines     4
#define fiveLines     5
#define sixLines      6

void batteryStatusChange(char batteryStatus);

#endif /* BATTERY_H_ */
