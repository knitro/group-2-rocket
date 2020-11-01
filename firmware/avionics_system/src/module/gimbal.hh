#ifndef _GIMBAL_
#define _GIMBAL_

#define X_PIN 10 
#define Z_PIN 11

/*Includes*/
#include <stdint.h>
#include <Arduino.h>
// #include <Servo.h>

/*Header Content*/
namespace gimbal_ns {

    int init_gimbal();

}

#endif /* _GIMBAL_ */