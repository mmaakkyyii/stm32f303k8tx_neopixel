/*
 * neopixel.cpp
 *
 *  Created on: Aug 26, 2024
 *      Author: kyoro
 */


#include "neopixel.h"
#include "string.h"

#define LED_NUM 10
const int RESET_NUM=100;

uint16_t LED_data[LED_NUM][3]={0};
uint32_t rgb[100+LED_NUM*3*8]={0};

void SetNeoPixel(uint16_t r,uint16_t g,uint16_t b){
//*
	const int PWM_H=9;
	const int PWM_L=3;
	const int PWM_RESET=0;

	memset(rgb,0,sizeof(rgb));

	rgb[0]=12;
	for(int i=1;i<RESET_NUM;i++){
		rgb[i]=PWM_RESET;
	}
	for(int i=0;i<LED_NUM;i++){
		for(int k=7;k>=0;k--){
			if((LED_data[i][0]>>k)&0x01){
				rgb[RESET_NUM+(i*3)*8 +0+(7-k)]=PWM_H;
			}else{
				rgb[RESET_NUM+(i*3)*8 +0+(7-k)]=PWM_L;
			}

			if((LED_data[i][1]>>k)&0x01){
				rgb[RESET_NUM+(i*3)*8 +8+(7-k)]=PWM_H;
			}else{
				rgb[RESET_NUM+(i*3)*8 +8+(7-k)]=PWM_L;
			}

			if((LED_data[i][2]>>k)&0x01){
				rgb[RESET_NUM+(i*3)*8 +16+(7-k)]=PWM_H;
			}else{
				rgb[RESET_NUM+(i*3)*8 +16+(7-k)]=PWM_L;
			}
		}
	}

//	HAL_GPIO_WritePin(GPIO15_GPIO_Port, GPIO15_Pin, GPIO_PIN_SET);
	HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_1, (uint32_t*)rgb, RESET_NUM+24*LED_NUM);

//*/
}
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_1);
}
void UpdateNeoPixel(uint16_t r,uint16_t g,uint16_t b){
//*
	//	uint16_t data[15][3];
	static int t=0;
	memset(LED_data,0,sizeof(LED_data));

	for(int i=0;i<LED_NUM;i++){
		LED_data[i][0]=r;
		LED_data[i][1]=g;
		LED_data[i][2]=b;
	}

	SetNeoPixel(0,0,0);

//*/
}


