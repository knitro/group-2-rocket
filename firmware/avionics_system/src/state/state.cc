#include "state.hh"

/////////////////////////////////
/*Functions*/
/////////////////////////////////

/**
 * Prints out the current state of the system.c  
 */
int state_ns::print_state() {

  std::string log_message_begin = "Current State: ";
  std::string log_message_state = "";

  switch(state_ns::current_state) {
    case (state_ns::state::initialisation)  : {log_message_state =  "Initialisation";} 
    case (state_ns::state::test)            : {log_message_state =  "Test";} 
    case (state_ns::state::launch_sequence) : {log_message_state =  "Launch Sequence";} 
    case (state_ns::state::ignition)        : {log_message_state =  "Ignition";} 
    case (state_ns::state::flight)          : {log_message_state =  "Flight";} 
    case (state_ns::state::post_flight)     : {log_message_state =  "Post Flight";} 
    case (state_ns::state::idle)            : {log_message_state =  "Idle";} 
    case (state_ns::state::fail)            : {log_message_state =  "Fail";} 
    case (state_ns::state::finished)        : {log_message_state =  "Finished";}
  }

  std::cout << (log_message_begin + log_message_state);
  return 0;
}

/**
  * Gets the next state that the system would be at
  */
int state_ns::next_state() {

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
  
  return current_state;
}