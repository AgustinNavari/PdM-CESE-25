#include "API_uart.h"
#include "stm32f4xx_hal.h"
#include <stdbool.h>

static UART_HandleTypeDef huart2;

static char errorMsg[] = "ERROR";

bool uartInit(void) // configuracion de la UART
{
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;

  char uartConfigStr[] = "UART2: 115200 baudios, 8N1, TX/RX\r\n"; //se imprime la configuracion de la UART de forma manual

  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    return false;
  }

  uartSendString((uint8_t*)uartConfigStr);

  return true;

}



void uartSendString(uint8_t * pstring){

	if (pstring != NULL){
		uint32_t i=0;
		char end='b';
		do{
			end=pstring[i];
			i++;
		}while(end!='\0');

		HAL_UART_Transmit(&huart2, pstring, i-1, HAL_MAX_DELAY); // cuando se encuentra un \0 se envia el string
		i = 0;
	}else{
		HAL_UART_Transmit(&huart2, (uint8_t*)errorMsg, 6, HAL_MAX_DELAY); // en caso de un error se envia un mensaje de ERROR
	}


}


void uartSendStringSize(uint8_t * pstring, uint16_t size){

	if ((pstring != NULL)&&(size < MAX_BUFFER)){
		HAL_UART_Transmit(&huart2, pstring, size, HAL_MAX_DELAY);
	}else{
		HAL_UART_Transmit(&huart2, (uint8_t*)errorMsg, 6, HAL_MAX_DELAY); // en caso de un error se envia un mensaje de ERROR
	}

}

void uartReceiveStringSize(uint8_t * pstring, uint16_t size){
	if ((pstring != NULL)&&(size < MAX_BUFFER)){
		HAL_UART_Receive(&huart2, pstring, size, HAL_MAX_DELAY);
	}else{
		HAL_UART_Transmit(&huart2, (uint8_t*)errorMsg, 6, HAL_MAX_DELAY); // en caso de un error se envia un mensaje de ERROR
	}

}
