/*
 * TMP461.h
 *
 *  Created on: Feb 4, 2020
 *      Author: marisa
 */

#ifndef SRC_PERIPHERALS_TMP461_H_
#define SRC_PERIPHERALS_TMP461_H_

#include "stm32l0xx_hal.h"

class TMP461 {
public:
	TMP461(I2C_HandleTypeDef handle, uint16_t i2c_address);
	virtual ~TMP461();

	int readTemp(void);

private:
	I2C_HandleTypeDef i2c_handle;
	uint16_t i2c_address;
};

#endif /* SRC_PERIPHERALS_TMP461_H_ */
