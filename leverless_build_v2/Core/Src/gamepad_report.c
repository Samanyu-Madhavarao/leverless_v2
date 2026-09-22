#include "gamepad_logic.h"
#include "usb_device.h"
#include "usbd_customhid.h"

extern USBD_HandleTypeDef hUsbDeviceFS;

void GamepadReport_Send(GamepadReport_t *report)
{
    USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, (uint8_t*)report, sizeof(GamepadReport_t));
}
