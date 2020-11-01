Throughout the project two hardware systems were developed- a prototype system and a version intended for use in the actual rocket. The prototype system was developed using a breadboard and breakout boards for initial developement and testing of code. For the second system, a schematic and corresponding PCB layout was developed, with the intention of using this design inside the model rocket. Due to time constraints, the PCB was not able to be printed and populated. Although the electronics were not assembled, all of the information required for assembly including BOM and PCB designs have been included in the hardware section of the repository.


### Pinout for prototype avionics system design:
The prototype system used an Adafruit Feather F4 in conjunction with breakout boards for the different sensors required in the avionics system. Below are the pin connections for the prototype avionics system. Note that:
- BMP280 is barometer module using SPI interface
- RFM95 is LoRa transceiver using SPI interface
- BNO055 is IMU using I2C interface
- BMP280 and RFM95 are connnected to the same SPI bus (SPI2)

| Feather Pin   |  MCU Reference    | Pin Function          | Device Connection                 |
| ------------- | ----------------- | --------------------- | --------------------------------- |
| A0            | PA4               | Analog in             | LED                               |
| A1            | PA5               | Analog in             | LED                               |
| A2            | PA6               | Analog in             | LED                               |
| A3            | PA7               | Analog in             | LED                               |
| A4            | PC4               | Analog in             | LED                               |
| A5            | PC5               | Analog in             | LED                               |
| SCK           | PB13              | SPI2_SCK              | SCK of BMP208 & RFM95             |
| MOSI          | PB14              | SPI2_MOSI             | MOSI of BMP208 & RFM95            | 
| MISO          | PB15              | SPI2_MISO             | MISO of BMP208 & RFM95            |
| RX            | PB11              | UART3_RX              | TX of NEO-M8N                     |
| TX            | PB10              | UART3_TX              | RX of NEO-M8N                     |
| B0            | BOOT0             | Boot0 Pin             | Unused                            |
| SDA           | PB7               | I2C1_SDA              | SDA of BNO055                     |
| SCL           | PB6               | I2C1_SCL              | SCL of BNO055                     |  
| 5             | PC7               | Digital GPIO          | RST of RFM95                      |
| 6             | PC6               | Digital GPIO          | LED                               |
| 9             | PB8               | Digital GPIO          | INT of BNO055                     |
| 10            | PB9               | Digital GPIO          | G1 of RFM95                       |
| 11            | PC3               | Digital GPIO (SPI Slave Select)         | SPI2_SS1 of BMP208                |
| 12            | PC2               | Digital GPIO          | DIO0 of RFM95                     |
| 13            | PC1               | Digital GPIO (SPI Slave Select)         | SPI2_SS2 of RFM95                 |
| SDIO_D0       | PC8               | SD Card               | SD Card                           |          
| SDIO_D1       | PC9               | SD Card               | SD Card                           |
| SDIO_D2       | PC10              | SD Card               | SD Card                           |
| SDIO_D3       | PC11              | SD Card               | SD Card                           |
| SDIO_CLK      | PC12              | SD Card               | SD Card                           |
| SDIO_CMD      | PD2               | SD Card               | SD Card                           |
| SD_DETECT     | PB12              | SD Card               | SD Card                           |



### Pinout description for avionics system PCB design:
The table below describes the pin connections of the microcontroller and the other sensors on the avionics board. For a full connection diagram, refer to the schematic of the main avionics board.


