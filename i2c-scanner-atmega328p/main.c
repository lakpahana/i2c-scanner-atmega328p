/*
    *   main.c
    *   I2C Scanner
    *   Lakpahana A.G.S

 */

#include <avr/io.h>

int main(void)
{
    //First Initalize the I2C
    int cpu_clk = 16000000; //16MHz
    int i2c_clk = 100000;   //100KHz

    //Set the SCL frequency
    TWSR = 0; //Prescaler 1
    TWBR = ((cpu_clk / i2c_clk) - 16) / 2;

    //found led
    DDRB = 0xFF;
    PORTB = 0x00;


    uint8_t address;
    uint8_t status;

    while (1)
    {
        for (address = 1; address < 127; address++)
        {
            //Send Start
            TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN); //Start Condition
            while (!(TWCR & (1 << TWINT))); //Wait for TWINT Flag

            //From twint flag we can check the status of the I2C

            //Send Address
            TWDR = (address << 1); //Address is given by decimal value but it should be shifted by 1 bit to left
            TWCR = (1 << TWINT) | (1 << TWEN); //Clear TWINT Flag
            while (!(TWCR & (1 << TWINT)));

            //Check Status
            status = TWSR & 0xF8;
            if (status == 0x18)
            {
                //Device Found
                //Send Stop
                TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
                while (TWCR & (1 << TWSTO));

                //Turn on the LED
                PORTB = 0xFF;
                break;
                
            }
        

        
        }

    return 0;
}
}
