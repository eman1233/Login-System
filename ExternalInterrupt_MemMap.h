/*
 * ExternalInterrupt_MemMap.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: inter
 */

#ifndef EXTERNALINTERRUPT_MEMMAP_H_
#define EXTERNALINTERRUPT_MEMMAP_H_


#define MCUCR_REG             *((volatile u8*)0X55)
#define MCUCSR_REG            *((volatile u8*)0X54)
#define GICR_REG              *((volatile u8*)0X5B)
#define GIFR_REG              *((volatile u8*)0X5A)


#define READ_PIN(PORT,PIN)    ((PORT>>PIN)&1)
#define SET_PIN(PORT,PIN)    (PORT=PORT|(1<<PIN))
#define CLEAR_PIN(PORT,PIN)  (PORT&=~(1<<PIN))
#define TOGGLE_PIN(PORT,PIN) (PORT^=(1<<PIN))

#define READ_BIT(PORT,BIT)    ((PORT>>BIT)&1)
#define SET_BIT(PORT,BIT)    (PORT=PORT|(1<<BIT))
#define CLEAR_BIT(PORT,BIT)  (PORT&=~(1<<BIT))
#define TOGGLE_BIT(PORT,BIT) (PORT^=(1<<BIT))
#endif /* EXTERNALINTERRUPT_MEMMAP_H_ */
