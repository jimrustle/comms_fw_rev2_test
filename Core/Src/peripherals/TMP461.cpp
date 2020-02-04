/*
 * TMP461.cpp
 *
 *  Created on: Feb 4, 2020
 *      Author: marisa
 */

#include "TMP461.h"

TMP461::TMP461(I2C_HandleTypeDef handle, uint16_t i2c_addr) {
	i2c_handle = handle;
	i2c_address = i2c_addr;
}

TMP461::~TMP461() {
	// TODO Auto-generated destructor stub
}

int TMP461::readTemp(void) {
	float temp_c = 0;
	int val = 0;
	uint8_t buf0[] = {0, 0};
	// Tell TMP102 that we want to read from the temperature register
	int ret = HAL_I2C_Master_Transmit(&i2c_handle, i2c_address, buf0, 1, HAL_MAX_DELAY);

	if ( ret != HAL_OK ) {
		//strcpy((char*)buf, "Error Tx\r\n");
	} else {
		// Read 2 bytes from the temperature register
		ret = HAL_I2C_Master_Receive(&i2c_handle, i2c_address, buf0, 2, HAL_MAX_DELAY);

		if ( ret != HAL_OK ) {
			//strcpy((char*)buf, "Error Rx\r\n");
		} else {
			//Combine the bytes
			val = (buf0[0] << 4) | (buf0[1] >> 4);

			// Convert to 2's complement, since temperature can be negative
			if ( val > 0x7FF ) {
				val |= 0xF000;
			}

			// Convert to float temperature value (Celsius)
			temp_c = val * 0.0625;

			// Convert temperature to decimal format
			temp_c *= 100;
			//sprintf((char*)buf, "%u.%u C\r\n", ((unsigned int)temp_c / 100), ((unsigned int)temp_c % 100));
		}
	}

	// Wait
	HAL_Delay(500);

	return (int) temp_c;
}
