#include "sensor_gps.hh" 
#include "sensor.hh" 
#include <NMEAGPS.h> //GPS Library
#include <Streamers.h> //Used for Formatting GPS Data
#include "GPSport.h" //GPS port header
#include <Arduino.h> //For time commands

/*Variables*/
static NMEAGPS gps; //GPS
static gps_fix fix; //Current GPS Data (gps_fix is the data structure)
static sensor_gps_ns::gps_data_t gps_data_current; // The current gps data using the struct

/*Functions*/
int sensor_gps_ns::init_gps() {
  
  // DEBUG_PORT.begin( gpsPort );
  // while (!Serial);
  
  // data_state = sensor_ns::data_state::NO_DATA;
  // fix.init();
  // fix.valid.init(); //"Sets all the flags to false"

  return 0; //Test return for valid init
}

int sensor_gps_ns::record_data_gps() {

  if (gps.available( gpsPort )) {
  gps_fix fix = gps.read();
  } else {
    //TODO:: Debug Message Here
  }

  return 0; //Currently returning 0 regardless of gps being available or not
}


int sensor_gps_ns::get_data_gps(sensor_gps_ns::gps_data_t* return_data) {

  //Convert the gps_fix into gps_data_t
  gps_data_current = {
    fix.latitudeL(), fix.longitudeL(), fix.altitude_cm() , millis()
  };
  
  return 0; //Currently returning 0 regardless of gps data being available or not
}