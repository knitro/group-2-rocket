//Arduino Source Library
#include <Arduino.h>

//Necessary C Libraries
#include <stdint.h>
#include <iostream>

//Required .hh Files
#include "init/init_system.hh"
#include "init/init_test.hh" 
#include "sensor/sensor_battery.hh"
#include "sensor/sensor_gps.hh"
#include "sensor/sensor_barometer.hh"
#include "sensor/sensor_accelerometer.hh"
#include "sensor/sensor_temp.hh"
#include "pre_flight/launch_sequence.hh"
#include "pre_flight/ignition.hh"
#include "launch/flight.hh"
#include "post_flight/post_flight.hh"
#include "led/led_controller.hh"
#include "state/state.hh"

using namespace state_ns;

/////////////////////////////////
/*Variables and Constants*/
/////////////////////////////////

#define MAIN_BUFFER_SIZE 100 //Temporary Value
static const bool isTesting = true;

static uint8_t launch_sequence_passed_tests = 0;
static int battery_pin_number = 0; //TODO:: Adjust this later with the actual pin
static bool hasUploadedFail = false;

/////////////////////////////////
/*Functions*/
/////////////////////////////////

/**
 * Sets up the sensors.
 */
uint8_t setup_sensors() {

  /*Initialisation*/
  int sensorErrorValue = 0;

  /*Setup Battery Sensor*/
  sensorErrorValue = sensor_battery_ns::init_battery(battery_pin_number);
  if (sensorErrorValue > 0) {
    return sensorErrorValue ;
  }

  /*Setup GPS*/
  sensorErrorValue = sensor_gps_ns::init_gps();
  if (sensorErrorValue > 0) {
    return sensorErrorValue;
  }

  /*Setup Barometer*/
  sensorErrorValue = sensor_barometer_ns::init_barometer();
  if (sensorErrorValue > 0) {
    return sensorErrorValue;
  }

  /*Setup Temp*/
  sensorErrorValue = sensor_temp_ns::init_temp();
  if (sensorErrorValue > 0) {
    return sensorErrorValue;
  }

  /*Setup Accelerometer*/
  sensorErrorValue = sensor_accelerometer_ns::init_accelerometer();
  if (sensorErrorValue > 0) {
    return sensorErrorValue;
  }

  /*Success Return as all sensors have passed*/
  return 0;
}

/**
 * Forces the state into failure.
 */
int state_fail() {
  current_state = state::fail;
  return 0;
}

/**
 * Displays the LED on the chip with the colour corresponding to the state that the rocket is in.
 */
int activate_state_led() {

  switch(current_state) {

    case (state::initialisation): {
      //Initialisation => Orange
      led_controller_ns::solid_colour(200, 200, 20, led_controller_ns::led::chip_led);
      break;
    } case (state::test): {
      //Test => Yellow
      led_controller_ns::solid_colour(100, 100, 0, led_controller_ns::led::chip_led);
      break;
    } case (state::idle): {
      //Idle => Green
      led_controller_ns::solid_colour(0, 255, 0, led_controller_ns::led::chip_led);
      break;
    } case (state::launch_sequence): {
      //Launch Sequence => Cyan
      led_controller_ns::solid_colour(0, 255, 255, led_controller_ns::led::chip_led);
      break;
    } case (state::ignition): {
      //Ignition => Blue
      led_controller_ns::solid_colour(65, 105, 255, led_controller_ns::led::chip_led);
      break;
    } case (state::flight): {
      //Flight => Purple
      led_controller_ns::solid_colour(153, 50, 204, led_controller_ns::led::chip_led);
      break;
    } case (state::post_flight): {
      //Post Flight => Magenta
      led_controller_ns::solid_colour(255, 0, 255, led_controller_ns::led::chip_led);
      break;
    } case (state::fail): {
      //Fail => Red
      led_controller_ns::solid_colour(255, 0, 0, led_controller_ns::led::chip_led);
      break;
    } case (state::finished): {
      //Finished => Green
      led_controller_ns::solid_colour(0, 255, 0, led_controller_ns::led::chip_led);
      break;
    }
  }
  return 0;
}

int activate_error_led(int error_code) {
  switch(error_code) {
    case (init_test_ns::failure_code::battery_failure): {
      //Colour => Cyan
      blink_colour(0, 255, 255, 1, led_controller_ns::led::chip_led);
      break; 
    } case (init_test_ns::failure_code::gps_failure): {
      //Colour => Mauve (Purple/Brown)
      blink_colour(0, 176, 0, 1, led_controller_ns::led::chip_led); 
      // blink_colour(224, 176, 255, 1, led_controller_ns::led::chip_led); 
      break;
    } case (init_test_ns::failure_code::accelerometer_failure): {
      //Colour => Chartreuse (Yellow)
      blink_colour(127, 255, 0, 1, led_controller_ns::led::chip_led);      
      break; 
    } case (init_test_ns::failure_code::barometer_failure): {
      //Colour => Teal
      blink_colour(0, 128, 129, 1, led_controller_ns::led::chip_led); 
      break;
    } case (init_test_ns::failure_code::temp_failure): {
      //Colour => Russet (Brown)
      blink_colour(128, 70, 27, 1, led_controller_ns::led::chip_led); 
      break;
    } case (init_test_ns::failure_code::radio_link_failure): {
      //Colour => White
      blink_colour(255, 255, 255, 1, led_controller_ns::led::chip_led); 
      break;
    } case (init_test_ns::failure_code::gimbal_failure): {
      //Colour => Hot Pink
      blink_colour(255, 69, 105, 1, led_controller_ns::led::chip_led); 
      break;
    } case (init_test_ns::failure_code::black_box_failure): {
      //Colour => Glaucous (Dull BLue)
      blink_colour(96, 130, 182, 1, led_controller_ns::led::chip_led);   
      break;
    }

  }
  return 0;
}

