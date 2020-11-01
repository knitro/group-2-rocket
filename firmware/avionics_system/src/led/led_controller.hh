#ifndef _LED_CONTROLLER_
#define _LED_CONTROLLER_

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

/*Definitions*/
#define PIN           8 
#define NUMPIXELS     1     // How many NeoPixels are attached to the Arduino?
#define BLINK_DELAY   250   // Time (in milliseconds) to pause. In this case 250s. Used for Blink Delay
#define SOLID_DELAY   2000  // Time (in milliseconds) to pause. In this case 1000s. Used for Solid Colour

namespace led_controller_ns {

  enum led {
    chip_led = 1
  };

  /*Methods*/
  int setup_leds();
  void solid_colour(int r, int g, int b, led led);
  void blink_colour(int r, int g, int b, int loop_times, led led);
  void gradualIncrease(int type, int rate, led led);

}

#endif /*_LED_CONTROLLER_*/
