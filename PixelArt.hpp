/**
 * turkarshreyash@gmail.com
 * 
 * Copyleft (c) 2022 Innovation Eternity.
 * 
 *
 * Converging: Pixel travel towards center originating from both sides.
 * Diverging: Pixel travels towards sides originating from center.
 * rightTraveling: Pixel travels towards right originating from leftmost.
 * leftTraveling: Pixel travels towards left originating from rightmost.
 * Consistent: Pixel doesn't not travel. All LEDs are source.
 *
 */

#pragma once

#include <Adafruit_NeoPixel.h>
#include "BasePixelArt.hpp"


class ConvergingPixelArt: private BasePixelArt {
  

  public:

  ConvergingPixelArt(Adafruit_NeoPixel &pixel_strip,
                     uint16_t center,
                     uint16_t range,
                     float travel_loss=DEFAULT_TRAVEL_LOSS,
                     float self_loss=DEFAULT_PIXEL_LOSS);

  void update(uint8_t r, uint8_t g, uint8_t b);

};

class DivergingPixelArt: private BasePixelArt {
  

  public:

  DivergingPixelArt(Adafruit_NeoPixel &pixel_strip,
                     uint16_t center,
                     uint16_t range,
                     float travel_loss=DEFAULT_TRAVEL_LOSS,
                     float self_loss=DEFAULT_PIXEL_LOSS);

  void update(uint8_t r, uint8_t g, uint8_t b);

};

class RightTravellingPixelArt: private BasePixelArt {
  

  public:

  RightTravellingPixelArt(Adafruit_NeoPixel &pixel_strip,
                          uint16_t left,
                          uint16_t range,
                          float travel_loss=DEFAULT_TRAVEL_LOSS,
                          float self_loss=DEFAULT_PIXEL_LOSS);

  void update(uint8_t r, uint8_t g, uint8_t b);

};

class LeftTravellingPixelArt: private BasePixelArt {
  

  public:

  LeftTravellingPixelArt(Adafruit_NeoPixel &pixel_strip,
                         uint16_t right,
                         uint16_t range,
                         float travel_loss=DEFAULT_TRAVEL_LOSS,
                         float self_loss=DEFAULT_PIXEL_LOSS);

  void update(uint8_t r, uint8_t g, uint8_t b);

};

class ConsistentPixelArt: private BasePixelArt {
  

  public:

  ConsistentPixelArt(Adafruit_NeoPixel &pixel_strip,
                     uint16_t left,
                     uint16_t right,
                     float travel_loss=DEFAULT_TRAVEL_LOSS,
                     float self_loss=DEFAULT_PIXEL_LOSS);

  void update(uint8_t r, uint8_t g, uint8_t b);

};

/*
!nnovation Eternity
*/