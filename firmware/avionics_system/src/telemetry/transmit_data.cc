#include "transmit_data.hh"

SX1278 radio = new Module(10, 2, 9, 3);

/**
 * Setup the radio transmitter system
 * Return 0 if setup was successful
 * Return 1 if setup failed.
 */
uint8_t transmit_data_ns::setup(){
    Serial.begin(9600);

    Serial.print("Initalizing telemetry system...");

    int state = radio.begin();
    if(state == ERR_NONE){
        return 0;
    }
    
    return 1;
}

/**
 * Transmit a string of data from the transciever
 * Return 0 is sucessfully sent.
 * Return 1 if an error occured.
 */
uint8_t transmit_data_ns::transmit(String toSend){

    //Check that the string to be transmitted is less than 256 characters.
    if(toSend.length() > 256){
        return 1;
    }

    int state = radio.transmit(toSend);

    if(state == ERR_NONE){
        return 0;
    }
    
    //An error occurred
    return 1;
}