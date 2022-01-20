/**
 * turkarshreyash@gmail.com
 * 
 * Copyright (c) 2022 Innovation Eternity.
 * 
 */

#include"MSEGQ7Interface.hpp"

// Don't change calibrated on: 20 January 2022.
uint16_t MSGEQ7Interface::read_cutoff[7] = {125,150,150,160,225,360,1023};
uint16_t MSGEQ7Interface::final_cutoff[7] = {160,100,120,120,160,200,1023};

/**
 * @brief Construct a new msgeq7 interface::msgeq7 interface object
 * 
 * @param reset_pin 
 * @param strobe_pin 
 * @param analog_in 
 * @param number_samples 
 */
MSGEQ7Interface::MSGEQ7Interface(uint8_t reset_pin,
                                   uint8_t strobe_pin,
                                   uint8_t analog_in,
                                   uint8_t number_samples){
  this->reset_pin = reset_pin;
  this->strobe_pin = strobe_pin;
  this->analogin_pin = analog_in;
  this->number_samples = number_samples<10?number_samples:9;
  ARDUINO_DELAY_USECS(MSGEQ7_STARTUP_DELAY);
}

/**
 * @brief Setups pins.
 * 
 */
void MSGEQ7Interface::setup(){
  ARDUINO_SET_INPUT(this->analogin_pin);
  ARDUINO_SET_OUTPUT(this->reset_pin);
  ARDUINO_SET_OUTPUT(this->strobe_pin);
  ARDUINO_LOW(this->reset_pin);
  ARDUINO_HIGH(this->strobe_pin);
}

/**
 * @brief Setup MSGEQ7 for reading data.
 * 
 */
inline void MSGEQ7Interface::read_ready(){
  ARDUINO_HIGH(this->reset_pin);
  ARDUINO_DELAY_USECS(MSGEQ7_RESET_PULSE_WIDTH_US);
  ARDUINO_LOW(this->reset_pin);
  ARDUINO_DELAY_USECS(MSGEQ7_RESET_TO_STROBE_DELAY_US);
}

/**
 * @brief Read amplitude for a frequency.
 * 
 * @return uint16_t
 */
inline uint16_t MSGEQ7Interface::read_analog_in(){
  ARDUINO_DELAY_USECS(MSGEQ7_STROBE_TO_STROBE_DELAY_US);
  ARDUINO_LOW(this->strobe_pin);
  ARDUINO_DELAY_USECS(MSGEQ7_OUTPUT_SETTLE_TIME_US);
  uint16_t analog_value = ARDUINO_READ(this->analogin_pin);
  ARDUINO_HIGH(this->strobe_pin);
  return analog_value;
}

/**
 * @brief Read amplitude for all 7 frequencies.
 * 
 * @param freq_amp_values 
 */
void MSGEQ7Interface::get_frequency_amp(uint16_t freq_amp_values[7]){

  memset(freq_amp_values, 0, 14);

  for(uint8_t sample_index = 0; sample_index < this->number_samples; ++sample_index){
    this->read_ready();
    for(uint8_t freq_index = 0; freq_index < 7; ++freq_index){
      uint16_t freq_amp_value = this->read_analog_in();
      if (freq_amp_value < MSGEQ7Interface::read_cutoff[freq_index]){
        continue;
      }
      freq_amp_values[freq_index] += freq_amp_value;
    }
  }

  for(uint8_t freq_index = 0; freq_index <7; ++freq_index){
    freq_amp_values[freq_index]/=this->number_samples;
    if(freq_amp_values[freq_index] < MSGEQ7Interface::final_cutoff[freq_index]){
      freq_amp_values[freq_index] = 0;
    }
  }

}

/*
!nnovation Eternity
*/