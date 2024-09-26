/*
 * PCF8574.c
 *
 *  Created on: Sep 26, 2024
 *      Author: 13088
 */

#include "PCF8574.h"
#include "i2c.h"
#include "main.h"

#include <stdio.h>

void PCF8574_init(void) {
	uint8_t data = 0xFF;
	uint8_t state = HAL_I2C_Master_Transmit(&hi2c2, PCF8574_ADDR, &data, 1, 100);

	printf("PCF8574_init()   state = [%d] \r\n", state);

	// test
//	state = PCF8574_set_output(0x55);
//	printf("PCF8574_set_output(0x55)   state = [%d] \n", state);
//
//
//	state = PCF8574_get_output(&data);
//	printf("PCF8574_get_output(&data)   state = [%d] data = [%d]\n", state, data);
//
//	state = PCF8574_set_bit(0, 0);
//
//	state = PCF8574_get_output(&data);
//	printf("PCF8574_get_output(&data)   state = [%d] data = [%d]\n", state, data);
}

uint8_t PCF8574_set_output(uint8_t value) {
	uint8_t state = HAL_I2C_Master_Transmit(&hi2c2, PCF8574_ADDR, &value, 1, 100);

	printf("PCF8574_output()   state = [%d] \r\n", state);
	return state;
}


uint8_t PCF8574_get_output(uint8_t *value) {
	uint8_t state = HAL_I2C_Master_Receive(&hi2c2, PCF8574_ADDR, value, 1, 100);
	printf("PCF8574_get_output(&data)   state = [%d] value = [%d]\\rn", state, *value);
	return state;
}

uint8_t PCF8574_set_bit(uint8_t offset, uint8_t state) {
	if (offset > 7)
		return 1;

	uint8_t data;
	if (HAL_I2C_Master_Receive(&hi2c2, PCF8574_ADDR, &data, 1, 100) != HAL_OK)
		return 1;

	if (state) {
		data |= (0x01 << offset);
	} else {
		data &= ~(0x01 << offset);
	}

	return HAL_I2C_Master_Transmit(&hi2c2, PCF8574_ADDR, &data, 1, 100);
}
