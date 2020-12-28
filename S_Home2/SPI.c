#include "Dio_Int.h"
#include "Utilities.h"
#include "Dio_Reg.h"
#include "SPI.h"
void SPI_InitMaster(void)
{
	// configure SPI pins
	Dio_SetPinDirection(GroupB,PIN4,OUTPUT); //SS
	Dio_SetPinDirection(GroupB,PIN5,OUTPUT); //MOSI
	Dio_SetPinDirection(GroupB,PIN6,INPUT); //MISO
	Dio_SetPinDirection(GroupB,PIN7,OUTPUT); //SCK
	//Master mode
	SET_BIT(SPCR,4);
	//Enable SPI
	SET_BIT(SPCR,6);

	//clock rate to fso/4 : clr bits 0,1 (no need to do it)

}
void SPI_InitSlave(void)
{
	// configure SPI pins
	Dio_SetPinDirection(GroupB,PIN4,INPUT); //SS
	Dio_SetPinDirection(GroupB,PIN5,INPUT); //MOSI
	Dio_SetPinDirection(GroupB,PIN6,OUTPUT); //MISO
	Dio_SetPinDirection(GroupB,PIN7,INPUT); //SCK
	//Enable SPI
	SET_BIT(SPCR,6);
	//clock rate to fso/4 : clr bits 0,1 (no need to do it)
}
void SPI_SendByte(u8 data)
{
	SPDR =data;
	while(GET_BIT(SPSR,7)==0);
}
u8 SPI_RecieveByte(void)
{
	while(GET_BIT(SPSR,7)==0);
	return SPDR;
}

