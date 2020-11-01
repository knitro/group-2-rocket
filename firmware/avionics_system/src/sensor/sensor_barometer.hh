#ifndef _SENSOR_BAROMETER_
#define _SENSOR_BAROMETER_

/*Includes*/
#include <stdint.h>
#include "sensor.hh"
//TODO:: Add barometer library here

/*Header Content*/
namespace sensor_barometer_ns {

  static sensor_ns::circular_buffer<int>* circ_buff_barometer;

  /*Typedefs*/

  typedef struct barometer_data {
    int pressure;
  } barometer_data_t;

  /*Functions*/

  /**
    * Initialises the Sensor 
    */
  int init_barometer();

  /**
    * Prompts the sensor to collect data, and record it to its buffer.
    */
  int record_data_barometer();

  /**
   * Gets the head of the sensor's buffer
   */
  int get_data_barometer(barometer_data_t* return_data);

}
#endif /* _SENSOR_BAROMETER_ */