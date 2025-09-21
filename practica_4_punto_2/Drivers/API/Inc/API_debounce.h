#include <stdbool.h>
#include <stdint.h>

#define LD2_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC

typedef bool pinState_t;
typedef bool bool_t;

typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RAISING,
}debounceState_t;

void debounceFSM_init();
void debounceFSM_update();
bool_t readKey();


