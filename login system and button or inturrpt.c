#include "ADC.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "LcdService.h"
#include "Dio.h"
#include "Keypad.h"
#include "Keypad_Cfg.h"
#include "LED_Cfg.h"
#include "LED.h"
#include <string.h>
#include"SevenSegment_Cfg.h"
#include"SevenSegment.h"
#include "motor.h"
#include "Motor_Cfg.h"
#include "ExternalInterrupt.h"
#include "ExternalInterrupt_MemMap.h"
#include "Switch.h"
#include "Switch_Cfg.h"

/*u8 reset=0;

int main(void)
{
	Dio_Init();
	LCD_init();
	SET_BIT(SREG_REG,7);
	SET_BIT(GICR_REG,INT0_Enable);
	MCUCR_REG=0X8;
	Motor_t Motor={MotorClockWiseDirection,MotorAntiClockWiseDirection,STD_HIGH};
	u8 PassWord[4]="1234";
	extern  const char arr [10];
	u8 staus;
	u8 Pass[4];
	u8 i=0;
	u8 flag=0;
	u8 res=0;
	u8 index=3;
	LED_t Led={LED_1,STD_HIGH};
		LCD_CursorMove(2,2);
			LCD_WriteString("Welcome  ");
			_delay_ms(3000);
			LCD_Clear();
			while(1)
				{
					Dio_WritePort(PORT_SEVEN_SEGMENT,arr[index]);
					LCD_CursorMove(1,0);
					LCD_WriteString("Please Enter  ");
					LCD_CursorMove(2,0);
					LCD_WriteString("Your Password ");
					staus=GetKeyState ();
					if(staus!=KeyNotPressed)
					{
						i++;
						if(i==1)
						{
							LCD_CursorMove(3,0);
							LCD_WriteData('*');
							Pass[0]=staus;
						}
						if(i==2)
						{
							LCD_CursorMove(3,1);
							LCD_WriteData('*');
							Pass[1]=staus;
						}
						if(i==3)
						{
							LCD_CursorMove(3,2);
							LCD_WriteData('*');
							Pass[2]=staus;
						}
						if(i==4)
						{
							LCD_CursorMove(3,3);
							LCD_WriteData('*');
							Pass[3]=staus;
						}
					}
					res=strcmp(Pass,PassWord);
					LCD_CursorMove(4,2);
					LCD_WriteData(res);
					if(res==0b11010110&&i==4)
					{
						LCD_Clear();
						LCD_CursorMove(2,2);
						LCD_WriteString("Entered");
						LedOn(&Led);
						while(1)
						{
							 MotorDirectionClockWise(&Motor);
							_delay_ms(3000);
							 MotorDirectionAntiClockWise(&Motor);
							_delay_ms(3000);

						}
						break;
					}
					else if(res!=0b11010110&&i==4)
					{
						flag++;
						index--;
						if(flag==3)
						{
							LCD_Clear();
							LCD_CursorMove(0,1);
							LCD_WriteString("Not Entered");
							Dio_WritePort(PORT_SEVEN_SEGMENT,arr[0]);
							break;
						}
						LCD_Clear();
						LCD_CursorMove(0,1);
						LCD_WriteString("Try again");
						Dio_WritePort(PORT_SEVEN_SEGMENT,arr[index]);
						_delay_ms(1000);
						LCD_Clear();
						i=0;

					}

				}

	while(1)
	{

	}

}
ISR(INT0_vect)

{
	reset=1;
	LCD_Clear();
	_delay_ms(100);
	u8 PassWord[4]="1234";
	extern  const char arr [10];
	u8 staus;
	u8 Pass[4];
	u8 i=0;
	u8 flag=0;
	u8 res=0;
	u8 index=3;
	LED_t Led={LED_1,STD_HIGH};
	Motor_t Motor={MotorClockWiseDirection,MotorAntiClockWiseDirection,STD_HIGH};
	MotorOff(&Motor);
	LCD_CursorMove(2,2);
		LCD_WriteString("Welcome  ");
		_delay_ms(3000);
		LCD_Clear();
		while(1)
			{
				Dio_WritePort(PORT_SEVEN_SEGMENT,arr[index]);
				LCD_CursorMove(1,0);
				LCD_WriteString("Please Enter  ");
				LCD_CursorMove(2,0);
				LCD_WriteString("Your Password ");
				staus=GetKeyState ();
				if(staus!=KeyNotPressed)
				{
					i++;
					if(i==1)
					{
						LCD_CursorMove(3,0);
						LCD_WriteData('*');
						Pass[0]=staus;
					}
					if(i==2)
					{
						LCD_CursorMove(3,1);
						LCD_WriteData('*');
						Pass[1]=staus;
					}
					if(i==3)
					{
						LCD_CursorMove(3,2);
						LCD_WriteData('*');
						Pass[2]=staus;
					}
					if(i==4)
					{
						LCD_CursorMove(3,3);
						LCD_WriteData('*');
						Pass[3]=staus;
					}
				}
				res=strcmp(Pass,PassWord);
				LCD_CursorMove(4,2);
				LCD_WriteData(res);
				if(res==0b11010110&&i==4)
				{
					LCD_Clear();
					LCD_CursorMove(2,2);
					LCD_WriteString("Entered");
					LedOn(&Led);
					while(1)
					{
						 MotorDirectionClockWise(&Motor);
						_delay_ms(3000);
						 MotorDirectionAntiClockWise(&Motor);
						_delay_ms(3000);

					}
					break;
				}
				else if(res!=0b11010110&&i==4)
				{
					flag++;
					index--;
					if(flag==3)
					{
						LCD_Clear();
						LCD_CursorMove(0,1);
						LCD_WriteString("Not Entered");
						Dio_WritePort(PORT_SEVEN_SEGMENT,arr[0]);
						break;
					}
					LCD_Clear();
					LCD_CursorMove(0,1);
					LCD_WriteString("Try again");
					Dio_WritePort(PORT_SEVEN_SEGMENT,arr[index]);
					_delay_ms(1000);
					LCD_Clear();
					i=0;

				}

			}

}*/
//LED_t led={LED_1,STD_HIGH};
/*void fun (void)
{
	LCD_Clear();
	TOGGLE_BIT(PORTA_REG,LED_1);
	reset=1;
	LCD_CursorMove(4,5);
	LCD_WriteNum(reset);

}
void fun2 (void)
{
	LCD_Clear();
	reset=2;
	LCD_CursorMove(4,5);
	LCD_WriteNum(reset);

}*/

