#include <msp430.h> 



unsigned long bootCounter;
unsigned long *pBootCounter = (unsigned long*)0x1800;
const unsigned int blinkDelayCounts = 30000;


void BlinkDelay(unsigned int delayCycles);
/**
 * main.c
 */
int main(void)
 {
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	 PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
	                                            // to activate previously configured port settings

	    bootCounter = *pBootCounter;            // read boot counter from FRAM
	    bootCounter++;                          // increment the boot counter

	    P1DIR |= 0x01;                          // Set P1.0 to output direction
	    P4DIR |= 0x01;                          // Set P4.0 to output direction

	    SYSCFG0 &= ~DFWP;                       // unset FRAM write protection -> DFWP = "Data FRAM Write Protection"
	    *pBootCounter = bootCounter;            // boot counter in FRAM to the new value
	    SYSCFG0 |= DFWP;                        // set FRAM write protection

	    P4OUT = 0x01;                           // set the green LED

	    unsigned int i;
	    for(i = 1; i<= bootCounter; i++)        // blink the red LED as many times as we have booted
	    {
	        P1OUT = 0x01;                       // led on
	        BlinkDelay(blinkDelayCounts);

	        P1OUT = 0x00;                       // led off
	        BlinkDelay(blinkDelayCounts);

	    }

	    P1OUT = 0x00;                           // turn off red LED
	    P4OUT = 0x00;                           // turn off green LED

	    return 0;
	}

	void BlinkDelay(unsigned int delayCycles)
	{
	    volatile unsigned int j;
	    j = delayCycles;
	    do j--;
	    while(j != 0);
	}
