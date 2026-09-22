#include "gamepad_logic.h"
#include "gamepad_io.h"

#define HAT_NEUTRAL 8

static uint8_t ResolveHat(void) {
	uint8_t up		= GamepadIO_IsPressed(BTN_UP);
	uint8_t down	= GamepadIO_IsPressed(BTN_DOWN);
	uint8_t left	= GamepadIO_IsPressed(BTN_LEFT);
	uint8_t right	= GamepadIO_IsPressed(BTN_RIGHT);

	//SOCD cleaning - opposing pairs resolve to neutral
	if(up && down) {up = 0; down = 0;}
	if(left && right) {left = 0; right = 0;}

	if(up && right) 	return 1;
	if(down && right)	return 3;
	if(down && left)	return 5;
	if(up && left)		return 7;
	if(up)				return 0;
	if(right)			return 2;
	if(down)			return 4;
	if(left)			return 6;

	return HAT_NEUTRAL;
}

void GamepadLogic_Resolve(GamepadReport_t *report) {
	uint8_t hat = ResolveHat();

	uint16_t buttons = 0;
	if (GamepadIO_IsPressed(BTN_B01))    buttons |= (1 << 0);
	if (GamepadIO_IsPressed(BTN_B02))    buttons |= (1 << 1);
	if (GamepadIO_IsPressed(BTN_B03))    buttons |= (1 << 2);
	if (GamepadIO_IsPressed(BTN_B04))    buttons |= (1 << 3);
	if (GamepadIO_IsPressed(BTN_B05))    buttons |= (1 << 4);
	if (GamepadIO_IsPressed(BTN_B06))    buttons |= (1 << 5);
	if (GamepadIO_IsPressed(BTN_B07))    buttons |= (1 << 6);
	if (GamepadIO_IsPressed(BTN_B08))    buttons |= (1 << 7);
	if (GamepadIO_IsPressed(BTN_B09))    buttons |= (1 << 8);
	if (GamepadIO_IsPressed(BTN_START))  buttons |= (1 << 9);
	if (GamepadIO_IsPressed(BTN_SELECT)) buttons |= (1 << 10);

	report->bytes[0] = hat & 0x0F;
	report->bytes[1] = (uint8_t)(buttons & 0xFF);
	report->bytes[2] = (uint8_t)((buttons >> 8) & 0x07);
}


