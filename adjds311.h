// safety againts double-include
#ifndef adjds311_h
#define adjds311_h
#include <Arduino.h> 
#include <i2c_device.h>

class adjds311 : public i2c_device
{
    public:
        adjds311(); // We need this so we can set default address to the all-call 
};



#endif
// *********** END OF CODE **********
