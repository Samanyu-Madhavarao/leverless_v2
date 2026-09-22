#ifndef SRC_GAMEPAD_LOGIC_H_
#define SRC_GAMEPAD_LOGIC_H_

#include <stdint.h>

typedef struct {
	uint8_t bytes[3];
} GamepadReport_t;

void GamepadLogic_Resolve(GamepadReport_t *report);

#endif
