/**
 * turkarshreyash@gmail.com
 * 
 * Copyleft (c) 2022 Innovation Eternity.
 * 
 */

#include "PixelArt.hpp"


ConvergingPixelArt::ConvergingPixelArt(Adafruit_NeoPixel &pixel_strip,
    uint16_t center, uint16_t range, float travel_loss=DEFAULT_TRAVEL_LOSS,
    float pixel_loss=DEFAULT_PIXEL_LOSS): BasePixelArt(pixel_strip, travel_loss,
    pixel_loss){

  uint16_t length = pixel_strip.numPixels();
  this->center = center;
  this->left = (center > range)?(center - range):0;
  this->right = min(center + range, length);
}

void ConvergingPixelArt::update(uint8_t r, uint8_t g, uint8_t b){
  this->left_shift_pixels(this->center, this->right);
  this->right_shift_pixels(this->left, this->center);
  this->update_pixel(this->left, r, g, b);
  this->update_pixel(this->right, r, g, b);
}

DivergingPixelArt::DivergingPixelArt(Adafruit_NeoPixel &pixel_strip,
    uint16_t center, uint16_t range, float travel_loss=DEFAULT_TRAVEL_LOSS,
    float pixel_loss=DEFAULT_PIXEL_LOSS): BasePixelArt(pixel_strip, travel_loss,
     pixel_loss){

  uint16_t length = pixel_strip.numPixels();
  this->center = center;
  this->left = (center > range)?(center - range):0;
  this->right = min(center + range, length);
}

void DivergingPixelArt::update(uint8_t r, uint8_t g, uint8_t b){
  this->right_shift_pixels(this->center, this->right);
  this->left_shift_pixels(this->left, this->center);
  this->update_pixel(this->center, r, g, b);
}

RightTravellingPixelArt::RightTravellingPixelArt(Adafruit_NeoPixel &pixel_strip,
    uint16_t left, uint16_t range, float travel_loss=DEFAULT_TRAVEL_LOSS,
    float pixel_loss=DEFAULT_PIXEL_LOSS): BasePixelArt(pixel_strip, travel_loss,
     pixel_loss){
  
  uint16_t length = pixel_strip.numPixels();
  this->left = left;
  this->right = min(left + range, length);
}

void RightTravellingPixelArt::update(uint8_t r, uint8_t g, uint8_t b){
  this->right_shift_pixels(this->left, this->right);
  this->update_pixel(this->left, r, g, b);
}

LeftTravellingPixelArt::LeftTravellingPixelArt(Adafruit_NeoPixel &pixel_strip,
    uint16_t right, uint16_t range, float travel_loss=DEFAULT_TRAVEL_LOSS,
    float pixel_loss=DEFAULT_PIXEL_LOSS): BasePixelArt(pixel_strip, travel_loss,
     pixel_loss){
  
  uint16_t length = pixel_strip.numPixels();
  this->left = (right > range)?(right - range):0;
  this->right = min(right, length);
}

void LeftTravellingPixelArt::update(uint8_t r, uint8_t g, uint8_t b){
  this->left_shift_pixels(this->left, this->right);
  this->update_pixel(this->right, r, g, b);
}

ConsistentPixelArt::ConsistentPixelArt(Adafruit_NeoPixel &pixel_strip,
    uint16_t left, uint16_t right, float travel_loss=DEFAULT_TRAVEL_LOSS,
    float pixel_loss=DEFAULT_PIXEL_LOSS): BasePixelArt(pixel_strip, travel_loss,
     pixel_loss){
  
  uint16_t length = pixel_strip.numPixels();
  this->left = left;
  this->right = min(right, length);
}

void ConsistentPixelArt::update(uint8_t r, uint8_t g, uint8_t b){
  for (uint16_t index = this->left ; index <= this->right ; ++index)
    this->update_pixel(index, r, g, b);
}
/*
!nnovation Eternity
*/