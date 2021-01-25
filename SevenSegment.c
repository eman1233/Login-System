/*
 * SevenSegment.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: inter
 */

#include "SevenSegment.h"
#include "Dio.h"
#include "SevenSegment_Cfg.h"
#include "Det.h"

#if(Mode==Common_Cathod)


static const char arr [10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

void SevenSegmentON (SevenSegment_t *SevenSegmentPtrConfig)
{
	SevenSegmentPtrConfig->Channel=SevenSegmentCathodEnable;
	SevenSegmentPtrConfig->Level=STD_HIGH;
	Dio_WriteChannel(SevenSegmentPtrConfig->Channel,SevenSegmentPtrConfig->Level);
}
void SevenSegmentOFF  (SevenSegment_t *SevenSegmentPtrConfig)
{
	SevenSegmentPtrConfig->Channel=SevenSegmentCathodEnable;
	SevenSegmentPtrConfig->Level=STD_LOW;
	Dio_WriteChannel(SevenSegmentPtrConfig->Channel,SevenSegmentPtrConfig->Level);

}
void SevenSegmentDisplay(SevenSegment_t *SevenSegmentPtrConfig)
{
	Dio_WritePort(SevenSegmentPtrConfig->port,arr[SevenSegmentPtrConfig->Index]);
	SevenSegmentPtrConfig->Index++;
	if(SevenSegmentPtrConfig->Index==10)
	{
		SevenSegmentPtrConfig->Index=0;
	}

}
#elif (Mode==Common_Anode)

static const char arr [10]={~ZERO,~ONE,~TWO,~THREE,~FOUR,~FIVE,~SIX,~SEVEN,~EIGHT,~NINE};

void SevenSegmentON (SevenSegment_t *SevenSegmentPtrConfig)
{
	SevenSegmentPtrConfig->Channel=SevenSegmentAnodeEnable;
	SevenSegmentPtrConfig->Level=STD_LOW;
	Dio_WriteChannel(SevenSegmentPtrConfig->Channel,SevenSegmentPtrConfig->Level);
}
void SevenSegmentOFF  (SevenSegment_t *SevenSegmentPtrConfig)
{
	SevenSegmentPtrConfig->Channel=SevenSegmentAnodeEnable;
	SevenSegmentPtrConfig->Level=STD_HIGH;
	Dio_WriteChannel(SevenSegmentPtrConfig->Channel,SevenSegmentPtrConfig->Level);
}
void SevenSegmentDisplay(SevenSegment_t *SevenSegmentPtrConfig)
{
	Dio_WritePort(SevenSegmentPtrConfig->port,arr[SevenSegmentPtrConfig->Index]);
	SevenSegmentPtrConfig->Index++;
	if(SevenSegmentPtrConfig->Index==10)
	{
		SevenSegmentPtrConfig->Index=0;
	}

}
#endif

