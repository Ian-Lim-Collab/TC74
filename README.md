# TC74
This is the library used for the TC74 Temperature Sensor manufactured by Microchip. 

## Example code
```c++
    #include "TC74.h"
    #include "mbed.h"

    int main(){
        int8_t init_code;
        int8_t temp_val;
        TC74 tempSensor(init_code);
        if(init_code != 0){
            printf("Error can't connect to sensor at %x", tempSensor.i2c_addr);
            return -100; // This is a made up error code 
        }
        while(true) {
            temp_val = tempSensor.read();
            if(temp_val == -100){
                printf("Temp Sensor Missing");
                return -200;
            } else {
                printf("Current Temperature is %d\n",temp_val);
            }
        }
    }
```