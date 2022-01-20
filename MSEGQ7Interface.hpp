/**
 * turkarshreyash@gmail.com
 * 
 * Copyright (c) 2022 Innovation Eternity.
 * 
 * Hardware interface for MSGEQ7 chip. 
 */

#pragma once

#include <unistd.h>
#include "Arduino.h"


// Arduino dependencies.
#define ARDUINO_SET_INPUT(PIN_NUM) pinMode(PIN_NUM, INPUT)
#define ARDUINO_SET_OUTPUT(PIN_NUM) pinMode(PIN_NUM, OUTPUT)
#define ARDUINO_HIGH(PIN_NUM) digitalWrite(PIN_NUM, HIGH)
#define ARDUINO_LOW(PIN_NUM) digitalWrite(PIN_NUM, LOW)
#define ARDUINO_READ(PIN_NUM) analogRead(PIN_NUM)
#define ARDUINO_DELAY(SECS) delay(SECS)
#define ARDUINO_DELAY_USECS(USECS) delayMicroseconds(USECS)

#define MSGEQ7_STARTUP_DELAY 36
#define MSGEQ7_RESET_PULSE_WIDTH_US 1
#define MSGEQ7_RESET_TO_STROBE_DELAY_US 72
#define MSGEQ7_STROBE_PULSE_WIDTH_US 18
#define MSGEQ7_OUTPUT_SETTLE_TIME_US 36
#define MSGEQ7_STROBE_TO_STROBE_DELAY_US 72

#define F_63HZ 0
#define F_160HZ 1
#define F_400HZ 2
#define F_1KHZ 3
#define F_2500HZ 4 
#define F_6250KHZ 5
#define F_16KH6 6

class MSGEQ7Interface{

  static uint16_t read_cutoff[7];
  static uint16_t final_cutoff[7];

  // Pin numbers.
  uint8_t reset_pin;
  uint8_t strobe_pin;
  uint8_t analogin_pin;

  uint8_t number_samples;

  void read_ready();
  uint16_t read_analog_in();

  public:
  MSGEQ7Interface(uint8_t, uint8_t, uint8_t, uint8_t);
  void setup();
  void get_frequency_amp(uint16_t[7]);
};

/*
!nnovation Eternity
*/