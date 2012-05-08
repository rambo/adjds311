// safety againts double-include
#ifndef adjds311_h
#define adjds311_h
#include <Arduino.h> 
#include <i2c_device.h>
#ifndef ADJDS311_LED_PIN
#define ADJDS311_LED_PIN 13
#endif



class adjds311 : public i2c_device
{
    public:
        adjds311(); // We need this so we can set default address to the all-call
        
        // Multiple signatures to handle optional arguments
        void begin(byte dev_addr, boolean wire_begin);
        void begin(boolean wire_begin);
        void begin();

        boolean write_gains();
        boolean read_data();
        boolean read_color();
        boolean read_offset();

        // Gain registers
        byte gain_caps[4]; // Red, Green, Blue, Clear (note that values must be <= 0xf)
        unsigned int gain_integrators[4]; // Red, Green, Blue, Clear (note that values must be <= 0xfff)

        // Raw color values
        unsigned int color_values[4];
        byte offset_values[4];
};



#endif
// *********** END OF CODE **********
