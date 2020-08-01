/*
 * RingBuffer.h
 *
 *  Created on: 31 lip 2020
 *      Author: Mateusz Szpiech
 */

#ifndef INC_RINGBUFFER_H_
#define INC_RINGBUFFER_H_
#include "stm32f4xx_hal.h"

typedef enum
{
  BUFFER_OK = 0U,
  TO_BIG_FRAME,
  BUFFER_FULL,
} ringBufferStatus_t;

typedef struct ringBuffer
{
	uint8_t * buffer; //buffer table

	uint32_t bufferSize;

	uint8_t *first_free;
	uint8_t *start_data;

	ringBufferStatus_t status;
}ringBuffer_t;

void InitRingBuffer(ringBuffer_t * ringBuffer, uint8_t * buffer, uint32_t buffeSize);
uint32_t GetRingBufferActualSize(ringBuffer_t * ringBuffer);
uint32_t GetRingBufferFreeSpaceSize(ringBuffer_t * ringBuffer);
uint32_t AddToBuffer(ringBuffer_t * ringBuffer, uint8_t * data, uint32_t dataSize);
uint32_t GetFromBuffer(ringBuffer_t * ringBuffer, uint8_t * data, uint32_t dataSize);


#endif /* INC_RINGBUFFER_H_ */
