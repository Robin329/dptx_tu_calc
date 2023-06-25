#ifndef __VIDEO_H__
#define __VIDEO_H__
#include <stdint.h>

struct dtd {
  uint16_t pixel_repetition_input;
  uint32_t pixel_clock; /* pixelclock in KHz */
  uint8_t interlaced;   /* 1 for interlaced, 0 progressive */
  uint16_t h_active;
  uint16_t h_blanking;
  uint16_t h_image_size;
  uint16_t h_sync_offset; /* hactive front porch */
  uint16_t h_sync_pulse_width;
  uint8_t h_sync_polarity;
  uint16_t v_active;
  uint16_t v_blanking;
  uint16_t v_image_size;
  uint16_t v_sync_offset; /* vactive front porch */
  uint16_t v_sync_pulse_width;
  uint8_t v_sync_polarity;
};
struct video_timing {
  uint8_t display_protocol;
  uint8_t video_timing_id;
  struct dtd video_info;
};

#define DPTX_PHYIF_CTRL_RATE_RBR 0x0
#define DPTX_PHYIF_CTRL_RATE_HBR 0x1
#define DPTX_PHYIF_CTRL_RATE_HBR2 0x2
#define DPTX_PHYIF_CTRL_RATE_HBR3 0x3

#define DPTX_MP_SINGLE_PIXEL 0
#define DPTX_MP_DUAL_PIXEL 1
#define DPTX_MP_QUAD_PIXEL 2

enum { RGB = 0, YCBCR420 = 1, YCBCR422 = 2, YCBCR444 = 3, YONLY = 4, RAW = 5 };

enum { ITU601 = 1, ITU709 = 2 };

enum { CEA = 1, VESA = 2 };

enum {
  COLOR_DEPTH_INVALID = 0,
  COLOR_DEPTH_6 = 6,
  COLOR_DEPTH_8 = 8,
  COLOR_DEPTH_10 = 10,
  COLOR_DEPTH_12 = 12,
  COLOR_DEPTH_16 = 16
};

enum { VCEA = 0, CVT = 1, DMT = 2, USER = 3, INVALID = 0xFF };

int get_video_timing(struct video_timing *info, uint16_t refresh_rate);
#endif /* __VIDEO_H__ */