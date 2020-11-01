#ifndef _SENSOR_
#define _SENSOR_

/*Includes*/
#include <stdint.h>
#include <Arduino.h>

namespace sensor_ns {
  template <typename T>

    /*Fields*/
  #define SENSOR_BUFFER_LEN 8 //Temporary Value

  class circular_buffer {

  private:
    T data [SENSOR_BUFFER_LEN] = {};
  public:
    //Adds a value on the front of the buffer
    void addValue(T newVal);

    //Returns full buffer
    T* getBuffer();
    
    //Size of buffer
    int getCapacity();

  };
}

#endif _SENSOR_