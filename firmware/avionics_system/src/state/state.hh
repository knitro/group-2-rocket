#ifndef _STATE_
#define _STATE_

/*Includes*/
#include <stdint.h>
#include <string>
#include <iostream>

namespace state_ns {

  /////////////////////////////////
  /*Enums*/
  /////////////////////////////////
  /**
   * The enum that determines what state/stage the rocket is in
   */ 
  enum state {
    initialisation, test, idle, launch_sequence, ignition, flight, post_flight, finished, fail
  };

  /////////////////////////////////
  /*Variables and Constants*/
  /////////////////////////////////

  static state current_state = state::fail;

  /////////////////////////////////
  /*Functions*/
  /////////////////////////////////

  /**
   * Prints out the current state of the system.c  
   */
  int print_state();

  /**
  * Gets the next state that the system would be at
  */
  int next_state();


}

#endif /*_STATE_*/