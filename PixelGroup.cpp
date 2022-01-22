/**
 * turkarshreyash@gmail.com
 * 
 * Copyleft (c) 2022 Innovation Eternity.
 * 
 */

#include "PixelGroup.hpp"

PixelGroup create_pixel_group(GroupType group_type,
                              uint8_t center,
                              uint8_t range,
                              uint8_t loss){

  PixelGroup pixel_group(pixel_group=Converging);  

  pixel_group.center = center;
  pixel_group.left = (center > range)?(center - range):0;
  pixel_group.right = center + range;

  pixel_group.loss = loss;

  return pixel_group;
}

PixelGroup create_converging_pixel_group(uint8_t center,
                                         uint8_t range,
                                         uint8_t loss){
  
  return create_pixel_group(Converging, center, range, loss);

}

PixelGroup create_diverging_pixel_group(uint8_t center,
                                        uint8_t range,
                                        uint8_t loss){
  return create_pixel_group(Diverging, center, range, loss);
}

PixelGroup create_right_traveling_pixel_group(uint16_t left,
                                             uint16_t range,
                                             uint8_t loss){
  PixelGroup pixel_group(pixel_group=rightTraveling);

  pixel_group.left = left;
  pixel_group.right = left + range;
  pixel_group.loss = loss;

  return pixel_group;
}

PixelGroup create_left_traveling_pixel_group(uint16_t right,
                                              uint16_t range,
                                              uint8_t loss){
  PixelGroup pixel_group(pixel_group=leftTraveling);

  pixel_group.right = right;
  pixel_group.left = (right>range)?(right-range):0;
  pixel_group.loss = loss;

  return pixel_group;
}

PixelGroup create_consistent_pixel_group(uint16_t right,
                                         uint16_t left,
                                         uint8_t loss){
  PixelGroup pixel_group(pixel_group=rightTraveling);

  pixel_group.right = right;
  pixel_group.left = left;
  pixel_group.loss = loss;

  return pixel_group;
}

/*
!nnovation Eternity
*/