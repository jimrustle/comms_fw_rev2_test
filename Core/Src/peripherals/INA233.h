/*
 * INA233.h
 *
 *  Created on: Feb 4, 2020
 *      Author: marisa
 */

#ifndef SRC_PERIPHERALS_INA233_H_
#define SRC_PERIPHERALS_INA233_H_

#include "stm32l0xx_hal.h"

class INA233 {
public:
	INA233(I2C_HandleTypeDef handle, uint16_t i2c_address);
	virtual ~INA233();

	float readCurrent(void);

private:
	I2C_HandleTypeDef i2c_handle;
	uint16_t i2c_address;
};

#endif /* SRC_PERIPHERALS_INA233_H_ */
