#include "API_delay.h"
#include "API_debounce.h"
#include "stm32f4xx_hal.h"


static const uint32_t debounceDelay = 40; // determina el tiempo de duracion del delay
static delay_t debounce; // delay
static pinState_t pin; // contiene el estado del pin
static debounceState_t debounceState;

static bool_t buttonState = false;

// debounceFSM_init carga el estado inicial en BUTTON_UP
void debounceFSM_init(){
	debounceState = BUTTON_UP;
}

// debounceFSM_update maneja los cambios de estado
void debounceFSM_update(){

	pin = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin); // lee el estado del pin

	switch(debounceState){
		case BUTTON_UP:

			if(!pin){
				debounceState = BUTTON_FALLING;
				delayInit(&debounce,debounceDelay);
				delayRead(&debounce);
			}
			break;

		case BUTTON_FALLING:

			if(delayRead(&debounce)==true){
				pin = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
				if(!pin){										// si paso el tiempo y el boton continua apretado, se enciende el LED y cambia al estado BUTTON_DOWN
					buttonState = true; 						// buttonState se hace true cuando se confirma que el boton esta presionado
					debounceState = BUTTON_DOWN;
				}else{debounceState = BUTTON_UP;}
			}

			break;

		case BUTTON_DOWN:

			if(pin){
				debounceState = BUTTON_RAISING;
				delayInit(&debounce,debounceDelay);
				delayRead(&debounce);
			}

			break;

		case BUTTON_RAISING:

			if(delayRead(&debounce)==true){
				pin = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
				if(pin){										// si paso el tiempo y el boton continua suelto, se apaga el LED y cambia al estado BUTTON_UP
					debounceState = BUTTON_UP;
				}else{
					debounceState = BUTTON_DOWN;
				}
			}

			break;

		default:
			debounceFSM_init();
			break;
	}
}

bool_t readKey(){												// readKey es una funcion publica a la que se le puede consultar por el estado del boton
	if(buttonState){
		buttonState = false;
		return true;
	}else{
		return false;
	}
}
