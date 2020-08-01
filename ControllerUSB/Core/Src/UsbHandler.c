/*
 * Usb_handler.c
 *
 *  Created on: 30 lip 2020
 *      Author: mateu
 */

#include "UsbHandler.h"

uint8_t gUsbReceiveBuffer[USB_RECEIVE_BUFFER_SIZE];
uint8_t gUsbTransmitBuffer[USB_TRANSMIT_BUFFER_SIZE];



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
  InitRingBuffer(Get_gRingBufferReceive(),gUsbReceiveBuffer,USB_RECEIVE_BUFFER_SIZE);
  for(;;)
  {
	if(GetRingBufferActualSize(Get_gRingBufferReceive()) > 0)
	{
		EchoRingBuffer(Get_gRingBufferReceive());
	}
    HAL_Delay(10);
  }
}

void EchoRingBuffer(ringBuffer_t *ringBuffer)
{
	uint8_t * data = malloc(GetRingBufferActualSize(ringBuffer));

	GetFromBuffer(ringBuffer,data,GetRingBufferActualSize(ringBuffer));
	CDC_Transmit_HS(data, sizeof(data));
	free(data);
}

ringBuffer_t * Get_gRingBufferReceive(void)
{
	return &gRingBufferReceive;
}


