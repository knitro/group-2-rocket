#ifndef _SENSOR_BATTERY_
#define _SENSOR_BATTERY_

/*Includes*/
#include <stdint.h>

/*Header Content*/
namespace sensor_battery_ns {

/*Functions*/
/**
 * Initialises the Sensor 
 */
int init_battery(int pin_number_parameter);

/**
 * Returns the battery level from [0,100], where 0 is no charge, and 100 is full charge
 */
int getBatteryLevel();
}

#endif /* _SENSOR_BATTERY_ */