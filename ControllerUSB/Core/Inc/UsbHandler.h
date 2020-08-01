/*
 * Usb_handler.h
 *
 *  Created on: 30 lip 2020
 *      Author: Mateusz Szpiech
 */

#include "stm32f4xx_hal.h"
#include "usbd_cdc_if.h"
#include "usb_device.h"
#include "RingBuffer.h"

#ifndef INC_USB_HANDLER_H_
#define INC_USB_HANDLER_H_

#define USB_RECEIVE_BUFFER_SIZE 5
#define USB_TRANSMIT_BUFFER_SIZE 5

typedef struct usbQueueElement
{

}usbQueueElement_t;

typedef struct usbQueue
{
	usbQueueElement_t * firstElement;
	uint32_t queueSize;
}usbQueue_t;

void StartUsbReceiver(void * atributes);
void EchoRingBuffer(ringBuffer_t * ringBuffer);
ringBuffer_t * Get_gRingBufferReceive(void);

#endif /* INC_USB_HANDLER_H_ */