Motor_t Motor={MotorClockWiseDirection,MotorAntiClockWiseDirection,STD_HIGH};
LED_t Led={LED_1,STD_HIGH};
volatile static u8 index;
volatile static u8 flag=0;
volatile static u8 reset=0;
int main(void)
{
	Dio_Init();
	LCD_init();
	SET_BIT(SREG_REG,7);
	SET_BIT(GICR_REG,INT0_Enable);
	MCUCR_REG=0X8;

	u8 PassWord[4]="1234";
	extern  const char arr [10];
	u8 staus;
	u8 Pass[4];
	u8 i=0;
	u8 res=0;

		/*LCD_CursorMove(2,2);
			LCD_WriteString("Welcome  ");
			_delay_ms(3000);*/
			while(1)
				{

				if(reset==1||reset==2)
				{

					Dio_WritePort(PORT_SEVEN_SEGMENT,arr[index]);
					LCD_CursorMove(1,0);
					LCD_WriteString("Please Enter  ");
					LCD_CursorMove(2,0);
					LCD_WriteString("Your Password ");
					staus=GetKeyState ();
					if(staus!=KeyNotPressed)
					{
						i++;
						if(i==1)
						{
							LCD_CursorMove(3,0);
							LCD_WriteData('*');
							Pass[0]=staus;
						}
						if(i==2)
						{
							LCD_CursorMove(3,1);
							LCD_WriteData('*');
							Pass[1]=staus;
						}
						if(i==3)
						{
							LCD_CursorMove(3,2);
							LCD_WriteData('*');
							Pass[2]=staus;
						}
						if(i==4)
						{
							LCD_CursorMove(3,3);
							LCD_WriteData('*');
							Pass[3]=staus;
						}
					}
					res=strcmp(Pass,PassWord);
					/*LCD_CursorMove(4,2);
					LCD_WriteData(res);*/
					if(res=='.'&&i==4)
					{
						LCD_Clear();
						LCD_CursorMove(2,2);
						LCD_WriteString("Entered");
						LedOn(&Led);
						MotorDirectionClockWise(&Motor);
						_delay_ms(3000);
						MotorDirectionAntiClockWise(&Motor);
						_delay_ms(3000);
						i=0;
					}
					else if(res!='.'&&i==4)
					{
						flag++;
						index--;
						if(flag==3)
						{
							LCD_Clear();
							LCD_CursorMove(0,1);
							LCD_WriteString("Not Entered");
							Dio_WritePort(PORT_SEVEN_SEGMENT,arr[index]);
							break;
						}
						LCD_Clear();
						LCD_CursorMove(0,1);
						LCD_WriteString("Try again");
						Dio_WritePort(PORT_SEVEN_SEGMENT,arr[index]);
						_delay_ms(1000);
						LCD_Clear();
						i=0;

					}

				}
				}
			while(1)
			{

			}

}
	ISR(INT0_vect)
	{
		LCD_Clear();
		reset++;
		if(reset==3)
		    LCD_Clear();
		MotorOff(&Motor);
		LedOff(&Led);
		Dio_WritePort(PORT_SEVEN_SEGMENT,0);
		index=3;
		flag=0;
		LCD_CursorMove(2,2);
		LCD_WriteString("Welcome  ");
		_delay_ms(30000);


		/*LCD_CursorMove(4,5);
		LCD_WriteNum(reset);*/
	}

