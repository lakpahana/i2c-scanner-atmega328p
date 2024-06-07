# I2C SCANNER ATMEGA328P

I2C protocol is a popular communication protocol used to communicate between microcontrollers and peripheral devices. 

Each I2C device has a unique 7-bit or 10-bit address. For most common applications, the 7-bit addressing scheme is used.

So in here i scan addresses from 0x08 to 0x77 and print the address of the device connected to the I2C bus.

## Hardware Tested

1. ATmega328P microcontroller ( Arduino Uno board )
2. I2C device (16x2 LCD)
3. LED (for debugging, if found a device it will turn on)

## Notes on Arduino Uno I2C pins

1. SDA - A4
2. SCL - A5

## Notes on ATmega328P I2C pins

1. SDA - PC4
2. SCL - PC5

## Register Description

1. TWCR - TWI Control Register
2. TWDR - TWI Data Register
3. TWSR - TWI Status Register
4. TWBR - TWI Bit Rate Register
5. TWAR - TWI Address Register
6. TWAMR - TWI Address Mask Register


## Sources

https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf

Page 173


