#include "Dio_Int.h"
#include "util/delay.h"
#include "Utilities.h"
#include "Dio_Reg.h"
#include "UART.h"
void UART_Init(void)
{
	//Enable RX and TX
	//UCSRB set	 bit 4,3
	SET_BIT(UCSRB,4);
	SET_BIT(UCSRB,3);
	// setting the frame (UCSRC): 8bits set bit 1,0 :no parity CLR bit 5,4 :one stop CLR bit 3
	SET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);
	//setting the baud rate UBRRL 103
	//UBRRH=0;
	UBRRL=103;
}
void UART_SendByte(u8 Byte)
{
	// wait until the transmit flag is empty
	// UCSRA bit 6 wait while this bit is 0
	UDR = Byte;
	while(GET_BIT(UCSRA,6)==0);


}
u8 UART_RecieveByte(void)
{
	// wait until the transmit flag is empty
	// UCSRA bit 7 wait while this bit is 0
	while(GET_BIT(UCSRA,7)==0);
	return UDR;
}

