#pragma once
#include "mbed.h"
#include <cstdint>

class TC74{
    private:
        const uint8_t TEMP_REGISTER     = 0x00;

        const uint8_t CHANGE_REG_CMD    = 0x01;
        const uint8_t READ_CMD          = 0x00;
        
    protected:
        I2C i2c_connection;
        char cmd[2];
    public:
        uint8_t i2c_addr;

        TC74(int8_t& init_code, PinName sda=I2C_SDA, PinName scl=I2C_SCL,uint8_t i2c_7b_addr = 0b1001101);
        ~TC74();
        int8_t read();
};