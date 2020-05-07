#include <msp430.h> 
#include "driverlib.h"

// Backup Memory variables to track states through LPM3.5
volatile unsigned char * S1buttonDebounce = &BAKMEM2_L;       // S1 button debounce flag
volatile unsigned char * S2buttonDebounce = &BAKMEM2_H;       // S2 button debounce flag

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
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;       // Disable the GPIO power-on default high-impedance mode

    // Clear LCD memory
    LCD_E_clearAllMemory(LCD_E_BASE);

	P1DIR |= 0x01;                          // Set P4.0 to output direction (green)
    P4DIR |= 0x01;                          // Set P4.0 to output direction (green)

    P2REN |= BIT6; // Enable internal pull-up/down resistors for P2.6
    P2OUT |= BIT6; //Select pull-up mode for P2.6
    P1REN |= BIT2; // Enable internal pull-up/down resistors for P1.2
    P1OUT |= BIT2; //Select pull-up mode for P1.2

    P1OUT &= ~BIT0;
    P4OUT &= ~BIT0;

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


    __enable_interrupt();

    while(1)
    {
    }

	return 0;
}

/* PORT1 Interrupt Service Routine
* Handles S1 button press interrupt
*/
#pragma vector = PORT1_VECTOR
__interrupt void PORT1_ISR(void)
{
   //P1OUT |= BIT0;    // Turn LED1 On
   switch(__even_in_range(P1IV, P1IV_P1IFG7))
   {
       case P1IV_NONE : break;
       case P1IV_P1IFG0 : break;
       case P1IV_P1IFG1 : break;
       case P1IV_P1IFG2 :
           if ((*S1buttonDebounce) == 0)
           {
               *S1buttonDebounce = 1;                               // First high to low transition
               P1OUT ^= 0x01;                                       // Toggle LED1 (red) on
               Timer_A_initUpMode(TIMER_A0_BASE, &initUpParam_A0);  // Start debounce timer
           break;
       case P1IV_P1IFG3 : break;
       case P1IV_P1IFG4 : break;
       case P1IV_P1IFG5 : break;
       case P1IV_P1IFG6 : break;
       case P1IV_P1IFG7 : break;
       }
   }
}

/* PORT2 Interrupt Service Routine
 * Handles S2 button press interrupt
*/
#pragma vector = PORT2_VECTOR
__interrupt void PORT2_ISR(void)
{
    //P4OUT |= BIT0;    // Turn LED2 On
    switch(__even_in_range(P2IV, P2IV_P2IFG7))
    {
        case P2IV_NONE : break;
        case P2IV_P2IFG0 : break;
        case P2IV_P2IFG1 : break;
        case P2IV_P2IFG2 : break;
        case P2IV_P2IFG3 : break;
        case P2IV_P2IFG4 : break;
        case P2IV_P2IFG5 : break;
        case P2IV_P2IFG6 : ;
        if ((*S2buttonDebounce) == 0)
               {
                   *S2buttonDebounce = 1;                               // First high to low transition
                   P4OUT ^= 0x01;                                       // Toggle LED1 (red) on
                   Timer_A_initUpMode(TIMER_A0_BASE, &initUpParam_A0);  // Start debounce timer
               break;
        case P2IV_P2IFG7 : break;
        }
    }
}


/*
* Timer A0 Interrupt Service Routine
* Used as button debounce timer
*/
#pragma vector = TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR (void)
{
    // Button S1 released
    if (P1IN & BIT2)
    {
        *S1buttonDebounce = 0;                                   // Clear button debounce
        //P1OUT &= ~BIT0;
    }

    // Button S2 released
    if (P2IN & BIT6)
    {
        *S2buttonDebounce = 0;                                   // Clear button debounce
        //P4OUT &= ~BIT0;
    }
}

