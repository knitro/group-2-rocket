#ifndef _INIT_TEST_
#define _INIT_TEST_

/*Includes*/
#include <stdint.h>

/*Header Content*/
namespace init_test_ns {

  /*Enums*/
  //Error code format  = XY WHERE X is a failure type AND Y is a specific error
  // Basic error codes = X0 WHERE X is a failure type
  // Ex: 15 = Battery charge error
  enum failure_code {
    battery_failure = 10,
    gps_failure = 20,
    accelerometer_failure = 30,
    barometer_failure = 40,
    temp_failure = 50,
    radio_link_failure = 60,
    gimbal_failure = 70,
    black_box_failure = 80,
  };

  /*Functions*/
  uint8_t perform_all_tests();
  uint8_t check_battery();
  uint8_t check_gps();
  uint8_t check_accelerometer();
  uint8_t check_barometer();
  uint8_t check_temp();
  uint8_t check_radio_link();
  uint8_t check_gimbal();
  uint8_t check_black_box();
  
}

#endif /* _INIT_SYSTEM_ */