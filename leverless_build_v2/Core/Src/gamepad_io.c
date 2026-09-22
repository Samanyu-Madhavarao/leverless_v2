#include "gamepad_io.h"
#include "main.h"

typedef struct {
	GPIO_TypeDef *port;
	uint16_t pin;
}ButtonPin_t;

static const ButtonPin_t buttonPins[BTN_COUNT] = {
    [BTN_B01]    = {B01_GPIO_Port,    B01_Pin},
    [BTN_B02]    = {B02_GPIO_Port,    B02_Pin},
    [BTN_B03]    = {B03_GPIO_Port,    B03_Pin},
    [BTN_B04]    = {B04_GPIO_Port,    B04_Pin},
    [BTN_B05]    = {B05_GPIO_Port,    B05_Pin},
    [BTN_B06]    = {B06_GPIO_Port,    B06_Pin},
    [BTN_B07]    = {B07_GPIO_Port,    B07_Pin},
    [BTN_B08]    = {B08_GPIO_Port,    B08_Pin},
    [BTN_B09]    = {B09_GPIO_Port,    B09_Pin},
    [BTN_UP]     = {UP_GPIO_Port,     UP_Pin},
    [BTN_DOWN]   = {DOWN_GPIO_Port,   DOWN_Pin},
    [BTN_LEFT]   = {LEFT_GPIO_Port,   LEFT_Pin},
    [BTN_RIGHT]  = {RIGHT_GPIO_Port,  RIGHT_Pin},
    [BTN_START]  = {START_GPIO_Port,  START_Pin},
    [BTN_SELECT] = {SELECT_GPIO_Port, SELECT_Pin},
};

#define DEBOUNCE_STABLE_COUNT 4

static uint8_t debouncedState[BTN_COUNT];
static uint8_t candidateState[BTN_COUNT];
static uint8_t candidateCount[BTN_COUNT];

void GamepadIO_Init(void) {
	for(int i = 0; i < BTN_COUNT; i++) {
		debouncedState[i] = 0;
		candidateState[i] = 0;
		candidateCount[i] = 0;
	}
}

void GamepadIO_Poll(void) {
	for(int i = 0; i < BTN_COUNT; i++) {
		uint8_t rawPressed = (HAL_GPIO_ReadPin(buttonPins[i].port, buttonPins[i].pin) == GPIO_PIN_RESET) ? 1 : 0;

		if(rawPressed == candidateState[i]) {
			if(candidateCount[i] < DEBOUNCE_STABLE_COUNT) {
				candidateCount[i]++;
			}
			if(candidateCount[i] >= DEBOUNCE_STABLE_COUNT) {
				debouncedState[i] = candidateState[i];
			}
		} else {
			candidateState[i] = rawPressed;
			candidateCount[i] = 1;
		}
	}
}

uint8_t GamepadIO_IsPressed(GamepadButton_t btn) {
	return debouncedState[btn];
}

