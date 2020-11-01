#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
// #include <utility/imumaths.h>
#include "sensor_accelerometer.hh" 
#include "sensor.cc"

uint16_t BNO055_SAMPLERATE_DELAY_MS = 100;

Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

// GO TO : https://github.com/adafruit/Adafruit_BNO055/blob/master/examples/read_all_data/read_all_data.ino

/*Functions*/
int sensor_accelerometer_ns::init_accelerometer() {

  circ_buff_accelerometer = new sensor_ns::circular_buffer<sensor_accelerometer_ns::accelerometer_data_t>;

  //Perform some initialisation of the sensor
  if (!bno.begin())
  {
    /* There was a problem detecting the BNO055, check your connections */
    Serial.print("BNO055 Sensor Initialisation failed.");
    return 1;
  }
  return 0;
}

int sensor_accelerometer_ns::record_data_accelerometer() {
  //Record the data, and add it to the buffer

  sensors_event_t *orientationData , *angVelocityData , *linearAccelData, *magnetometerData, *accelerometerData, *gravityData;

  bno.getEvent(orientationData, Adafruit_BNO055::VECTOR_EULER);
  bno.getEvent(angVelocityData, Adafruit_BNO055::VECTOR_GYROSCOPE);
  bno.getEvent(linearAccelData, Adafruit_BNO055::VECTOR_LINEARACCEL);
  bno.getEvent(magnetometerData, Adafruit_BNO055::VECTOR_MAGNETOMETER);
  bno.getEvent(accelerometerData, Adafruit_BNO055::VECTOR_ACCELEROMETER);
  bno.getEvent(gravityData, Adafruit_BNO055::VECTOR_GRAVITY);

  uint8_t system, gyro, accel, mag = 0;
  bno.getCalibration(&system, &gyro, &accel, &mag);

  sensor_accelerometer_ns::accelerometer_data_t* newData = new sensor_accelerometer_ns::accelerometer_data_t();

  newData->acceleration_x = accelerometerData->acceleration.x;
  newData->acceleration_y = accelerometerData->acceleration.y;
  newData->acceleration_z = accelerometerData->acceleration.z;

  newData->gyro_x = angVelocityData->gyro.x;
  newData->gyro_y = angVelocityData->gyro.y;
  newData->gyro_z = angVelocityData->gyro.z;

  newData->orientation_x = orientationData->orientation.x;
  newData->orientation_y = orientationData->orientation.y;
  newData->orientation_z = orientationData->orientation.z;

  circ_buff_accelerometer->addValue(*newData);

  return 0; //Currently returning 0 regardless of sensor being available or not
}

int sensor_accelerometer_ns::get_data_accelerometer(sensor_accelerometer_ns::accelerometer_data_t* return_data) {
  //Get Head of the Data
  if(circ_buff_accelerometer == nullptr || circ_buff_accelerometer->getBuffer() == nullptr){
    return 1;
  }
  sensor_accelerometer_ns::accelerometer_data_t* data = circ_buff_accelerometer->getBuffer();
  return_data = data;
  return 0;
}
