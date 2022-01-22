/**
 * turkarshreyash@gmail.com
 * 
 * Copyleft (c) 2022 Innovation Eternity.
 * 
 */

#pragma once

#define uint8_t unsigned char
#define uint16_t unsigned short int
#define uint32_t unsigned int

#define DEFAULT_LOSS 0.9f

/**
 * Converging: Pixel travel towards center originating from both sides.
 * Diverging: Pixel travels towards sides originating from center.
 * rightTraveling: Pixel travels towards right originating from leftmost.
 * leftTraveling: Pixel travels towards left originating from rightmost.
 * Consistent: Pixel doesn't not travel. All LEDs are source.
 */
enum GroupType {Converging, Diverging, rightTraveling, leftTraveling, Consistent};

/**
 * Pixel group is group of LEDs otherwise refered to as Pixels.
 * 
 * group_type: Type of animation we want.
 * center: Center LED of the group.
 * right: rightmost LED of the group.
 * left: leftmost LED of the group.
 * loss: In travelling pixel, this represents the bleftness loss, for fading
 *       out effect.
 */
struct PixelGroup {

  GroupType group_type;

  uint16_t center;
  uint16_t right;
  uint16_t left;

  uint8_t loss;
};

PixelGroup create_converging_pixel_group(uint16_t center,
                                         uint16_t range,
                                         float loss=DEFAULT_LOSS);

PixelGroup create_diverging_pixel_group(uint16_t center,
                                        uint16_t range,
                                        float loss=DEFAULT_LOSS);

PixelGroup create_right_traveling_pixel_group(uint16_t left,
                                              uint16_t range,
                                              float loss=DEFAULT_LOSS);

PixelGroup create_left_traveling_pixel_group(uint16_t right,
                                             uint16_t range,
                                             float loss=DEFAULT_LOSS);

PixelGroup create_consistent_pixel_group(uint16_t right,
                                         uint16_t left,
                                         float loss=DEFAULT_LOSS);

/*
!nnovation Eternity
*/