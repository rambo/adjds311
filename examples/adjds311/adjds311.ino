// Get this from https://github.com/rambo/I2C
#define I2C_DEVICE_DEBUG
#include <I2C.h> // For some weird reason including this in the relevant .h file does not work
#include <i2c_device.h> // For some weird reason including this in the relevant .h file does not work
#define ADJDS311_LED_PIN 12
#include <adjds311.h>

// Container for the device
adjds311 color;


void setup()
{
    Serial.begin(115200);
    // Initialize I2C library manually
    I2c.begin();
    I2c.timeOut(500);
    I2c.pullup(true);

    // Scan the bus
    //I2c.scan();

    // initialize the board
    color.begin();
    color.set_trim(true);

    Serial.println("Booted");
}


void loop()
{
    if (color.read_data())
    {
        Serial.print("Red 0x");
        Serial.println(color.color_values[0], HEX);
        Serial.print("Green 0x");
        Serial.println(color.color_values[1], HEX);
        Serial.print("Blue 0x");
        Serial.println(color.color_values[2], HEX);
        Serial.print("Clear 0x");
        Serial.println(color.color_values[3], HEX);

        Serial.print("Red offset 0x");
        Serial.println(color.offset_values[0], HEX);
        Serial.print("Green offset 0x");
        Serial.println(color.offset_values[1], HEX);
        Serial.print("Blue offset 0x");
        Serial.println(color.offset_values[2], HEX);
        Serial.print("Clear offset 0x");
        Serial.println(color.offset_values[3], HEX);
    }
    else
    {
        Serial.println("Color acquire failed");
    }
    
    /*
    // Dump device registers and wait 5sek
    Serial.println("=== Dump ===");
    color.dump_registers(0x0, 0x4b);
    Serial.println("=== Done ===");
    */

    delay(1000);
}
