/*
 * Usb_handler.c
 *
 *  Created on: 30 lip 2020
 *      Author: mateu
 */

#include "Usb_handler.h"
#include "usb_device.h"

uint8_t gUsbReceiveBuffer[USB_RECEIVE_BUFFER_SIZE];
uint8_t gUsbTransmitBuffer[USB_TRANSMIT_BUFFER_SIZE];

/* USER CODE BEGIN Header_StartUsbReceiver */
/**
  * @brief  Function implementing the UsbReceiver thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartUsbReceiver */

static void AddToQueue(uint8_t buf, uint16_t len);


void StartUsbReceiver(void)
{
  MX_USB_DEVICE_Init();

  uint16_t len = 0;
  uint8_t * buf = gUsbReceiveBuffer;
  for(;;)
  {
	CDC_Receive_HS(buf,len);
	if(len > 0)
	{
		AddToQueue(buf,len);
		memset(buf,0,USB_RECEIVE_BUFFER_SIZE);
	}
    HAL_Delay(1000);
  }
}

static void AddToQueue(uint8_t buf, uint16_t len)
{

}
