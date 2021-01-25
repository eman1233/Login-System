/*
 * ExternalInterrupt.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: inter
 */

#include "ExternalInterrupt.h"
#include "ExternalInterrupt_MemMap.h"
#include "Std_Types.h"

#define NumOfInterrupts 3

static void (*ArrInterruptToFun[NumOfInterrupts])(void)={NULL,NULL,NULL};
void ExternalEnableInterrupt (Dio_ExternalInterrupConfig *Dio_ExternalInterrupConfigPtr)
{
	if(Dio_ExternalInterrupConfigPtr->ExternalChannel==INT0_)
	{
		SET_BIT(GICR_REG,INT0_Enable);
		switch(Dio_ExternalInterrupConfigPtr->ExternalChannel)
		{
		case(LowLevel):
				CLEAR_BIT(MCUCR_REG,ISC00_);
		        CLEAR_BIT(MCUCR_REG,ISC01_);
				break;
		case(AnyLogicalChange):
				SET_BIT(MCUCR_REG,ISC00_);
	            CLEAR_BIT(MCUCR_REG,ISC01_);
				break;
		case(Falling_Edge):
				CLEAR_BIT(MCUCR_REG,ISC00_);
			    SET_BIT(MCUCR_REG,ISC01_);
				break;
		case(Raising_Edge):
				SET_BIT(MCUCR_REG,ISC00_);
				SET_BIT(MCUCR_REG,ISC01_);
				break;

		}

}
	 if(Dio_ExternalInterrupConfigPtr->ExternalChannel==INT1_)
	{
		SET_BIT(GICR_REG,INT1_Enable);
		switch(Dio_ExternalInterrupConfigPtr->ExternalChannel)
		{
		case(LowLevel):
				CLEAR_BIT(MCUCR_REG,ISC10_);
		        CLEAR_BIT(MCUCR_REG,ISC11_);
				break;
		case(AnyLogicalChange):
				SET_BIT(MCUCR_REG,ISC10_);
	            CLEAR_BIT(MCUCR_REG,ISC11_);
				break;
		case(Falling_Edge):
				CLEAR_BIT(MCUCR_REG,ISC10_);
			    SET_BIT(MCUCR_REG,ISC11_);
				break;
		case(Raising_Edge):
				SET_BIT(MCUCR_REG,ISC10_);
				SET_BIT(MCUCR_REG,ISC11_);
				break;

		}

	}
	 if(Dio_ExternalInterrupConfigPtr->ExternalChannel==INT2_)
	{
			SET_BIT(GICR_REG,INT2_Enable);
		switch(Dio_ExternalInterrupConfigPtr->InterruptEdge)
		{
		case(LowLevel):

				break;
		case(AnyLogicalChange):

				break;
		case(Falling_Edge):
		        CLEAR_BIT(MCUCSR_REG,ISC2_);
				break;
		case(Raising_Edge):
				SET_BIT(MCUCSR_REG,ISC2_);
				break;

		}
	}

}

void ExternalDisableInterrupt (Dio_ExternalInterrupConfig *Dio_ExternalInterrupConfigPtr)
{
	CLEAR_PIN(Dio_ExternalInterrupConfigPtr->ExternalChannel,STD_NOT_OK);
}

void ExternalSetCallBack(Dio_ExternalInterrupConfig *Dio_ExternalInterrupConfigPtr)
{
	ArrInterruptToFun[Dio_ExternalInterrupConfigPtr->ExternalChannel]=Dio_ExternalInterrupConfigPtr->InterruptPtr;

}

/*void __vector_1(void) __attribute__((single));
void __vector_1(void)
{
	if(ArrInterruptToFun[INT0_]!=NULL)
	    ArrInterruptToFun[INT0_]();
}

void __vector_2(void) __attribute__((single));
void __vector_2(void)
{
	if(ArrInterruptToFun[INT1_]!=NULL)
	   ArrInterruptToFun[INT1_]();
}

void __vector_3(void) __attribute__((single));
void __vector_3(void)
{
	if(ArrInterruptToFun[INT2_]!=NULL)
	   ArrInterruptToFun[INT2_]();
}*/
