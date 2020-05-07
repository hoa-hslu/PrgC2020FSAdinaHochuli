/*
 * main.c
 *
 *  Created on: Apr 30, 2020
 *      Author: adina
 */

#include <msp430.h>
//#include "driverlib.h"
#include "main.h"
#include "battery.h"


// TimerA0 UpMode Configuration Parameter
Timer_A_initUpModeParam initUpParam_A0 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK Clock Source
        TIMER_A_CLOCKSOURCE_DIVIDER_1,          // SMCLK/1 = 2MHz
        30000,                                  // 15ms debounce period
        TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
        TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
        TIMER_A_DO_CLEAR,                       // Clear value
        true                                    // Start Timer
};


/**
 * main.c
 */
int main(void)
{
    char switchCases = InitialMode;

//C A L L  C A S E S
    while(1)
    {
        switch(switchCases)
        {
        //CASE: InitialMode Stop Watchdog timer
        case InitialMode:
            WDT_A_hold(__MSP430_BASEADDRESS_WDT_A__);     // Stop WDT
            Init_GPIO();
            Init_LCD();
            switchCases = TextMode;
            break;
        //CASE: TextMode Show your Name
        case TextMode:
             while(i <= countName-1)
             {
                 displayScrollText("PRG_C ADINA HOCHULI");
                 ++i;
             }
            switchCases = BatteryMode;
            break;
        //CASE: Battery Mode
        case BatteryMode:
                LCDM12 = 0x10;
                LCDM13 = 0x01;
                switchCases = BatterySwitch;
                break;
        //CASE: Battery Switch, switch battery Level
        case BatterySwitch:
            // When button S1 is pressed the first time
                         if (!(P1IN & BIT2) && (S1buttonDebounce == 0))
                         {
                             P1OUT |= BIT0;            // turn on red LED
                             S1buttonDebounce = 1;
                             if (batteryStatus > 0)
                             {
                                 batteryStatus--;
                                 batteryStatusChange(batteryStatus);
                             }
                             else //blink if empty and button gets pressed
                             {
                                 P1OUT |= BIT0;
                                 P4OUT |= BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }

                                 P1OUT &= ~BIT0;
                                 P4OUT &= ~BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }
                                 P1OUT |= BIT0;
                                 P4OUT |= BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }

                                 P1OUT &= ~BIT0;
                                 P4OUT &= ~BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }
                             }
                         }
                         // When button S2 is pressed the first time
                         if (!(P2IN & BIT6) && S2buttonDebounce == 0)
                         {
                             P4OUT |= BIT0;            // turn on green LED
                             S2buttonDebounce = 1;
                             if (batteryStatus < 6)
                             {
                                 batteryStatus++;
                                 batteryStatusChange(batteryStatus);
                             }
                             else //blink if full and button S2 gets pressed
                             {
                                 P1OUT |= BIT0;
                                 P4OUT |= BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }

                                 P1OUT &= ~BIT0;
                                 P4OUT &= ~BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }
                                 P1OUT |= BIT0;
                                 P4OUT |= BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }

                                 P1OUT &= ~BIT0;
                                 P4OUT &= ~BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }
                             }
                         }
                         // Button S1 is released
                         if (P1IN & BIT2)
                         {
                             S1buttonDebounce = 0;     // Clear button
                             P1OUT &= ~BIT0;           // turn off red LED
                         }

                         // Button S2 is released
                         if (P2IN & BIT6)
                         {
                             S2buttonDebounce = 0;     // Clear button
                             P4OUT &= ~BIT0;           // turn off green LED
                         }
                         if (!(P1IN & BIT2) && !(P2IN & BIT6))
                         {
                             LCDM12 = 0x00;
                             LCDM13 = 0x00;
                             batteryStatus = 0;
                             switchCases = TextMode;
                         }
                         break;

        }
    }



    return 0;
}

void Init_GPIO()
{
    // Set all GPIO pins to output low to prevent floating input and reduce power consumption
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P7, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P8, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);

    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P8, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);

    GPIO_setAsInputPin(GPIO_PORT_P1, GPIO_PIN1);

    // Configure button S1 (P1.2) interrupt
    GPIO_selectInterruptEdge(GPIO_PORT_P1, GPIO_PIN2, GPIO_HIGH_TO_LOW_TRANSITION);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN2);
    GPIO_clearInterrupt(GPIO_PORT_P1, GPIO_PIN2);
    GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN2);

    // Configure button S2 (P2.6) interrupt
    GPIO_selectInterruptEdge(GPIO_PORT_P2, GPIO_PIN6, GPIO_HIGH_TO_LOW_TRANSITION);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_clearInterrupt(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_enableInterrupt(GPIO_PORT_P2, GPIO_PIN6);

    // Set P4.1 and P4.2 as Secondary Module Function Input, LFXT.
    GPIO_setAsPeripheralModuleFunctionInputPin(
           GPIO_PORT_P4,
           GPIO_PIN1 + GPIO_PIN2,
           GPIO_PRIMARY_MODULE_FUNCTION
           );

    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PMM_unlockLPM5();
}








    /*    displayScrollText("PRG_C ADINA HOCHULI");
    displayScrollText("PRG_C ADINA HOCHULI");

    showSymbol(12);
    showSymbol(18);

    P1DIR |= BIT0; // P1.0 pin set as output the rest are input
    P4DIR |= BIT0; // P4.0 pin set as output the rest are input

    P2REN |= BIT6; // Enable internal pull-up/down resistors for P2.6
    P2IN |= BIT6; //Select pull-up mode for P2.6
    P1REN |= BIT2; // Enable internal pull-up/down resistors for P1.2
    P1IN |= BIT2; //Select pull-up mode for P1.2

   // P1OUT |= BIT0; // Turn-ON red LED
    //P4OUT |= BIT0; // Turn-ON green LED

    s1last = BIT2;
    s2last = BIT6;


    while(1)
    {

    if(((P1IN & BIT2) == 0) && ((s1last & BIT2) == BIT2)) // if button S1 is pressed...
    {
    P1OUT ^= BIT0;
    }


    if(((P2IN & BIT6) == 0) && ((s2last & BIT6) == BIT6)) // if button S2 is pressed...
    {
    P4OUT ^= BIT0;
    }

    s1last = s1current;
    s2last = s2current;

    _delay_cycles(1000); // delay time
    }



    P1DIR |= 0x00;                          // Set P1.0 to output direction (red)
    P4DIR |= 0x00;                          // Set P4.0 to output direction (green)

    while (1)
    {
        if (P1IN == 0x01)
            P1OUT = 0x01;
        else
            P1OUT = 0x00;

        if (P4IN == 0x02)
            P4OUT = 0x01;
        else
            P4OUT = 0x00;
    }*/



