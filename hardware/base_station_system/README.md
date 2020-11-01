A prototype base station system was developed in conjunction with the developement of the prototype avionics system. This system simply consists of an Arduino Uno board connected to a RFM95 LoRa module for communication with the avionics system.


### Pinout for base station prototype:

Below shows the pin connections of the base station. It simply consists of a RFM95 transceiver module connected to an Arduino Uno/Nano (or compatible) via an SPi interface.

| Arduino Pin   | MCU Reference | Pin Function      | Device Connection     |
| ------------- | ------------- | ----------------- | --------------------- |
| 13            | PB5           | SCK               | SCK of RFM95          |
| 12            | PB4           | MISO              | MISO of RFM95         |
| 11            | PB3           | MOSI              | MOSI of RFM95         |
| 10            | PB2           | SS                | CS of RFM95           |
| 9             | PB1           | Digital GPIO      | RESET of RFM95        |
| 3             | PD3           | Digital GPIO      | DIO1 of RFM95         |
| 2             | PD2           | Digital GPIO      | DIO0 of RFM95         |

