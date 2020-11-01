The software for the avionics system and base station is developed using the PlatformIO ecosystem which is built on top of the Visual Studio Code IDE. The board used by the avionics system is the Adafuit Feather STM32F405, and the board used by the base station is the Arduino Nano ATmega328.

The hardware for the avionics system is composed from several different components which have different functions. To allow for easier interfacing with the the hardware several software libraries are used. 

The different components used in the avionics system, as the libraries required are listed below:

- BMP280 (Barometer): Adafruit BMP280 Library https://github.com/adafruit/Adafruit_BMP280_Library
- BNO055 (9 Axis IMU): Adafruit BNO055 Library https://github.com/adafruit/Adafruit_BNO055
- NEO-M8N: NeoGPS https://github.com/SlashDevin/NeoGPS
- RFM95W: RadioHead Library http://www.airspayce.com/mikem/arduino/RadioHead/index.html



