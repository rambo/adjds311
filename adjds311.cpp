#include <adjds311.h>

// Constructor
adjds311::adjds311()
{
    device_address = 0x74; // Default address
    
    // Default values for calibration
    gain_caps[0] = 0x9;
    gain_caps[1] = 0x9;
    gain_caps[2] = 0x2;
    gain_caps[3] = 0x5;

    gain_integrators[0] = 0x800;
    gain_integrators[1] = 0x800;
    gain_integrators[2] = 0x800;
    gain_integrators[3] = 0x800;
}

void adjds311::begin(byte dev_addr, boolean wire_begin)
{
    i2c_device::begin(dev_addr, wire_begin);
    this->write_gains();
}

void adjds311::begin(boolean wire_begin)
{
    this->begin(this->device_address, wire_begin);
}

void adjds311::begin()
{
    this->begin(true);
}

boolean adjds311::write_gains()
{
    boolean ret1 = this->write_many(0x6, 4, gain_caps);
    boolean ret2 = this->write_many(0xa, 8, gain_integrators);
    return ret1 & ret2;
}

boolean adjds311::read_data()
{
    /**
     * To obtain sensor ADC value, ‘01’ Hex must be written to CTRL register.
     * Then, read the value from CTRL register. If value is 00H, can read sensor output from data register.
     */
    if (!this->write(0x0, (byte)0x1))
    {
        return false;
    }
    unsigned long started = millis();
    while (true)
    {
        // Waiting for measurement data
        if (this->read(0x0) == 0x0)
        {
            break;
        }
        if ((millis() - started) > 500)
        {
            // Timeout
            return false;
        }
    }
    return this->read_many(0x40, 8, (byte*)this->color_values);
}
