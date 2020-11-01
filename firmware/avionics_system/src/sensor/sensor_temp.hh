#ifndef _SENSOR_TEMP_
#define _SENSOR_TEMP_

/*Includes*/
#include <stdint.h>
#include "sensor.hh"
//TODO:: Add temp library here

/*Header Content*/
namespace sensor_temp_ns {

  /*Typedefs*/
  typedef struct temp_data {
    //TODO:: Fill in Temp Data that can be stored/is useful
  } temp_data_t;


  /*Functions*/
  /**
    * Initialises the Sensor 
    */
  int init_temp();

  /**
    * Prompts the sensor to collect data, and record it to its buffer.
    */
  int record_data_temp();

  /**
   * Gets the head of the sensor's buffer
   */
  int get_data_temp(sensor_temp_ns::temp_data_t* return_data);
}
#endif /* _SENSOR_TEMP_ */