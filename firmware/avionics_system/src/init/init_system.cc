#include "init_system.hh" 
#include "init_test.hh"
#include "../led/led_controller.hh"

/*Variables*/
//0 = Working, 1 = Not Working
static uint8_t battery_charge;
static uint8_t gps_valid;
static uint8_t accelerometer_valid;
static uint8_t barometer_valid;
static uint8_t temp_valid;
static uint8_t radio_link_valid;
static uint8_t gimbal_valid;

uint8_t init_system_ns::init_loop() {

  //Initialisation
  unsigned int init_check = 1;

  //Repeat Loop until all Checks pass
  while (init_check > 0) {
    
    blink_colour(255, 0, 0, 1, led_controller_ns::led::chip_led); 

    init_check = 0; //Reverts to 1 if any check fails
    if (init_test_ns::check_battery() != 0) {
      battery_charge = 1;
      init_check = 0;
    } else {
      battery_charge = 0;
    }

    if (init_test_ns::check_gps() != 0) {
      gps_valid = 1;
      init_check = 0;
    } else {
      gps_valid = 0;
    }

    if (init_test_ns::check_accelerometer() != 0) {
      accelerometer_valid = 1;
      init_check = 0;
    } else {
      accelerometer_valid = 0;
    }

    if (init_test_ns::check_barometer() != 0) {
      barometer_valid = 1;
      init_check = 0;
    } else {
      barometer_valid = 0;
    }

    if (init_test_ns::check_temp() != 0) {
      temp_valid = 1;
      init_check = 0;
    } else {
      temp_valid = 0;
    }
    
    if (init_test_ns::check_radio_link() != 0) {
      radio_link_valid = 1;
      init_check = 0;
    } else {
      radio_link_valid = 0;
    }

    if (init_test_ns::check_gimbal() != 0) {
      gimbal_valid = 1;
      init_check = 0;
    } else {
      gimbal_valid = 0;
    }

  }

  return 0;
}