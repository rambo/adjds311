// safety againts double-include
#ifndef adjds311_h
#define adjds311_h
#include <Arduino.h> 
#include <i2c_device.h>

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

        // Gain registers
        byte gain_caps[4]; // Red, Green, Blue, Clear
        unsigned int gain_integrators[4]; // Red, Green, Blue, Clear

        // Raw color values
        unsigned int color_values[4];
};



#endif
// *********** END OF CODE **********
