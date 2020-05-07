/*
 * battery.c
 *
 *  Created on: May 6, 2020
 *      Author: adina
 */


#include "battery.h"

void batteryStatusChange(char batteryStatus)
{
    switch(batteryStatus)
        {
            case noLine:
                        LCDM12 = 0x10;
                        LCDM13 = 0x01;
                        break;
            case oneLine:
                        LCDM12 = 0x10;
                        LCDM13 = 0x03;
                        break;
            case twoLines:
                        LCDM12 = 0x30;
                        LCDM13 = 0x03;
                        break;
            case threeLines:
                        LCDM12 = 0x30;
                        LCDM13 = 0x07;
                        break;
            case fourLines:
                        LCDM12 = 0x70;
                        LCDM13 = 0x07;
                        break;
            case fiveLines:
                        LCDM12 = 0x70;
                        LCDM13 = 0x0F;
                        break;
            case sixLines:
                        LCDM12 = 0xF0;
                        LCDM13 = 0x0F;
                        break;
        }
}

