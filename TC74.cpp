#include "TC74.h"
#include <cstdint>

TC74::TC74(int8_t& init_code, PinName sda, PinName scl,uint8_t i2c_7b_addr)
    :i2c_connection(sda,scl){
        i2c_addr = i2c_7b_addr << 1;
        cmd[0] = CHANGE_REG_CMD;
        cmd[1] = TEMP_REGISTER;
        init_code = this->i2c_connection.write(this->i2c_addr,cmd,2); // Magic Number is the length of the comamand, 2 wide command
};

TC74::~TC74(){
    
};

int8_t TC74::read(){
    cmd[0] = READ_CMD;
    if(this->i2c_connection.write(this->i2c_addr,cmd,1) != 0){ // Magic Number 1 is the lenght of the write data, 1 byte
        // TODO: Throw error no response error
    } else {
        this->i2c_connection.read((int)this->i2c_addr, (char*)this->temp, 1);// Magic Number 1 is the lenght of return data, 1 byte
    }
    return (int8_t) *temp;
};