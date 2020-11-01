#ifndef _FLIGHT_
#define _FLIGHT_

/*Includes*/
#include <stdint.h>
#include "../sensor/sensor_accelerometer.hh"
#include "../sensor/sensor_barometer.hh"
#include "../sensor/sensor_gps.hh"
#include "../sensor/sensor_temp.hh"

/*Header Content*/
namespace flight_ns {

  /**
   * Enum that determines the state of the rocket in regards to flight.
   * This will be used for launch_loop().
   */ 
  enum fly_state {
    FLYING, APEX
  };

  enum sensor_return {
    NO_ERROR, RECORD_DATA_FAIL, GET_DATA_FAIL, ALL_FAIL
  };

  typedef struct flight_data {
    sensor_accelerometer_ns::accelerometer_data_t accelerometer;
    sensor_barometer_ns::barometer_data_t barometer;
    sensor_gps_ns::gps_data_t gps;
    sensor_temp_ns::temp_data_t temp;
  } flight_data_t;

  fly_state launch_loop();
  sensor_return handle_gps();
  sensor_return handle_accelerometer();
  sensor_return handle_barometer();
  sensor_return handle_temp();
  uint8_t handle_control();
  int checkIfFalling();

}

#endif /* _FLIGHT_ */