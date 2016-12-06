#include <msp430.h> 
/*
 * main.c
 */
char flag=0;
char estado=0;
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR|=(BIT0|BIT1|BIT2|BIT3|BIT4|BIT5);
	P2DIR|=BIT0;
	P1REN|=BIT7;
	P1OUT|=BIT7;
	while(1){
		switch(estado){
		case 0:
			P1OUT |= (BIT0|BIT1|BIT2|BIT4|BIT5);	// Enciendo B A F E D
			P2OUT |= BIT0;							// Enciendo C
			P1OUT &= BIT3;							// Apago G
			if (!(BIT7&P1IN)){
				flag=1;
				__delay_cycles(10000);
			}
			if ((BIT7&P1IN)&&flag){
				flag=0;
				estado++;
				__delay_cycles(10000);
			}
		break;
		case 1:
			P1OUT &= ~(BIT1|BIT2|BIT3|BIT4|BIT5);	// Apago A F G E D
			P2OUT |= BIT0;							// Enciendo C
			P1OUT |= BIT0;							// Enciendo B
			if (!(BIT7&P1IN)){
				flag=1;
				__delay_cycles(10000);
			}
			if ((BIT7&P1IN)&&flag){
				flag=0;
				estado++;
				__delay_cycles(10000);
			}
		break;
		case 2:
			P1OUT |= (BIT0|BIT1|BIT3|BIT4|BIT5);	// Enciendo B A G E D
			P2OUT &= ~BIT0;							// Apago C
			P1OUT &= ~BIT2;							// Apago F
			if (!(BIT7&P1IN)){
				flag=1;
				__delay_cycles(10000);
			}
			if ((BIT7&P1IN)&&flag){
				flag=0;
				estado++;
				__delay_cycles(10000);
			}
		break;
		case 3:
			P1OUT |= (BIT0|BIT1|BIT3|BIT5);			// Enciendo B A G D
			P2OUT |= BIT0;							// Enciendo C
			P1OUT &= ~(BIT2|BIT4);					// Apago F E
			if (!(BIT7&P1IN)){
				flag=1;
				__delay_cycles(10000);
			}
			if ((BIT7&P1IN)&&flag){
				flag=0;
				estado++;
				__delay_cycles(10000);
			}
		break;
		case 4:
			P1OUT |= (BIT0|BIT2|BIT3);				// Enciendo B F G
			P2OUT |= BIT0;							// Enciendo C
			P1OUT &= ~(BIT1|BIT4|BIT5);				// Apago A E D
			if (!(BIT7&P1IN)){
				flag=1;
				__delay_cycles(10000);
			}
			if ((BIT7&P1IN)&&flag){
				flag=0;
				estado++;
				__delay_cycles(10000);
			}
		break;
		case 5:
			P1OUT |= (BIT1|BIT2|BIT3|BIT5);			// Enciendo A F G D
			P2OUT |= BIT0;							// Enciendo C
			P1OUT &= ~(BIT0|BIT4);					// Apago B E
			if (!(BIT7&P1IN)){
				flag=1;
				__delay_cycles(10000);
			}
			if ((BIT7&P1IN)&&flag){
				flag=0;
				estado++;
				__delay_cycles(10000);
			}
		break;
		case 6:
			P1OUT |= (BIT1|BIT2|BIT3|BIT4|BIT5);	// Enciendo A F G E D
			P2OUT |= BIT0;							// Enciendo C
			P1OUT &= ~BIT0;							// Apago B
			if (!(BIT7&P1IN)){
				flag=1;
				__delay_cycles(10000);
			}
			if ((BIT7&P1IN)&&flag){
				flag=0;
				estado++;
				__delay_cycles(10000);
			}
		break;
		case 7:
			P1OUT |= (BIT0|BIT1);					// Enciendo B A
			P2OUT |= BIT0;							// Enciendo C
			P1OUT &= ~(BIT2|BIT3|BIT4|BIT5);		// Apago F G E D
			if (!(BIT7&P1IN)){
				flag=1;
				__delay_cycles(10000);
			}
			if ((BIT7&P1IN)&&flag){
				flag=0;
				estado++;
				__delay_cycles(10000);
			}
		break;
		case 8:
			P1OUT |= (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5);	// Enciendo B A F G E D
			P2OUT |= BIT0;								// Enciendo C
			if (!(BIT7&P1IN)){
				flag=1;
				__delay_cycles(10000);
			}
			if ((BIT7&P1IN)&&flag){
				flag=0;
				estado++;
				__delay_cycles(10000);
			}
		break;
		case 9:
			P1OUT |= (BIT0|BIT1|BIT2|BIT3|BIT5);	// Enciendo B A F G D
			P2OUT |= BIT0;							// Enciendo C
			P1OUT &= ~BIT4;							// Apago E
			if (!(BIT7&P1IN)){
				flag=1;
				__delay_cycles(10000);
			}
			if ((BIT7&P1IN)&&flag){
				flag=0;
				estado=0;
				__delay_cycles(10000);
			}
		break;
		}
	}
	return 0;
}
