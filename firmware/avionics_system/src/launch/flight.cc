#include "flight.hh" 

/////////////////////////////////
/*Variables and Constants*/
/////////////////////////////////

namespace flight_ns_cc {
  
  int previousBarometerData = 0; //Barometer Pressure ranges from 300-1100hpa, therefore 0 is out of scope for "uninitialised" state.
                                 //Further Information: https://www.bosch-sensortec.com/products/environmental-sensors/pressure-sensors/pressure-sensors-bmp280-1.html

  flight_ns::flight_data_t currentFlightData;
}

const bool isTesting = true;

/////////////////////////////////
/*Implemented Functions*/
/////////////////////////////////

flight_ns::fly_state flight_ns::launch_loop() {

  /*Handle Sensors*/
  handle_gps();
  handle_accelerometer();
  handle_barometer();
  handle_temp();
  handle_control();

  /*Handle the Return*/
  int checkIfFallingValue = checkIfFalling();
  if (checkIfFallingValue == 0) {
    return flight_ns::fly_state::APEX;
  } else if (checkIfFallingValue == 1) {
    return flight_ns::fly_state::FLYING;
  }
}

flight_ns::sensor_return flight_ns::handle_gps() {
  
  /*Retrieve Data Values from Sensor*/
  int recordDataValue = sensor_gps_ns::record_data_gps();
  int getDataValue = sensor_gps_ns::get_data_gps(&flight_ns_cc::currentFlightData.gps);

  /*Determine the "Correctness" of the Data returned from the Sensor*/
  if ((recordDataValue > 0) && (getDataValue > 0)) {
    return flight_ns::sensor_return::ALL_FAIL;
  } else if ((recordDataValue > 0) && (getDataValue == 0)) {
    return flight_ns::sensor_return::RECORD_DATA_FAIL;
  } else if ((recordDataValue == 0) && (getDataValue > 0)) {
    return flight_ns::sensor_return::GET_DATA_FAIL;
  } else {
    return flight_ns::sensor_return::NO_ERROR;
  }
}

flight_ns::sensor_return flight_ns::handle_accelerometer() {

  /*Retrieve Data Values from Sensor*/
  int recordDataValue = sensor_accelerometer_ns::record_data_accelerometer();
  int getDataValue = sensor_accelerometer_ns::get_data_accelerometer(&flight_ns_cc::currentFlightData.accelerometer);

  /*Determine the "Correctness" of the Data returned from the Sensor*/
  if ((recordDataValue > 0) && (getDataValue > 0)) {
    return flight_ns::sensor_return::ALL_FAIL;
  } else if ((recordDataValue > 0) && (getDataValue == 0)) {
    return flight_ns::sensor_return::RECORD_DATA_FAIL;
  } else if ((recordDataValue == 0) && (getDataValue > 0)) {
    return flight_ns::sensor_return::GET_DATA_FAIL;
  } else {
    return flight_ns::sensor_return::NO_ERROR;
  }
}

flight_ns::sensor_return flight_ns::handle_barometer() {

  /*Retrieve Data Values from Sensor*/
  int recordDataValue = sensor_barometer_ns::record_data_barometer();
  int getDataValue = sensor_barometer_ns::get_data_barometer(&flight_ns_cc::currentFlightData.barometer);

  /*Determine the "Correctness" of the Data returned from the Sensor*/
  if ((recordDataValue > 0) && (getDataValue > 0)) {
    return flight_ns::sensor_return::ALL_FAIL;
  } else if ((recordDataValue > 0) && (getDataValue == 0)) {
    return flight_ns::sensor_return::RECORD_DATA_FAIL;
  } else if ((recordDataValue == 0) && (getDataValue > 0)) {
    return flight_ns::sensor_return::GET_DATA_FAIL;
  } else {
    return flight_ns::sensor_return::NO_ERROR;
  }
}

flight_ns::sensor_return flight_ns::handle_temp() {

  /*Retrieve Data Values from Sensor*/
  int recordDataValue = sensor_temp_ns::record_data_temp();
  int getDataValue = sensor_temp_ns::get_data_temp(&flight_ns_cc::currentFlightData.temp);

  /*Determine the "Correctness" of the Data returned from the Sensor*/
  if ((recordDataValue > 0) && (getDataValue > 0)) {
    return flight_ns::sensor_return::ALL_FAIL;
  } else if ((recordDataValue > 0) && (getDataValue == 0)) {
    return flight_ns::sensor_return::RECORD_DATA_FAIL;
  } else if ((recordDataValue == 0) && (getDataValue > 0)) {
    return flight_ns::sensor_return::GET_DATA_FAIL;
  } else {
    return flight_ns::sensor_return::NO_ERROR;
  }
}

uint8_t flight_ns::handle_control() {
  //TODO:: Unsure on how to handle the IMU
  return 1;
}

/**
 * Checks if the rocket is in the state of falling or not.
 * If the rocket is in a state of falling, it should return 0, otherwise returns 1. 
 */
int flight_ns::checkIfFalling() {

  if (isTesting) {
    return 0; //Rocket is Falling
  } else {
    //Check to determine if the barometer data has been initialised or not.
    //If it has not been initialised, then the rocket "cannot be falling".
    if (flight_ns_cc::previousBarometerData == -1) {
      return 1; //Not Falling
    }

    /*Update the Current Barometer Data*/
    int currentBarometerData = flight_ns_cc::currentFlightData.barometer.pressure;

    if (currentBarometerData < flight_ns_cc::previousBarometerData) {
      //Rocket is falling as pressure is now decreased
      return 0; 
    } else {
      //Rocket is not falling; update the previousBarometerData
      flight_ns_cc::previousBarometerData = currentBarometerData;
      return 1; 
    }
  }
  
}