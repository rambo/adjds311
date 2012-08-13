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

    Serial.println(F("Booted"));
}


void loop()
{
    if (color.read_data())
    {
        Serial.print(F("Red 0x"));
        Serial.println(color.color_values[0], HEX);
        Serial.print(F("Green 0x"));
        Serial.println(color.color_values[1], HEX);
        Serial.print(F("Blue 0x"));
        Serial.println(color.color_values[2], HEX);
        Serial.print(F("Clear 0x"));
        Serial.println(color.color_values[3], HEX);

        Serial.print(F("Red offset 0x"));
        Serial.println(color.offset_values[0], HEX);
        Serial.print(F("Green offset 0x"));
        Serial.println(color.offset_values[1], HEX);
        Serial.print(F("Blue offset 0x"));
        Serial.println(color.offset_values[2], HEX);
        Serial.print(F("Clear offset 0x"));
        Serial.println(color.offset_values[3], HEX);
    }
    else
    {
        Serial.println(F("Color acquire failed"));
    }
    
    /*
    // Dump device registers and wait 5sek
    Serial.println(F("=== Dump ==="));
    color.dump_registers(0x0, 0x4b);
    Serial.println(F("=== Done ==="));
    */

    delay(1000);
}
