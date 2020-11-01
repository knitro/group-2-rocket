#ifndef _SENSOR_GPS_
#define _SENSOR_GPS_

/*Includes*/
#include <stdint.h>
#include "sensor.hh"

/*Header Content*/
namespace sensor_gps_ns {

  /*Typedefs*/
  typedef struct gps_data {
    //Position
    int32_t latitude;
    int32_t longitude;
    int32_t altitude;

    //Other Values
    uint32_t time;
  } gps_data_t;

  /*Functions*/
  /**
   * Initialises the Sensor 
   */
  int init_gps();

  /**
   * Prompts the sensor to collect data, and record it to its buffer.
   */
  int record_data_gps();

  /**
   * Gets the head of the sensor's buffer
   */
  int get_data_gps(sensor_gps_ns::gps_data_t* return_data);
}

#endif /* _SENSOR_GPS_ */