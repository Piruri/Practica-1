#include <msp430.h> 

/*
 * main.c
 */
char flag=0;
char estado=0;
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR |= (BIT0|BIT6);
	P1REN |= BIT3;
	P1OUT |= BIT3;
	while (1) {
		switch (estado) {
		case 0:
		P1OUT |= (BIT0|BIT6);	// Encendemos los dos leds
		if (!(P1IN&BIT3)){
			flag=1;
			__delay_cycles(1000);
		}
		if ((P1IN&BIT3)&&flag){
			flag=0;
			estado++;
		}
		break;
		case 1:
			P1OUT |= (BIT6);	// Encendemos Led2
			P1OUT &= ~(BIT0);	// Apagamos Led1

			if (!(P1IN&BIT3)){
				flag=1;
				__delay_cycles(1000);
			}
			if ((P1IN&BIT3)&&flag){
				flag=0;
				estado++;
			}
		break;
		case 2:
			P1OUT |= (BIT0);	// Encendemos Led1
			P1OUT &= ~(BIT6);	// Apagamos Led2
			if (!(P1IN&BIT3)){
				flag=1;
				__delay_cycles(1000);
			}
			if((P1IN&BIT3)&&flag){
				flag=0;
				estado++;
			}
		break;
		case 3:
			P1OUT &= ~(BIT0|BIT6);	// Apagamos los dos leds
			if (!(P1IN&BIT3)){
				flag=1;
				__delay_cycles(1000);
			}
			if ((P1IN&BIT3)&&flag){
				flag=0;
				estado=0;
			}
		break;
		}
	}
	return 0;
}
