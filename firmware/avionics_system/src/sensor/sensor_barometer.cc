#include "sensor_barometer.hh" 
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include "sensor.cc"

#define BMP_SCK 23
#define BMP_MISO 24
#define BMP_MOSI 25
#define BMP_CS 11

// Adafruit_BMP280 bmp; // use I2C interface
Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);
Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor(); //currently unused, not part of MVP
Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();

/*Functions*/
/**
* Initialises barometer. Returns a status code.
*/
int sensor_barometer_ns::init_barometer() {
  // Perform some initialisation of the sensor

  // //Commented Out because it doesn't work
  // Serial.begin(9600);
  // if (!bmp.begin()) {
  //   Serial.println(F("BMP280 Sensor Initialisation failed."));
  //   return 1; //failure!
  // }

  // //TODO: Check if sampling settings are appropriate
  // bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
  //                 Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
  //                 Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
  //                 Adafruit_BMP280::FILTER_X16,      /* Filtering. */
  //                 Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  // circ_buff_barometer = new sensor_ns::circular_buffer<int>;

  return 0; //success!
}

/**
  * Prompts the sensor to collect data, and record it to its buffer.
  */
int sensor_barometer_ns::record_data_barometer() {
  //Record the data, and add it to the buffer
  // sensors_event_t pressure_event;
  // if(!bmp_pressure->getEvent(&pressure_event)) {
  //   //TODO: Add proper fail state 
  //   return 1; //Getting pressure failed
  // } 
  // circ_buff_barometer->addValue(pressure_event.pressure);
  return 0;

}


int sensor_barometer_ns::get_data_barometer(sensor_barometer_ns::barometer_data_t* return_data) {
  //Get Head of the Data
  // if(circ_buff_barometer == nullptr || circ_buff_barometer->getBuffer() == nullptr){
  //   return 1;
  // }
  // int* pressure_value = circ_buff_barometer->getBuffer();
  // return_data->pressure = *pressure_value;
  return 0;
}
  