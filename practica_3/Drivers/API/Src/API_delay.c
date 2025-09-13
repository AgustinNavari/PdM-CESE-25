#include "API_delay.h"
#include "stm32f4xx_hal.h"

void delayInit(delay_t * delay, tick_t duration){

	//delay->startTime = 0;
	delay->duration = duration;
	delay->running = false;

}

bool_t delayRead(delay_t * delay){

	if (delay->running == false){
		delay->startTime = HAL_GetTick();
		delay->running = true;
	}

	if ((delay->running == true) && (HAL_GetTick() - delay->startTime > delay->duration)){

		delay->running = false;
		return true; //si paso el tiempo devuelve "true"

	}else{
		return false; //si aun no paso el tiempo devuelve "false"
	}
}

void delayWrite(delay_t * delay, tick_t duration){
	delay->duration = duration;
}

bool_t delayIsRunning(delay_t * delay){
	return delay->running;
}
