# README for the Avionics System

## Avionics System Platform

The Avionic System was developed on the [**PlatformIO**](https://platformio.org/) platform, with the STM32F405 Chip.

## What does the System do?

This system does not perform what we had originally set out to do for our minimum viable product. There were several issues that had occured during the development of the rocket, in particular the delays in hardware testing, and software integration. Our software in our avionics system performs the following:

* **Has a functioning Finite State Machine (FSM)**
  * Each state of the FSM can be determined through the on-board RGB LED on the STM32F405 chip. The states include:
    * **Boot Up** - This is not explicity a state, however it sets up all proprietary requirements from the Arduino Framework such as LED capabilities. This is represented on the on-board chip with 10 Red Blinks, then 10 Green Blinks. 
    * **Initialisation** - This sets up the sensors and other components so they are active. The LED colour on the on-board chip is Orange.
    * **Test** - This performs a series of tests to make sure that the sensors are working. The LED colour on the on-board chip is Yellow. The LED will also represent each of the possible errors that can occur during the testing. These are:
      * **Battery Failure** - Cyan
      * **GPS Failure** - Mauve (Purple/Brown)
      * **Accelerometer** Failure - Chareuse (Yellow)
      * **Barometer Failure** - Teal
      * **Temperature Sensor Failure** - Russet (Brown)
      * **Radio Link Failure** - White
      * **Gimbal Failure** - Hot Pink
      * **Black Box Failure** - Glaucous (Blue)
    * **Idle** - The is when the system is ready to be launched, but is not launched yet. The LED colour on the on-board chip is Green.
    * **Launch Sequence** - This is when the system is performing the launch sequence. This state includes a countdown. The idea is that the interupts via the Radio Link can stop the countdown, and put the system into failure. The LED colour on the on-board chip is Cyan.
    * **Ignition** - This is when the system's software lock on the ignition is freed, and the rocket is available to be launched via hardware implementations. The LED colour on the on-board chip is Blue.
    * **Flight** - This is when the system is in flight upwards. The idea is that the system should be able to adjust the direction of flight via gimbal adjustments, transmit data to the base station, and store the same information on the black-box storage. This state is changed into the Post Flight state, given that the rocket's barometers detects a drop in altitude. The LED colour on the on-board chip is Purple.
    * **Post Flight** - This is when the rocket has determined that is has fallen down, and performs the same actions as the flight state. The main difference is that in this state, it checks if the rocket has stopped falling and has landed (when the rocket has not adjusted its altitude within a threshold over a period of 60 ticks). The LED colour on the on-board chip is Magenta.
    * **Finished** - This is when the rocket has finally "landed", and is simply the idle state, except it performs additional actions, most notably the buzzer going off (hardware implementation and code implementation of this needs to be added). the LED colour on the on-board chip is Green.
    * **Failed** - This is the state that the FSM gets stuck in if there are any failure issues that occur during almost every point of the system. The exception to this is during Flight/Post Flight, as the rocket should still perform actions during failure, and instead transmit/record the failure.
  * At each loop iteration of the system, the on-board chip will blink blue 4 times.
  * With the current state of the FSM, the code will cycle through all the states of a functioning program.
* **Has an Easily Expandable Code Structure**
  * Additional/changes to the sensor code can easily performed as the struture of the code is broken down and separated into appropriately named files and folders.
* **Has Mutliple Environments**
  * There exists 3 different PlatformIO environments, each for different purposes:
    * **hardware** - This is the enviroment for the stsm32 chipset platform, the chipset that the current rocket hardware is built on.
    * **cicd** - The is the environment used for the CICD process. This is similar to the hardware environment, except it removes several library dependencies and excess code that stops it working on the CICD.
    * **native** - This is the environment that is used for testing on the PlatformIO testing process. It is important to note that Arduino code libraries DO NOT work on this environment, and hence explains the lack of tests performed.


## What does the System not do?

Due to issues with rocket hardware, ECS hardware and sudden software adjustments, the code does not perform the following:

* Sensors on the System are not implemented/function properly in the Avionics System. This includes the Barometer and Accelerometer.
* The gimbal actuation using the pair of servo motors was unable to be fully integrated with the system due to issues with Arduino libraries and our development environment of choice, PIO. Integration of the gimbal system was also difficult due to lack of access to a power supply to connect the gimbal and systems to.
* The Radio-Link is not functioning on the software side.
* handle_control() in *src/launch/flight.cc* needs to be implemented to handle the IMU and data recording.
* ignition.cc as a whole in *src/pre_flight/ignition.cc* needs to be implemented. This is the software unlocks, which can be as simple as a LED to say when the rocket is ready to be ignited, to more complicated unlocks (eg. software forces the rocket to allow itself to be armed) when the situation changes arrive.

## What does the System allow for?

Even though not everything was implemented, the code base was designed with extensibility in mind. Other than was implemented, the code base allows for:
* Additional sensor implementations through adding it to the initialisation, test and any file where the sensors would be used.
* The ability to have more complex ignition systems with proper software launch locks (*See src/pre_flight/ignition.cc*).
* The ability to adjust the chipset used for the hardware (due to the PlatformIO platform being used).

## How to Run the System

* The avionics system was developed using the [**PlatformIO**](https://platformio.org/) platform.
* To run the program, you will need to plug in the STM32F405 chip with a USB-C input, press the reset button on the chip, and then type the following command in the PlatformIO Terminal:
  * ```platformio run --target upload -e hardware```

