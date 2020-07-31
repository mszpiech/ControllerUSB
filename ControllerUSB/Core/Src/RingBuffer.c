/*
 * RingBuffer.c
 *
 *  Created on: 31 lip 2020
 *      Author: Mateusz Szpiech
 */

#include "RingBuffer.h"




void InitRingBuffer(ringBuffer_t ringBuffer, uint8_t * buffer, uint32_t bufferSize)
{
	ringBuffer.buffer = buffer;
	ringBuffer.bufferSize = bufferSize;
	ringBuffer.first_free = buffer;
	ringBuffer.start_data = buffer;
}

uint32_t GetRingBufferActualSize(ringBuffer_t ringBuffer)
{
	uint32_t ActualSize = 0;

	if(ringBuffer.first_free >= ringBuffer.start_data)
	{
		ActualSize = ringBuffer.first_free - ringBuffer.start_data;
	}
	else
	{
		ActualSize = ringBuffer.bufferSize - (ringBuffer.start_data - ringBuffer.first_free);
	}

	return ActualSize;
}

uint32_t GetRingBufferFreeSpaceSize(ringBuffer_t ringBuffer)
{
	return ringBuffer.bufferSize-GetRingBufferActualSize(ringBuffer);
}

uint32_t AddToBuffer(ringBuffer_t ringBuffer, uint8_t * data, uint32_t dataSize)
{
	if(GetRingBufferFreeSpaceSize(ringBuffer) >= dataSize)
	{
		for (int i = 0; i<dataSize; i++)
		{
			*ringBuffer.first_free = data[i];
			if(ringBuffer.first_free == ringBuffer.buffer + ringBuffer.bufferSize)
			{
				ringBuffer.first_free = ringBuffer.buffer;
			}
			else
			{
				ringBuffer.first_free++;
			}
		}
		return dataSize;
	}
	else
	{
		return 0; //To many data
	}
}

uint32_t GetFromBuffer(ringBuffer_t ringBuffer, uint8_t * data, uint32_t dataSize)
{
	if(GetRingBufferActualSize(ringBuffer) < dataSize)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i<dataSize; i++)
		{
			data[i] = *ringBuffer.start_data;
			if(ringBuffer.start_data == ringBuffer.buffer + ringBuffer.bufferSize)
			{
				ringBuffer.start_data = ringBuffer.buffer;
			}
			else
			{
				ringBuffer.start_data++;
			}
		}
	}
	return 0;
}











