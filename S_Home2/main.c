#include "Dio_Reg.h"
#include "Utilities.h"
#include "SPI.h"
void main(void)
{
	SPI_InitSlave();
	Dio_SetPinDirection(GroupA,PIN0,OUTPUT);
	Dio_SetPinDirection(GroupA,PIN1,OUTPUT);
	while(1)
	{
		switch(SPI_RecieveByte())
		{
		case('F'):TOG_bIT(PORTA,0);break;
		case('S'):TOG_bIT(PORTA,1);break;
		}
	}
}
