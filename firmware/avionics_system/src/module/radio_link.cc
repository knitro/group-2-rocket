#include "radio_link.hh"
#include "../telemetry/transmit_data.hh" 

int radio_link_ns::init_radio_link() {

  return 0;
  //Commented Out because it doesn't work
  // uint8_t errorCode = transmit_data_ns::setup();
  // return errorCode; //Test return for valid init
}