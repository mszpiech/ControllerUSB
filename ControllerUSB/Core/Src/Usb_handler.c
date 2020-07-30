/*
 * Usb_handler.c
 *
 *  Created on: 30 lip 2020
 *      Author: mateu
 */

#include "Usb_handler.h"
#include "usb_device.h"

/* USER CODE BEGIN Header_StartUsbReceiver */
/**
  * @brief  Function implementing the UsbReceiver thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartUsbReceiver */
void StartUsbReceiver(void)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    HAL_Delay(1000);
  }
  /* USER CODE END 5 */
}
