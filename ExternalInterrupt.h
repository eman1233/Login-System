/*
 * ExternalInterrupt.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: inter
 */

#ifndef EXTERNALINTERRUPT_H_
#define EXTERNALINTERRUPT_H_

#include "Std_Types.h"
typedef enum
{
	LowLevel=0,
	AnyLogicalChange,
	Falling_Edge,
	Raising_Edge
}InterruptEdge_t;

typedef enum
{
    ISC00_=0,
	ISC01_,
	ISC10_,
	ISC11_
}MCUControlRegister;

typedef enum
{
	INT2_Enable=5,
	INT0_Enable=6,
	INT1_Enable=7

}GeneralInterruptControlRegister;

typedef enum
{
	INTF2_=5,
	INTF0_=6,
	INTF1_=7

}GeneralInterruptFlagRegister;

typedef enum
{
	ISC2_=6
}MCUControlandStatusRegister;
typedef enum
{
	INT0_=0,
	INT1_,
	INT2_
}ExternalType;

typedef struct
{
	ExternalType ExternalChannel;
	InterruptEdge_t InterruptEdge;
	void(*InterruptPtr)(void);

}Dio_ExternalInterrupConfig;

void ExternalEnableInterrupt (Dio_ExternalInterrupConfig *Dio_ExternalInterrupConfigPtr);

void ExternalDisableInterrupt (Dio_ExternalInterrupConfig *Dio_ExternalInterrupConfigPtr);

void ExternalSetCallBack(Dio_ExternalInterrupConfig *Dio_ExternalInterrupConfigPtr);
#endif /* EXTERNALINTERRUPT_H_ */
