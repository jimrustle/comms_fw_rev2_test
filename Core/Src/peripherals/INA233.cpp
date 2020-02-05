/*
 * INA233.cpp
 *
 *  Created on: Feb 4, 2020
 *      Author: marisa
 */

/* datasheet: https://www.ti.com/lit/ds/sbos790/sbos790.pdf */

/* PMBUS operation:
 *
 * Writing to the device begins with the first byte transmitted by the master. This byte is the slave address with the
 * R/W bit low. The device then acknowledges receipt of a valid address. The next byte transmitted by the master is
 * the PMBus command address to the register that data are written to. This command address value updates the
 * register pointer to the desired register. The next two bytes are written to the register addressed by the PMBus
 * command. The device acknowledges receipt of each data byte. The master can terminate data transfer by
 * generating a START or STOP condition.
 *
 * The timing structure for SEND BYTE commands is the same as WRITE WORD commands except no data
 * packets are sent.
 *
 * When reading from the device, first the device is written to with the desired PMBus command that is to return the
 * desired value. This write is accomplished by issuing a slave address byte with the R/W bit low, followed by the
 * PMBus command code. No additional data are required. The master then generates a repeated START
 * condition and sends the slave address byte with the R/W bit high to initiate the read command. The next byte is
 * transmitted by the slave and is the most significant byte of the register indicated by the register pointer. This byte
 * is followed by an Acknowledge (ACK) from the master; then the slave transmits the least significant byte. The
 * master acknowledges receipt of the data byte. The master can terminate data transfer by generating a NotAcknowledge after receiving any data byte, or by generating a START or STOP condition. If repeated reads from
 * the same register are desired, the register pointer bytes do not have to be continually sent; the device retains the
 * register pointer value until the value is changed by the next write operation.
 *
 * The READ BYTE format has the same timing structure as the READ WORD format except a byte of data is
 * returned instead of a word.
 *
 */

#include "INA233.h"

INA233::INA233(I2C_HandleTypeDef handle, uint16_t i2c_addr) {
	i2c_handle = handle;
	i2c_address = i2c_addr;
}

INA233::~INA233() {
	// TODO Auto-generated destructor stub
}


float INA233::readCurrent(void) {
	float current = 0;

	current =

	HAL_Delay(500);

	return current;
}
