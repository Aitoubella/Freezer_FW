/*
 * uart_cmd.c
 *
 *  Created on: Oct 9, 2023
 *      Author: Loc
 */


#include "uart_cmd.h"
#include "usart.h"
#include "event.h"



#define UART_BUFF_SIZE   100
uint8_t uart_cmd_buf[UART_BUFF_SIZE];

event_id uart_cmd_id;


typedef struct
{
	uint16_t pixel_x;
	uint16_t pixel_y;
	uint8_t  char_size; //in pixel
	uint8_t color; // white or red;
	uint8_t chr[50]; //string
}uart_cmd_t;

enum
{
	HEADER_STATE = 0,
	CONTENT_STATE,
	END_STATE,
};

enum
{
	CMD_DRAW_SYMBOL = 0,
	CMD_WRITE_STRING,
};

typedef void (* uart_cmd_cb_t)(uart_cmd_t* cmd);



uint8_t uart_cli_get_data(const char * buff, const char* cmd, char* data_out,char* data_len)
{
	char* result = strstr((char *)buff,(char *)cmd);
	if(result)
	{
		result += strlen(cmd);
		//Remove space character
		while((*result) == ' ')
		{
			result += 1;
		}
		//Get data until met space character or NULL
		while(((*result) != ' ') && (result != NULL))
		{
			(* data_len ) ++;  //Increase len of data
			(*data_out) = (*result); // get data out
			data_out ++; //Move data pointer to next pos
			result ++;  //Move result pointer to next buffer pos
		}

		return 0;
	}
	return 1;
}

void uart_cmd_cb_default(uart_cmd_t* cmd)
{

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  HAL_UART_Receive_IT(&huart2, Rx_data, 1);
}
uart_cmd_cb_t uart_cmd_cb = uart_cmd_cb_default;
uint16_t chr_count = 0;
void uart_cmd_task(void)
{

	if((HAL_UART_Receive_IT(&huart2, &uart_cmd_buf[chr_count], 1)) == HAL_OK)
	{
		if(uart_cmd_buf[chr_count] == 0x0A || uart_cmd_buf[chr_count] == 0x0D) //Meet enter
		{
			chr_count = 0;
			//
		}
		chr_count ++;
	}
}

void uart_cmd_init(void* cmd_cb)
{
	if(cmd_cb != NULL) uart_cmd_cb = cmd_cb;
	event_add(uart_cmd_task,&uart_cmd_id,10);
	event_active(&uart_cmd_id);
}
