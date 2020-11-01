#ifndef _SENSOR_ACCELEROMETER_
#define _SENSOR_ACCELEROMETER_

/*Includes*/
#include <stdint.h>
#include "sensor.hh"
// #include <Adafruit_BNO055.h>

/*Header Content*/
namespace sensor_accelerometer_ns {

  /*Typedefs*/
  typedef struct accelerometer_data {
    double acceleration_x;
    double acceleration_y;
    double acceleration_z;
    double gyro_x;
    double gyro_y;
    double gyro_z;
    double orientation_x;
    double orientation_y;
    double orientation_z;
  } accelerometer_data_t;

  static sensor_ns::circular_buffer<accelerometer_data_t>* circ_buff_accelerometer;

  /*Functions*/

  /**
    * Initialises the Sensor 
    */
  int init_accelerometer();

  /**
    * Prompts the sensor to collect data, and record it to its buffer.
    */
  int record_data_accelerometer();

  /**
   * Gets the head of the sensor's buffer
   */
  int get_data_accelerometer(sensor_accelerometer_ns::accelerometer_data_t* return_data);

}
#endif /* _SENSOR_ACCELEROMETER_ */