/**
  * Gets the next state that the system would be at
  */
int next_state_2() {

  led_controller_ns::blink_colour(5,0,0,1,led_controller_ns::led::chip_led);

  switch(state_ns::current_state) {
    case (state_ns::state::initialisation)  : {state_ns::current_state = state_ns::state::test; break;}
    case (state_ns::state::test)            : {state_ns::current_state = state_ns::state::idle; break;}
    case (state_ns::state::idle)            : {state_ns::current_state = state_ns::state::launch_sequence; break;}
    case (state_ns::state::launch_sequence) : {state_ns::current_state = state_ns::state::ignition; break;}
    case (state_ns::state::ignition)        : {state_ns::current_state = state_ns::state::flight; break;}
    case (state_ns::state::flight)          : {state_ns::current_state = state_ns::state::post_flight; break;}
    case (state_ns::state::post_flight)     : {state_ns::current_state = state_ns::state::finished; break;}
    case (state_ns::state::finished)        : {break;} //Should not change state after already being launched
    case (state_ns::state::fail)            : {break;} //Should not change state after failing
  }
  
  led_controller_ns::blink_colour(5,0,0,1,led_controller_ns::led::chip_led);
  return current_state;
}

/////////////////////////////////
/*Loop and Setup*/
/////////////////////////////////

/**
 * The Main Loop of the System.
 * This should go through all the different states (phases) during the rocket's duration.
 * See https://gitlab.ecs.vuw.ac.nz/course-work/engr300/2020/group2/group-2/-/blob/master/architecture_design/images/4.1_class_diagram.png
 */
void loop() {
  
  //Display the Current State via LED: Blink Solid Blue x4, then State Colour
  blink_colour(0, 0, 255, 4, led_controller_ns::led::chip_led);

  activate_state_led();

  //Perform Current State Actions
  switch(current_state) {
    
    case (state::initialisation): {
      
      init_system_ns::init_loop();
      next_state_2(); 
      break;
      
    } case (state::test): {

      int testReturnValue = init_test_ns::perform_all_tests();
      if (testReturnValue == 0) {
        blink_colour(0, 255, 0, 1, led_controller_ns::led::chip_led); 
        //Should only pass given all the tests pass
        next_state_2();
        activate_state_led();
      } else {
        // blink_colour(0, 128, 0, 1, led_controller_ns::led::chip_led); 
        activate_error_led(testReturnValue);
      }
      break;

    } case (state::launch_sequence): {
      
        //Check if tests have been performed or not. This should olnly be ever called once.
        if (launch_sequence_passed_tests == 0) {
        //Perform Launch Tests
        if (launch_sequence_ns::perform_launch_tests() > 0) {
          current_state = state::fail;
          break;
        }
        launch_sequence_passed_tests = 1;
        launch_sequence_ns::init_start_time();
      }

      //Check the Radio Buffer for "Abort Launch" Commands
      //TODO::

      //Check the Countdown
      if (launch_sequence_ns::countdown_tick() == true) {
        next_state_2();
      }

      break;

    } case (state::ignition): {

      ignition_ns::ignite_launch();
      next_state_2();
      break;

    } case (state::flight): {

      flight_ns::fly_state testReturnValue = flight_ns::launch_loop();

      //Once the rocket has reached the apex, move to post_flight state
      if (testReturnValue == flight_ns::fly_state::APEX) { 
        next_state_2();
      }
      break;

    } case (state::post_flight): {

      post_flight_ns::post_state testReturnValue = post_flight_ns::post_flight_loop();

      //Once the rocket has reached the apex, move to post_flight state
      if (testReturnValue == post_flight_ns::post_state::GROUNDED) {
        next_state_2();
      }
      break;

    } case (state::idle): {
      
      //Check for Software Start
      if (true /*TODO::*/) {
        next_state_2();
      }
      break;

    } case (state::fail): {

      if (!hasUploadedFail) {
        //Upload Fail Data to blackbox here.
        hasUploadedFail = true;
      }
      break;

    } case (state::finished) : {

      break;

    }
  }

}

/**
 * The first function to be called.
 * It should set up the sensors as best as it can.
 * If there is a setup failure, it should return early, and set the rocket to a fail state.
 */
void setup() {

  // Serial.begin(9600);
  led_controller_ns::setup_leds();
  
  //Blink Red 10 times for SetUp
  blink_colour(255, 0, 0, 10, led_controller_ns::led::chip_led); 
  // blink_colour(255, 0, 0, 1, led_controller_ns::led::chip_led); 

  switch (setup_sensors()) {

    case (10): {
      //GPS Failure
      current_state = state::fail;
      print_state();
      return;
    } case 20: {
      //Barometer Failure
      current_state = state::fail;
      print_state();
      return;
    } case 30: {
      //Temperature Failure
      current_state = state::fail;
      print_state();
      return;
    } case 40:  {
      //Accelerometer Failure
      current_state = state::fail;
      print_state();
      return;
    }
    default:
      break;
  }

  /*Set the initial current_state given no failures*/
  // current_state = state::initialisation;
  current_state = state::initialisation;
  print_state();

  //Blink Green 10 Times after Setup for a "Passed" SetUp
  // blink_colour(0, 255, 0, 1, led_controller_ns::led::chip_led);
  blink_colour(0, 255, 0, 10, led_controller_ns::led::chip_led);
}

/*Uncomment out for native testing*/
// int main(void) {
//   setup();
//   while(true) {
//     loop();
//   }
// }

