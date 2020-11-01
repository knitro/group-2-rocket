#ifndef _POST_FLIGHT_
#define _POST_FLIGHT_

/*Includes*/
#include <stdint.h>
#include "../launch/flight.hh"

/*Header Content*/
namespace post_flight_ns {
  
  /**
   * Enum that determines the state of the rocket in regards to its post_flight.
   * This will be used for post_flight_loop().
   */ 
  enum post_state {
    FALLING_DOWN, GROUNDED
  };

  post_state post_flight_loop();
  flight_ns::sensor_return post_handle_gps();
  flight_ns::sensor_return post_handle_accelerometer();
  flight_ns::sensor_return post_handle_barometer();
  flight_ns::sensor_return post_handle_buzzer();
  int checkIfStopped();

}

#endif /* _POST_FLIGHT_ */