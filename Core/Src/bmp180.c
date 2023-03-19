/*
 * bmp180.c
 *
 *  Created on: Oct 9, 2022
 *      Author: sezin
 */

#include "bmp180.h"


void BMP180_Init(){
	if(HAL_I2C_IsDeviceReady(&hi2c1, BMP180_DEVICE_WRITE_REGISTER_ADDRESS, 1, 100000)!=HAL_OK){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
	}

	BMP180_Get_Calibration_Value();
}

void BMP180_Get_Calibration_Value(){

	int a=0;

	uint8_t calibBuff[BMP180_CALIBRATION_VALUE_LENGTH] = {0};

	HAL_I2C_Mem_Read(&hi2c1, BMP180_DEVICE_WRITE_REGISTER_ADDRESS, BMP180_CALIBRATION_START_ADDRESS, 1, calibBuff, BMP180_CALIBRATION_VALUE_LENGTH, 100000);

	AC1 = (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]);		a+=2;
	AC2 = (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]);		a+=2;
	AC3 = (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]);		a+=2;
	AC4 = (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]);		a+=2;
	AC5 = (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]);		a+=2;
	AC6 = (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]);		a+=2;
	B1  = (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]);		a+=2;
	B2  = (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]);		a+=2;
	MB  = (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]);		a+=2;
	MC  = (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]);		a+=2;
	MD  = (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]);		a+=2;

	if(AC1==0x0000 | AC1==0xFFFF){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		while(1);
	}
	if(AC2==0x0000 | AC2==0xFFFF){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		while(1);
	}
	if(AC3==0x0000 | AC3==0xFFFF){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		while(1);
	}
	if(AC4==0x0000 | AC4==0xFFFF){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		while(1);
	}
	if(AC5==0x0000 | AC5==0xFFFF){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		while(1);
	}
	if(AC6==0x0000 | AC6==0xFFFF){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		while(1);
	}
	if(B1==0x0000 | B1==0xFFFF){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		while(1);
	}
	if(B2==0x0000 | B2==0xFFFF){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		while(1);
	}
	if(MB==0x0000 | MB==0xFFFF){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		while(1);
	}
	if(MC==0x0000 | MC==0xFFFF){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		while(1);
	}
	if(MD==0x0000 | MD==0xFFFF){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		while(1);
	}


}


float BMP180_Get_Temperature(void){

	BMP180_Get_Uncompansated_Temperature();

	tX1 = (((int32_t)unCompTemperature - AC6) * (int32_t)AC5) / 32768;
	tX2 = ((int32_t)MC * 2048) / (tX1 + (int32_t)MD);
	if(tX1 == 0 && MD == 0){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		while(1);
	}
	tB5 = tX1 + tX2;
	temperature = (float)((float)(tB5 + 8) / 16) / 10;
	return temperature;
}

void BMP180_Get_Uncompansated_Temperature(void){
	uint8_t rData[2] = {0};
	uint8_t wData[1];
	wData[0]=0x2E;

	HAL_I2C_Mem_Write(&hi2c1, BMP180_DEVICE_WRITE_REGISTER_ADDRESS, 0xF4, 1, wData, 1, 100000);
	HAL_Delay(500);
	HAL_I2C_Mem_Read(&hi2c1, BMP180_DEVICE_READ_REGISTER_ADDRESS, 0xF6, 1, rData, 2, 100000);
	unCompTemperature = (int16_t) ((rData[0] << 8) | rData[1]);

}
