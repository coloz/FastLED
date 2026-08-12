/// @file    CI130X.ino
/// @brief   Drives a WS2812 strip from a Chipintelli CI130X board
/// @example CI130X.ino

#include <Arduino.h>
#include <FastLED.h>

#if defined(ARDUINO_CI1306) || defined(ARDUINO_CI_D06GT01D)
#define DATA_PIN PD0
#elif defined(ARDUINO_ARCH_CI13XX)
#define DATA_PIN PA4
#else
// Keep the example buildable in FastLED's cross-platform example tests.
#define DATA_PIN 4
#endif

#define NUM_LEDS 8
#define BRIGHTNESS 32

CRGB leds[NUM_LEDS];

static const CRGB COLORS[] = {
    CRGB::Red,
    CRGB::Green,
    CRGB::Blue,
    CRGB::White,
};

static const char *const COLOR_NAMES[] = {
    "red",
    "green",
    "blue",
    "white",
};

void setup() {
    Serial.begin(115200);
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.clear(true);
    Serial.println("FastLED CI130X WS2812 test started");
}

void loop() {
    static uint8_t colorIndex = 0;
    fill_solid(leds, NUM_LEDS, COLORS[colorIndex]);
    FastLED.show();
    Serial.println(COLOR_NAMES[colorIndex]);
    colorIndex = (colorIndex + 1U) % 4U;
    delay(600);
}
