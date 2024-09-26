/*
 * PCF8574.h
 *
 *  Created on: Sep 26, 2024
 *      Author: 13088
 */

#ifndef PCF8574_H_
#define PCF8574_H_

#include <stdint.h>

#define PCF8574_ADDR	(0x40)		// 7位地址

void PCF8574_init(void);

uint8_t PCF8574_set_output(uint8_t value);

uint8_t PCF8574_get_output(uint8_t *value);

uint8_t PCF8574_set_bit(uint8_t offset, uint8_t state);

#endif /* PCF8574_H_ */
