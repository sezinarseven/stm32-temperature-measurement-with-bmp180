/*
 * bmp180.h
 *
 *  Created on: Oct 9, 2022
 *      Author: sezin
 */

#ifndef INC_BMP180_H_
#define INC_BMP180_H_

#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;


#define BMP180_DEVICE_WRITE_REGISTER_ADDRESS	0XEE
#define BMP180_DEVICE_READ_REGISTER_ADDRESS		0XEF

#define BMP180_CALIBRATION_START_ADDRESS 0xAA
#define BMP180_CALIBRATION_VALUE_LENGTH 22

// Calibration Values
int16_t AC1;
int16_t AC2;
int16_t AC3;
int16_t AC4;
int16_t AC5;
int16_t AC6;
int16_t B1;
int16_t B2;
int16_t MB;
int16_t MC;
int16_t MD;

// Temperature Values
int16_t unCompTemperature;
float temperature;
int32_t tX1,tX2,tB5;

void BMP180_Init(void);
void BMP180_GetCalibration(void);
void BMP180_Get_Calibration_Value(void);
void BMP180_Get_Uncompansated_Temperature(void);
float BMP180_Get_Temperature(void);
void BMP180_Get_Uncompansated_Pressure(void);
float BMP180_Get_Pressure(void);

#endif /* INC_BMP180_H_ */
