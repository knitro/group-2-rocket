#include "post_flight.hh"
#include "../launch/flight.hh" 

/////////////////////////////////
/*Variables and Constants*/
/////////////////////////////////

namespace post_flight_ns_cc {

  flight_ns::flight_data_t currentFlightData;

  int accelerometer_count = 0;
  const int accelerometer_count_max = 60;

}

const bool isTesting = true;

/////////////////////////////////
/*Implemented Functions*/
/////////////////////////////////

post_flight_ns::post_state post_flight_ns::post_flight_loop() {
  
  /*Handle Sensors*/
  post_handle_gps();
  post_handle_accelerometer();
  post_handle_barometer();
  post_handle_buzzer();

  /*Handle the Return*/
  int checkIfStoppedValue = checkIfStopped();
  if (checkIfStoppedValue == 0) {
    return post_flight_ns::post_state::GROUNDED;
  } else if (checkIfStoppedValue == 1) {
    return post_flight_ns::post_state::FALLING_DOWN;
  }
}

flight_ns::sensor_return post_flight_ns::post_handle_gps() {
  return flight_ns::handle_gps();
}

flight_ns::sensor_return post_flight_ns::post_handle_accelerometer() {
  return flight_ns::handle_accelerometer();
}

flight_ns::sensor_return post_flight_ns::post_handle_barometer() {
  return flight_ns::handle_barometer();
}

flight_ns::sensor_return post_flight_ns::post_handle_buzzer() {
  //TODO::
  return flight_ns::sensor_return::ALL_FAIL;
}

int post_flight_ns::checkIfStopped() {
  
  if (isTesting) {
    return 0; //Stopped
  } else {
    int current_accelerometer_data_x = post_flight_ns_cc::currentFlightData.accelerometer.acceleration_x;
    int current_accelerometer_data_y = post_flight_ns_cc::currentFlightData.accelerometer.acceleration_y;
    int current_accelerometer_data_z = post_flight_ns_cc::currentFlightData.accelerometer.acceleration_z;

    if (current_accelerometer_data_x == 0) {
      if (current_accelerometer_data_y == 0) {
        if (current_accelerometer_data_z == 0) {
          post_flight_ns_cc::accelerometer_count++;
          if (post_flight_ns_cc::accelerometer_count > post_flight_ns_cc::accelerometer_count_max) {
            return post_flight_ns::post_state::GROUNDED;
          } else {
            return post_flight_ns::post_state::FALLING_DOWN;
          }
        }
      }
    }
    post_flight_ns_cc::accelerometer_count = 0;
    return post_flight_ns::post_state::FALLING_DOWN;
  }
}
