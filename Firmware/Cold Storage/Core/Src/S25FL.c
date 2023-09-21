/*
 * SPI FLASH.c
 *
 *  Created on: Sep 21, 2023
 *      Author: Ait
 */

#include "stm32l4xx.h"
#include "S25FL.h"
#include "spi.h"
#define Sector_Size  4096     //256Byte
#define Page_Size    256        //byte
#define Total_Sector 32        //Total sector of M25P16
#define Total_Page   8192 				
uint8_t first_write = 0;
uint8_t old_address;
extern SPI_HandleTypeDef hspi1;


/*******************************************************************************
* Function Name  : SPI_FLASH_ReadByte
* Description    : Reads a byte from the SPI Flash.
*                  This function must be used only if the Start_Read_Sequence
*                  function has been previously called.
* Input          : None
* Output         : None
* Return         : Byte Read from the SPI Flash.
*******************************************************************************/
uint8_t SPI_Flash_ReadByte(void)
{
  return (SPI_Flash_SendByte(Dummy_Byte));
}
/*******************************************************************************
* Function Name  : FlashReadID
* Description    : Reads a ID from the SPI Flash.
*                  This function must be used only if the Start_Read_Sequence
*                  function has been previously called.
* Input          : None
* Output         : None
* Return         : Byte ID from the SPI Flash.
*******************************************************************************/
void FlashReadID(uint8_t *Data)
{
	uint8_t i;
	Select_Flash();	
  	SPI_Flash_SendByte(RDID);
  	for(i = 0; i < 4; i++)
  	{
  		Data[i] = SPI_Flash_ReadByte();
  	}
  NotSelect_Flash();	
}
/*******************************************************************************
* Function Name  : FlashWaitBusy
* Description    : Check flash busy
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void FlashWaitBusy(void)
{
  uint8_t FLASH_Status = 0;
  Select_Flash();	
  SPI_Flash_SendByte(S25FL_RDSR);
  do
  {
    FLASH_Status = SPI_Flash_SendByte(Dummy_Byte);
  }
  while ((FLASH_Status & WIP_Flag) == SET); 
  NotSelect_Flash();	   
}




/*******************************************************************************
* Function Name  : SPI_FLASH_SendByte
* Description    : Sends a byte through the SPI interface and return the byte 
*                  received from the SPI bus.
* Input          : byte : byte to send.
* Output         : None
* Return         : The value of the received byte.
*******************************************************************************/
uint8_t SPI_Flash_SendByte(uint8_t byte)
{
	uint8_t dat;
	HAL_SPI_TransmitReceive(&hspi1, &byte, &dat, 1, 100);
    return dat;
}

void FlashSectorEarse(uint32_t page)
{	
	FlashWaitBusy();
	Select_Flash();
	SPI_Flash_SendByte(S25FL_WREN);
	NotSelect_Flash();

	FlashWaitBusy();
	Select_Flash();
	SPI_Flash_SendByte(S25FL_SECTOR_ERASE);
	SPI_Flash_SendByte((page >> 16) & 0xFF);
	SPI_Flash_SendByte((page >> 8) & 0xFF);
	SPI_Flash_SendByte(page & 0xFF);
	NotSelect_Flash();
}

/*******************************************************************************
* Function Name  : Flash_Read_Array
* Description    : Read array of byte from flash
* Input          : start_address: address start to read
*                : length: Length of array data to read
* Output         : buffer: contain data
* Return         : None
*******************************************************************************/
void Flash_Read_Array(uint32_t start_address, uint8_t buffer[], uint16_t length)
{
	uint8_t adress[4];
	FlashWaitBusy(); 
	Select_Flash();
	adress[0] = S25FL_READ;
	adress[1] = (start_address >> 16) & 0xFF;
	adress[2] = (start_address >> 8) & 0xFF;
	adress[3] = start_address & 0xFF;

	HAL_SPI_Transmit(&hspi1, adress, 4, 100);
	HAL_SPI_Receive(&hspi1, buffer, length, 100);

	NotSelect_Flash();
}

/*******************************************************************************
* Function Name  : Flash_Read_Array
* Description    : Write array of byte to flash
* Input          : start_address: address start to write
*                : length: Length of array data to write
* Output         : buffer: contain data
* Return         : None
*******************************************************************************/
void Flash_Write_Array(uint32_t start_address,uint8_t buffer[],uint16_t length)
{
	uint8_t adress[4];
	if(start_address%0x1000 == 0) FlashSectorEarse(start_address);
	FlashWaitBusy();
	Select_Flash();
	SPI_Flash_SendByte(S25FL_WREN);
	NotSelect_Flash();
	FlashWaitBusy();
	
	Select_Flash();
	adress[0] = S25FL_WRITE;
	adress[1] = (start_address >> 16) & 0xFF;
	adress[2] = (start_address >> 8) & 0xFF;
	adress[3] = start_address & 0xFF;
	HAL_SPI_Transmit(&hspi1, adress, 4, 100);
	NotSelect_Flash();
}

