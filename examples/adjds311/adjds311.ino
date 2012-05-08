// Get this from https://github.com/rambo/I2C
#define I2C_DEVICE_DEBUG
#include <I2C.h> // For some weird reason including this in the relevant .h file does not work
#include <i2c_device.h> // For some weird reason including this in the relevant .h file does not work
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

    color.begin();

    Serial.println("Booted");
}


void loop()
{
    // Dump device registers and wait 5sek
    Serial.println("=== Dump ===");
    color.dump_registers(0x0, 0x47);
    Serial.println("=== Done ===");

    delay(15000);
}
