# TC74
This is the library used for the TC74 Temperature Sensor manufactured by Microchip. 

## Example code
```c++
    #include "TC74.h"
    #include "mbed.h"

    int main(){
        int8_t init_code;
        TC74 tempSensor(init_code);
        if(init_code != 0){
            printf("Error can't connect to sensor at %x", tempSensor.i2c_addr);
            return -100; // This is a made up error code 
        }
        while(true) {
            printf("Current Temperature is %d\n",tempSensor.read());
        }
    }
```