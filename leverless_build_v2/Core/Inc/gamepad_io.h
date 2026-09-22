#ifndef SRC_GAMEPAD_IO_H_
#define SRC_GAMEPAD_IO_H_

#include <stdint.h>

typedef enum {
	BTN_B01 = 0, BTN_B02, BTN_B03, BTN_B04, BTN_B05, BTN_B06, BTN_B07, BTN_B08, BTN_B09,
	BTN_UP, BTN_DOWN, BTN_LEFT, BTN_RIGHT, BTN_START, BTN_SELECT,
	BTN_COUNT
} GamepadButton_t;

void GamepadIO_Init(void);
void GamepadIO_Poll(void);
uint8_t GamepadIO_IsPressed(GamepadButton_t btn);

#endif
