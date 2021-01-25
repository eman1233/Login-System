/*
 * SevenSegment.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: inter
 */

#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include "Std_Types.h"
#include "Dio.h"
typedef struct
{
	Dio_ChannelType Channel;
	Dio_PortType port;
	u8 Index;
	Dio_LevelType Level;
}SevenSegment_t;

void SevenSegmentON (SevenSegment_t *SevenSegmentPtrConfig);
void SevenSegmentOFF  (SevenSegment_t *SevenSegmentPtrConfig);
void SevenSegmentDisplay(SevenSegment_t *SevenSegmentPtrConfig);

void SevenSegmentON (SevenSegment_t *SevenSegmentPtrConfig);
void SevenSegmentOFF  (SevenSegment_t *SevenSegmentPtrConfig);
void SevenSegmentDisplay(SevenSegment_t *SevenSegmentPtrConfig);

#define SevenSegmentON_API     0x01

#define SevenSegmentOFF_API    0x02

#define  SevenSegmentDisplay_API   0x03



#endif /* SEVENSEGMENT_H_ */
