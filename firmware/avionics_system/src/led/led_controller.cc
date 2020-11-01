#include "led_controller.hh"

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int led_controller_ns::setup_leds() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear(); // Set all pixel colors to 'off'
  return 0;
}

void led_controller_ns::solid_colour(int r, int g, int b, led led) {
  pixels.setPixelColor(0, pixels.Color(r, g, b));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(SOLID_DELAY); // Pause before next passing on
}

void led_controller_ns::blink_colour(int r, int g, int b, int loop_times, led led) {
  for (int i = 0; i  < loop_times; i++) {
    pixels.setPixelColor(0, pixels.Color(r, g, b));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(BLINK_DELAY); // Pause before next passing on
    pixels.clear();
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(BLINK_DELAY); // Pause before next passing on
  }
}

void led_controller_ns::gradualIncrease(int type, int rate, led led) {
  int loopIndex = 0;
  int maxIndex = 100;
  while (loopIndex < maxIndex) {

    if (type == 1) {
      solid_colour(maxIndex-loopIndex, loopIndex, 0, led);
    } else if (type == 2) {
      solid_colour(0, maxIndex-loopIndex, loopIndex, led);
    } else {
      solid_colour(loopIndex, 0, maxIndex-loopIndex, led);
    }

  loopIndex += rate;
  }
  
}