| MCU Pin   |  MCU Reference    | Pin Requirements              | Pin Function                  |
|-----------|-------------------|-------------------------------|-------------------------------|
| 1         | VBAT              | Battery input voltage (RTC)   | Power                         |
| 2         | PC13              | Unused                        | - |
| 3         | PC14              | Unused                        | - |
| 4         | PC15              | Heartbeat LED                 | GPIO Out |
| 5         | PHO               | Crystal input                 | Crystal |
| 6         | PH1               | Crystal output                | Crystal |
| 7         | NRST              | RESET pin                     | Reset |
| 8         | PC0               | Unused                        | - |
| 9         | PC1               | Unused                        | - |
| 10        | PC2               | Unused                        | - |
| 11        | PC3               | Unused                        | - |
| 12        | VSSA              | Analog ground                 | Power |
| 13        | VDDA              | Analog voltage supply         | Power |
| 14        | PA0               | Battery voltage sense         | GPIO Analog |
| 15        | PA1               | Reset for RFM95               | GPIO Out |
| 16        | PA2               | UART2_TX for GPS              | UART |
| 17        | PA3               | UART2_RX for GPS              | UART |
| 18        | VSS               | Ground                        | Power |
| 19        | VDD               | 3.3V supply                   | Power |
| 20        | PA4               | SPI1_NSS for Barometer        | SPI |
| 21        | PA5               | SPI1_SCK for Barometer        | SPI |
| 22        | PA6               | SPI1_MISO for Barometer       | SPI |
| 23        | PA7               | SPI1_MOSI for Barometer       | SPI |
| 24        | PC4               | IMU Interrupt 1               | External Interrupt (GPIO Input) |
| 25        | PC5               | IMU Interrupt 2               | External Interrupt (GPIO Input) |
| 26        | PB0               | SERVO 1 PWM                   | PWM |
| 27        | PB1               | Servo 2 PWM                   | PWM |
| 28        | PB2               | BOOT1                         | BOOT1 pin |
| 29        | PB10              | I2C2_SCL for IMU		| I2C |
| 30        | PB11              | I2C2_SDA for IMU		| I2C |
| 31        | VCAP              | Internal regulator capacitor  | Power |
| 32        | VDD               | 3.3V Supply                   | Power |
| 33        | PB12              | SPI2_NSS for RFM95            | SPI |
| 34        | PB13              | SPI2_SCK for RFM95            | SPI |
| 35        | PB14              | SPI2_MISO for RFM95           | SPI |
| 36        | PB15              | SPI2_MOSI for RFM95           | SPI |
| 37        | PC6               | UART6_TX (Breakout)           | UART |
| 38        | PC7               | UART6_RX                      | UART (Breakout) |
| 39        | PC8               | SDIO_D0 for SD Card           | SDIO |
| 40        | PC9               | SDIO_D1 for SD Card           | SDIO |
| 41        | PA8               | RFM95 Interrupt               | External Interrupt (GPIO Input) |
| 42        | PA9               | USB VBUS                      | USB OTG |
| 43        | PA10              | USB ID                        | USB OTG |
| 44        | PA11              | USB DM                        | USB OTG |
| 45        | PA12              | USB DP                        | USB OTG |
| 46        | PA13              | SWDIO for JTAG                | ARM_JTAG |
| 47        | VCAP              | Internal regulator capacitor  | Power |
| 48        | VDD               | 3.3V Supply                   | Power |
| 49        | PA14              | SWCLK for JTAG                | JTAG |
| 50        | PA15              | Unused                        | - |
| 51        | PC10              | SDIO_D2 for SD Card           | SDIO |
| 52        | PC11              | SDIO_D3 for SD Card           | SDIO |
| 53        | PC12              | SDIO_CK for SD Card           | SDIO |
| 54        | PD2               | SDIO_CMD for SD Card          | SDIO |
| 55        | PB3               | SWO for JTAG                  | JTAG |
| 56        | PB4               | Unused                        | - |
| 57        | PB5               | Eject 1 for Parachute         | GPIO Output |
| 58        | PB6               | Eject 2 for Parachute         | GPIO Output |
| 59        | PB7               | Eject 3 for Parachute         | GPIO Output |
| 60        | BOOT0             | BOOT0 for programming         | BOOT0 |
| 61        | PB8               | Unused                        | - |
| 62        | PB9               | SD_DETECT for SD card         | GPIO Input |
| 63        | VSS               | Ground                        | Power |
| 64        | VDD               | 3.3V Supply                   | Power |
