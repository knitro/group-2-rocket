#include "launch_sequence.hh" 
#include "init/init_test.hh"
#include <Arduino.h> //For time commands

/*Variables*/
const uint8_t COUNTDOWN_LENGTH = 10; //The length of the countdown in seconds before the rocket is ignited.
unsigned long start_time = -1;

/*Functions*/

uint8_t launch_sequence_ns::perform_launch_tests() {
  if (init_test_ns::perform_all_tests() == 0) { //Pass Condition
    return 0;
  } else {
    //TODO to handle error code - eg. printing to blackbox
    
    return 1;
  }
}

uint8_t launch_sequence_ns::init_start_time() {
  if (start_time == -1) {
    start_time = millis();
  }
  return 0;
}

uint8_t launch_sequence_ns::countdown_tick() {
  unsigned long current_time = millis();
  unsigned long diff_time = current_time - start_time; //Difference between times
  if (diff_time > COUNTDOWN_LENGTH) {
    //If the countdown has reached the max length
    return 0; //Countdown Finished
  }
  return 1; //Countdown not Finished
}


