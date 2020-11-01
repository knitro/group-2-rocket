#include "init_test.hh" 
#include <stdint.h>

/*Sensor Includes*/
#include "../sensor/sensor_battery.hh"
#include "../sensor/sensor_accelerometer.hh"
#include "../sensor/sensor_barometer.hh"
#include "../sensor/sensor_gps.hh"
#include "../sensor/sensor_temp.hh"
#include "../module/black_box.hh"
#include "../module/gimbal.hh"
#include "../module/radio_link.hh"

/*Fields*/
const int required_battery_charge = 50;  //requires battery to have at least 50% charge to launch

/*Functions*/

/**
 * This will perform all the tests available for the initialisation sequence.
 * The return values are as such:
 * 
 */
uint8_t init_test_ns::perform_all_tests() {

  if (init_test_ns::check_battery() != 0) {
    return init_test_ns::failure_code::battery_failure;
  }

  if (init_test_ns::check_gps() != 0) {
    return init_test_ns::failure_code::gps_failure;
  }

  if (init_test_ns::check_accelerometer() != 0) {
    return init_test_ns::failure_code::accelerometer_failure;
  }

  if (init_test_ns::check_barometer() != 0) {
    return init_test_ns::failure_code::barometer_failure;
  }

  if (init_test_ns::check_temp() != 0) {
    return init_test_ns::failure_code::temp_failure;
  }
  
  if (init_test_ns::check_radio_link() != 0) {
    return init_test_ns::failure_code::radio_link_failure;
  }

  if (init_test_ns::check_gimbal() != 0) {
    return init_test_ns::failure_code::gimbal_failure;
  }

  return 0; //No Errors!
}

uint8_t init_test_ns::check_battery() {
  
  int current_battery_charge = sensor_battery_ns::getBatteryLevel();

  if (current_battery_charge > required_battery_charge) {
    return 0; //Battery Charge is above the required charge
  } else {
    return 1; //Battery Charge is not above required charge, no launch allowed.
  }
}

uint8_t init_test_ns::check_gps() {
  int output = sensor_gps_ns::init_gps();
  return output;
}

uint8_t init_test_ns::check_accelerometer() {
  int output = sensor_accelerometer_ns::init_accelerometer();
  return output;
}

uint8_t init_test_ns::check_barometer() {
  int output = sensor_barometer_ns::init_barometer();
  return output;
}

uint8_t init_test_ns::check_temp() {
  int output = sensor_temp_ns::init_temp();
  return output;
}

uint8_t init_test_ns::check_radio_link() {
  int output = radio_link_ns::init_radio_link();
  return output;
}

uint8_t init_test_ns::check_gimbal() {
  int output = gimbal_ns::init_gimbal();
  return output;
}

uint8_t init_test_ns::check_black_box() {
  int output = black_box_ns::init_black_box();
  return output;
}