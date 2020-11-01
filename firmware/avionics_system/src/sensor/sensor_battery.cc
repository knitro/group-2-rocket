#include <Arduino.h>
#include "sensor_battery.hh" 

/*Fields*/
const int bit_value = 4095; //12 Bit Resolution
int pin_number = 0;
const bool isTesting = true;


/*Functions*/
/**
 * Initialises the Sensor 
 */
int sensor_battery_ns::init_battery(int pin_number_parameter) {
  pin_number = pin_number_parameter;
  return 0;
}

/**
 * Returns the battery level from [0,100], where 0 is no charge, and 100 is full charge
 * NOTE: Configured for a 12 bit resolution
 */
int sensor_battery_ns::getBatteryLevel() {
  if (isTesting == true) {
    return 100; //Full Charge Return
  } else {
    int battery_value = analogRead(pin_number); //todo TEST
    return std::floor(((float)battery_value / (float)bit_value) * 100); //converts raw value from battery to a percentage
  }
}