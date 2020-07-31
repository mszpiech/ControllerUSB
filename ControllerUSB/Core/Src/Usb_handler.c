/*
 * Usb_handler.c
 *
 *  Created on: 30 lip 2020
 *      Author: mateu
 */

#include "Usb_handler.h"
#include "RingBuffer.h"

uint8_t gUsbReceiveBuffer[USB_RECEIVE_BUFFER_SIZE];
uint8_t gUsbTransmitBuffer[USB_TRANSMIT_BUFFER_SIZE];

uint8_t fReceivedData = 0;

ringBuffer_t gRingBufferReceive;

/* USER CODE BEGIN Header_StartUsbReceiver */
/**
  * @brief  Function implementing the UsbReceiver thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartUsbReceiver */


void StartUsbReceiver(void * atributes)
{
  MX_USB_DEVICE_Init();
  //InitRingBuffer(gRingBufferReceive,gUsbReceiveBuffer,USB_RECEIVE_BUFFER_SIZE);
  for(;;)
  {
	if(fReceivedData == 1)
	{

	}
    HAL_Delay(1000);
  }
}

void Set_fReceivedData(uint8_t value)
{
	fReceivedData = value;
}

uint8_t Get_fReceivedData(void)
{
	return fReceivedData;
}

uint8_t * Get_gUsbReceiveBuffer(void)
{
	return gUsbReceiveBuffer;
}


