# STM32-Library
Using the STM32 F303K8 Microcontroller, I created a library for different components.The library consists of functions that allow the microcontroller to interact with different hardware components. 

# List of components:
* Shifting Register 74HC595 IC 

# How to Use
1. Familize yourself with the component using the documentation 
2. Configure your STM Project as specificed by the documentation
3. Retrieve the files needed from the library
4. Run your Project

You will find it the files under "STM32-Library\nucleo-f303k8-library\Core\Components".

 
 # Example
You want to use the external 8-bit register in your project. By reading the documentation you know the pin layout and what configurations you need to make. You send the data through SPI. You retrieve register.h from the library and see this function:

```c
void sendSPIdata(SPI_HandleTypeDef hspi1, uint8_t data[])
/*
 * @param  hspi to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 * @param  Data address to data buffer
 */
 ```
 
 You pass the SPI structure that you created in your configurations and the data address. The output is register holding that 8-bit value. 