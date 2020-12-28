#include "Dio_Reg.h"
#include "Utilities.h"
#include "SPI.h"
#include "UART.h"
u8 flag;
void main(void)
{
	SPI_InitMaster();
	UART_Init();
	while(1)
	{
		SPI_SendByte(UART_RecieveByte());
	}
}
