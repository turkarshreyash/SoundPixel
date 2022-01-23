/**
 * turkarshreyash@gmail.com
 * 
 * Copyright (c) 2022 Innovation Eternity.
 * 
 */

#pragma once

#include <Adafruit_NeoPixel.h>

#define DEFAULT_TRAVEL_LOSS 0.25f
#define DEFAULT_PIXEL_LOSS 0.25f

#define GET_RED(COLOR)  (uint8_t)(COLOR >> 16)
#define GET_GREEN(COLOR) (uint8_t)(COLOR >> 8)
#define GET_BLUE(COLOR) (uint8_t)(COLOR)

class BasePixelArt {

  float travel_loss;
  float pixel_loss;


  static uint32_t calculate_loss(uint32_t color, float loss);

  static uint32_t blend_colors(uint32_t color1, uint32_t color2);

  static uint8_t blend_color_value(uint8_t value1, uint8_t value2);


  protected:

  uint16_t center;
  uint16_t left; 
  uint16_t right;
  Adafruit_NeoPixel &pixel_strip;


  BasePixelArt(Adafruit_NeoPixel &pixel_strip, float travel_loss, float pixel_loss);


  void update_pixel(uint16_t pixel, uint16_t prev_pixel);

  void update_pixel(uint16_t pixel, uint8_t r, uint8_t g, uint8_t b);


  void left_shift_pixels(uint16_t start, uint16_t end);

  void right_shift_pixels(uint16_t start, uint16_t end);


  public:

  void update();
};

/*
!nnovation Eternity
*/