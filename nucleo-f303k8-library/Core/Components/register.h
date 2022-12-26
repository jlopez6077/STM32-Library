/*
 * register.h
 *
 *  Created on: Dec 25, 2022
 *      Author: jlopez6077
 *
 * This is for the 74HC595 Shift Register
 * Utilizes SPI
 * Mode = Transmit Only Master
 * Data Size = 8 bits
 * First Bit = MSB First
 */

#ifndef COMPONENTS_REGISTER_H_
#define COMPONENTS_REGISTER_H_

// 74HC595 IC REGISTER PINS
#define STORAGE_REGISTER_CLOCK_PIN GPIO_PIN_6	// PA6
#define MASTER_CLEAR_PIN GPIO_PIN_4				// PA4
#define REGISTER_PORT GPIOA						// GPIOA

#define BYTE_SIZE 1								// Data Size

void sendSPIdata(SPI_HandleTypeDef hspi1, uint8_t data[])
/*
 * @param  hspi to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 * @param  Data address to data buffer
 */
{
	// clear the shift register buffer
	HAL_GPIO_WritePin(REGISTER_PORT, MASTER_CLEAR_PIN, GPIO_PIN_RESET);	// Low Active

	// open shift register buffer
	HAL_GPIO_WritePin(REGISTER_PORT, MASTER_CLEAR_PIN, GPIO_PIN_SET);

	// transmit data
	HAL_SPI_Transmit(&hspi1, &data[0], BYTE_SIZE, 10); 					//controls SPI1_MOSI and SPI1_SCLK

	// parallel load into storage register
	HAL_GPIO_WritePin(REGISTER_PORT, STORAGE_REGISTER_CLOCK_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(REGISTER_PORT, STORAGE_REGISTER_CLOCK_PIN, GPIO_PIN_RESET);
}


#endif /* COMPONENTS_REGISTER_H_ */
