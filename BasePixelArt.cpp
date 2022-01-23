/**
 * turkarshreyash@gmail.com
 * 
 * Copyleft (c) 2022 Innovation Eternity.
 * 
 */

#include "BasePixelArt.hpp"

BasePixelArt::BasePixelArt(Adafruit_NeoPixel &pixel_strip,
                           float travel_loss,
                           float pixel_loss): pixel_strip(pixel_strip){

  this->travel_loss = travel_loss;
  this->pixel_loss = pixel_loss;
}

static uint32_t BasePixelArt::calculate_loss(uint32_t color, float loss){
  float r = GET_RED(color);
  float g = GET_GREEN(color);
  float b = GET_BLUE(color);

  uint8_t loss_r = r * (1.0f - loss);
  uint8_t loss_g = g * (1.0f - loss);
  uint8_t loss_b = b * (1.0f - loss);

  return Adafruit_NeoPixel::Color(loss_r, loss_g, loss_b);
}

static uint8_t BasePixelArt::blend_color_value(uint8_t value1, uint8_t value2){
  return max(value1, value2);
}

static uint32_t BasePixelArt::blend_colors(uint32_t color1, uint32_t color2){

  uint8_t r = BasePixelArt::blend_color_value(GET_RED(color1),
                                              GET_RED(color2));

  uint8_t g = BasePixelArt::blend_color_value(GET_GREEN(color1),
                                              GET_GREEN(color2));

  uint8_t b = BasePixelArt::blend_color_value(GET_BLUE(color1),
                                              GET_BLUE(color2));

  return Adafruit_NeoPixel::Color(r, g, b);
}

void BasePixelArt::update_pixel(uint16_t pixel, uint16_t prev_pixel){

  uint32_t color = pixel_strip.getPixelColor(pixel);
  uint32_t color_loss = this->calculate_loss(color, this->pixel_loss);

  uint32_t prev_pixel_color = pixel_strip.getPixelColor(prev_pixel);
  uint32_t prev_pixel_color_loss = this->calculate_loss(prev_pixel_color,
                                                        this->travel_loss);

  uint32_t blended = this->blend_colors(color_loss, prev_pixel_color_loss);

  pixel_strip.setPixelColor(pixel, blended);
}

void BasePixelArt::update_pixel(uint16_t pixel, uint8_t r, uint8_t g, uint8_t b){
  uint32_t color = Adafruit_NeoPixel::Color(r, g, b);
  pixel_strip.setPixelColor(pixel, color);
}

void BasePixelArt::left_shift_pixels(uint16_t left, uint16_t right){
  for(uint16_t index = left ; index < right ; ++index){
    this->update_pixel(index, index+1);
  }
}

void BasePixelArt::right_shift_pixels(uint16_t left, uint16_t right){
  for(uint16_t index = right ; index > left ; --index){
    this->update_pixel(index, index-1);
  }
}


/*
!nnovation Eternity
*/