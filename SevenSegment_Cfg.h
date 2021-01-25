/*
 * SevenSegment_Lcfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: inter
 */

#ifndef SEVENSEGMENT_CFG_H_
#define SEVENSEGMENT_CFG_H_

#define Common_Cathod 0

#define Common_Anode  1

#define Mode Common_Cathod

#define PORT_SEVEN_SEGMENT  PA

#define SevenSegmentCathodEnable   PINB2

#define SevenSegmentAnodeEnable    PINB3

#define ZERO  0b0111111
#define ONE   0b00000110
#define TWO   0b1011011
#define THREE 0b1001111
#define FOUR  0b1100110
#define FIVE  0b1011011
#define SIX   0b1111101
#define SEVEN 0b0000111
#define EIGHT 0b11111111
#define NINE  0b11101111

#endif /* SEVENSEGMENT_CFG_H_ */
