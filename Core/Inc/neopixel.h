/*
 * neopixel.h
 *
 *  Created on: Aug 26, 2024
 *      Author: kyoro
 */

#ifndef BASICFUNCTIONS_INC_NEOPIXEL_H_
#define BASICFUNCTIONS_INC_NEOPIXEL_H_

#include "tim.h"
#include "stdint.h"

void UpdateNeoPixel(uint16_t r,uint16_t g,uint16_t b);
void SetNeoPixel(uint16_t r,uint16_t g,uint16_t b);

#endif /* BASICFUNCTIONS_INC_NEOPIXEL_H_ */
