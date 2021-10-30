/*
 * SevenSegment.h
 *
 * Created: 16/12/2019 07:22:53 ص
 *  Author: admin
 */ 


#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#define SevenSegmentDir DDRB 
#define SevenSegmentData PORTB

#define SEG_A(x)   if (x==0) CLRBIT(PORTB,0); else SETBIT(PORTB,0); 
#define SEG_B(x)   if (x==0) CLRBIT(PORTB,1); else SETBIT(PORTB,1); 
#define SEG_C(x)   if (x==0) CLRBIT(PORTB,2); else SETBIT(PORTB,2);
#define SEG_D(x)   if (x==0) CLRBIT(PORTB,3); else SETBIT(PORTB,3);
#define SEG_EN1(x)   if (x==0) CLRBIT(PORTB,4); else SETBIT(PORTB,4);
#define SEG_EN2(x)   if (x==0) CLRBIT(PORTB,5); else SETBIT(PORTB,5); 


void SevenSegmentInit ();
void SevenSegmentUpdate (unsigned int counter);


#endif /* SEVENSEGMENT_H_ */