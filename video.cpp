#include <stdint.h>
#include "video.h"

#if __has_attribute(__fallthrough__)
#define fallthrough __attribute__((__fallthrough__))
#else
#define fallthrough \
  do {              \
  } while (0) /* fallthrough */
#endif

int get_video_timing(struct video_timing *info, uint16_t refresh_rate) {
  if (!info) {
    return -1;
  }
  if (info->display_protocol == VCEA) {
    switch (info->video_timing_id) {
      case 1: /* 640x480p @ 59.94/60Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 640;
        info->video_info.v_active = 480;
        info->video_info.h_blanking = 160;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 16;
        info->video_info.v_sync_offset = 10;
        info->video_info.h_sync_pulse_width = 96;
        info->video_info.v_sync_pulse_width = 2;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 25175;
        break;
      case 2: /* 720x480p @ 59.94/60Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 3: /* 720x480p @ 59.94/60Hz 16:9 */
        info->video_info.h_active = 720;
        info->video_info.v_active = 480;
        info->video_info.h_blanking = 138;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 16;
        info->video_info.v_sync_offset = 9;
        info->video_info.h_sync_pulse_width = 62;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 27000;
        break;
      case 69:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 4: /* 1280x720p @ 59.94/60Hz 16:9 */
        info->video_info.h_active = 1280;
        info->video_info.v_active = 720;
        info->video_info.h_blanking = 370;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 110;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 40;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 74250;
        break;
      case 5: /* 1920x1080i @ 59.94/60Hz 16:9 */
        info->video_info.h_active = 1920;
        info->video_info.v_active = 540;
        info->video_info.h_blanking = 280;
        info->video_info.v_blanking = 22;
        info->video_info.h_sync_offset = 88;
        info->video_info.v_sync_offset = 2;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 1;
        info->video_info.pixel_clock = 74250;
        break;
      case 6: /* 720(1440)x480i @ 59.94/60Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 7: /* 720(1440)x480i @ 59.94/60Hz 16:9 */
        info->video_info.h_active = 1440;
        info->video_info.v_active = 240;
        info->video_info.h_blanking = 276;
        info->video_info.v_blanking = 22;
        info->video_info.h_sync_offset = 38;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 124;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 1;
        info->video_info.pixel_clock = 27000;
        break;
      case 8: /* 720(1440)x240p @ 59.826/60.054/59.886/60.115Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 9: /* 720(1440)x240p @59.826/60.054/59.886/60.115Hz 16:9 */
        info->video_info.h_active = 1440;
        info->video_info.v_active = 240;
        info->video_info.h_blanking = 276;
        info->video_info.v_blanking = (refresh_rate == 59940) ? 22 : 23;
        info->video_info.h_sync_offset = 38;
        info->video_info.v_sync_offset = (refresh_rate == 59940) ? 4 : 5;
        info->video_info.h_sync_pulse_width = 124;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 27000;
        break;
      case 10: /* 2880x480i @ 59.94/60Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 11: /* 2880x480i @ 59.94/60Hz 16:9 */
        info->video_info.h_active = 2880;
        info->video_info.v_active = 240;
        info->video_info.h_blanking = 552;
        info->video_info.v_blanking = 22;
        info->video_info.h_sync_offset = 76;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 248;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 1;
        info->video_info.pixel_clock = 54000;
        break;
      case 12: /* 2880x240p @ 59.826/60.054/59.886/60.115Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 13: /* 2880x240p @ 59.826/60.054/59.886/60.115Hz 16:9 */
        info->video_info.h_active = 2880;
        info->video_info.v_active = 240;
        info->video_info.h_blanking = 552;
        info->video_info.v_blanking = (refresh_rate == 60054) ? 22 : 23;
        info->video_info.h_sync_offset = 76;
        info->video_info.v_sync_offset = (refresh_rate == 60054) ? 4 : 5;
        info->video_info.h_sync_pulse_width = 248;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 54000;
        break;
      case 14: /* 1440x480p @ 59.94/60Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 15: /* 1440x480p @ 59.94/60Hz 16:9 */
        info->video_info.h_active = 1440;
        info->video_info.v_active = 480;
        info->video_info.h_blanking = 276;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 32;
        info->video_info.v_sync_offset = 9;
        info->video_info.h_sync_pulse_width = 124;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 54000;
        break;
      case 76:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 16: /* 1920x1080p @ 59.94/60Hz 16:9 */
        info->video_info.h_active = 1920;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 280;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 88;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 148500;
        break;
      case 17: /* 720x576p @ 50Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 18: /* 720x576p @ 50Hz 16:9 */
        info->video_info.h_active = 720;
        info->video_info.v_active = 576;
        info->video_info.h_blanking = 144;
        info->video_info.v_blanking = 49;
        info->video_info.h_sync_offset = 12;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 64;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 27000;
        break;
      case 68:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 19: /* 1280x720p @ 50Hz 16:9 */
        info->video_info.h_active = 1280;
        info->video_info.v_active = 720;
        info->video_info.h_blanking = 700;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 440;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 40;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 74250;
        break;
      case 20: /* 1920x1080i @ 50Hz 16:9 */
        info->video_info.h_active = 1920;
        info->video_info.v_active = 540;
        info->video_info.h_blanking = 720;
        info->video_info.v_blanking = 22;
        info->video_info.h_sync_offset = 528;
        info->video_info.v_sync_offset = 2;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 1;
        info->video_info.pixel_clock = 74250;
        break;
      case 21: /* 720(1440)x576i @ 50Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 22: /* 720(1440)x576i @ 50Hz 16:9 */
        info->video_info.h_active = 1440;
        info->video_info.v_active = 288;
        info->video_info.h_blanking = 288;
        info->video_info.v_blanking = 24;
        info->video_info.h_sync_offset = 24;
        info->video_info.v_sync_offset = 2;
        info->video_info.h_sync_pulse_width = 126;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 1;
        info->video_info.pixel_clock = 27000;
        break;
      case 23: /* 720(1440)x288p @ 50Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 24: /* 720(1440)x288p @ 50Hz 16:9 */
        info->video_info.h_active = 1440;
        info->video_info.v_active = 288;
        info->video_info.h_blanking =
            (refresh_rate == 50080) ? 24 : ((refresh_rate == 49920) ? 25 : 26);
        info->video_info.v_blanking = 24;

        info->video_info.h_sync_offset =
            (refresh_rate == 50080) ? 2 : ((refresh_rate == 49920) ? 3 : 4);
        info->video_info.v_sync_offset = 2;
        info->video_info.h_sync_pulse_width = 126;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 27000;
        break;
      case 25: /* 2880x576i @ 50Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 26: /* 2880x576i @ 50Hz 16:9 */
        info->video_info.h_active = 2880;
        info->video_info.v_active = 288;
        info->video_info.h_blanking = 576;
        info->video_info.v_blanking = 24;
        info->video_info.h_sync_offset = 48;
        info->video_info.v_sync_offset = 2;
        info->video_info.h_sync_pulse_width = 252;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 1;
        info->video_info.pixel_clock = 54000;
        break;
      case 27: /* 2880x288p @ 50Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 28: /* 2880x288p @ 50Hz 16:9 */
        info->video_info.h_active = 2880;
        info->video_info.v_active = 288;
        info->video_info.h_blanking = 576;
        info->video_info.v_blanking =
            (refresh_rate == 50080) ? 24 : ((refresh_rate == 49920) ? 25 : 26);
        info->video_info.h_sync_offset =
            (refresh_rate == 50080) ? 2 : ((refresh_rate == 49920) ? 3 : 4);
        info->video_info.v_sync_offset = 2;
        info->video_info.h_sync_pulse_width = 252;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 54000;
        break;
      case 29: /* 1440x576p @ 50Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 30: /* 1440x576p @ 50Hz 16:9 */
        info->video_info.h_active = 1440;
        info->video_info.v_active = 576;
        info->video_info.h_blanking = 288;
        info->video_info.v_blanking = 49;
        info->video_info.h_sync_offset = 24;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 128;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 54000;
        break;
      case 75:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 31: /* 1920x1080p @ 50Hz 16:9 */
        info->video_info.h_active = 1920;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 720;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 528;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 148500;
        break;
      case 72:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 32: /* 1920x1080p @ 23.976/24Hz 16:9 */
        info->video_info.h_active = 1920;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 830;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 638;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 74250;
        break;
      case 73:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 33: /* 1920x1080p @ 25Hz 16:9 */
        info->video_info.h_active = 1920;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 720;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 528;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 74250;
        break;
      case 74:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 34: /* 1920x1080p @ 29.97/30Hz 16:9 */
        info->video_info.h_active = 1920;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 280;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 88;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 74250;
        break;
      case 35: /* 2880x480p @ 60Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 36: /* 2880x480p @ 60Hz 16:9 */
        info->video_info.h_active = 2880;
        info->video_info.v_active = 480;
        info->video_info.h_blanking = 552;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 64;
        info->video_info.v_sync_offset = 9;
        info->video_info.h_sync_pulse_width = 248;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 108000;
        break;
      case 37: /* 2880x576p @ 50Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 38: /* 2880x576p @ 50Hz 16:9 */
        info->video_info.h_active = 2880;
        info->video_info.v_active = 576;
        info->video_info.h_blanking = 576;
        info->video_info.v_blanking = 49;
        info->video_info.h_sync_offset = 48;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 256;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 108000;
        break;
      case 39: /* 1920x1080i (1250 total) @ 50Hz 16:9 */
        info->video_info.h_active = 1920;
        info->video_info.v_active = 540;
        info->video_info.h_blanking = 384;
        info->video_info.v_blanking = 85;
        info->video_info.h_sync_offset = 32;
        info->video_info.v_sync_offset = 23;
        info->video_info.h_sync_pulse_width = 168;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 1;
        info->video_info.pixel_clock = 72000;
        break;
      case 40: /* 1920x1080i @ 100Hz 16:9 */
        info->video_info.h_active = 1920;
        info->video_info.v_active = 540;
        info->video_info.h_blanking = 720;
        info->video_info.v_blanking = 22;
        info->video_info.h_sync_offset = 528;
        info->video_info.v_sync_offset = 2;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 1;
        info->video_info.pixel_clock = 148500;
        break;
      case 70:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 41: /* 1280x720p @ 100Hz 16:9 */
        info->video_info.h_active = 1280;
        info->video_info.v_active = 720;
        info->video_info.h_blanking = 700;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 440;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 40;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 148500;
        break;
      case 42: /* 720x576p @ 100Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 43: /* 720x576p @ 100Hz 16:9 */
        info->video_info.h_active = 720;
        info->video_info.v_active = 576;
        info->video_info.h_blanking = 144;
        info->video_info.v_blanking = 49;
        info->video_info.h_sync_offset = 12;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 64;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 54000;
        break;
      case 44: /* 720(1440)x576i @ 100Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 45: /* 720(1440)x576i @ 100Hz 16:9 */
        info->video_info.h_active = 1440;
        info->video_info.v_active = 288;
        info->video_info.h_blanking = 288;
        info->video_info.v_blanking = 24;
        info->video_info.h_sync_offset = 24;
        info->video_info.v_sync_offset = 2;
        info->video_info.h_sync_pulse_width = 126;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 1;
        info->video_info.pixel_clock = 54000;
        break;
      case 46: /* 1920x1080i @ 119.88/120Hz 16:9 */
        info->video_info.h_active = 1920;
        info->video_info.v_active = 540;
        info->video_info.h_blanking = 288;
        info->video_info.v_blanking = 22;
        info->video_info.h_sync_offset = 88;
        info->video_info.v_sync_offset = 2;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 1;
        info->video_info.pixel_clock = 148500;
        break;
      case 71:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 47: /* 1280x720p @ 119.88/120Hz 16:9 */
        info->video_info.h_active = 1280;
        info->video_info.v_active = 720;
        info->video_info.h_blanking = 370;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 110;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 40;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 148500;
        break;
      case 48: /* 720x480p @ 119.88/120Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 49: /* 720x480p @ 119.88/120Hz 16:9 */
        info->video_info.h_active = 720;
        info->video_info.v_active = 480;
        info->video_info.h_blanking = 138;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 16;
        info->video_info.v_sync_offset = 9;
        info->video_info.h_sync_pulse_width = 62;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 54000;
        break;
      case 50: /* 720(1440)x480i @ 119.88/120Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 51: /* 720(1440)x480i @ 119.88/120Hz 16:9 */
        info->video_info.h_active = 1440;
        info->video_info.v_active = 240;
        info->video_info.h_blanking = 276;
        info->video_info.v_blanking = 22;
        info->video_info.h_sync_offset = 38;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 124;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 1;
        info->video_info.pixel_clock = 54000;
        break;
      case 52: /* 720X576p @ 200Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 53: /* 720X576p @ 200Hz 16:9 */
        info->video_info.h_active = 720;
        info->video_info.v_active = 576;
        info->video_info.h_blanking = 144;
        info->video_info.v_blanking = 49;
        info->video_info.h_sync_offset = 12;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 64;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 108000;
        break;
      case 54: /* 720(1440)x576i @ 200Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 55: /* 720(1440)x576i @ 200Hz 16:9 */
        info->video_info.h_active = 1440;
        info->video_info.v_active = 288;
        info->video_info.h_blanking = 288;
        info->video_info.v_blanking = 24;
        info->video_info.h_sync_offset = 24;
        info->video_info.v_sync_offset = 2;
        info->video_info.h_sync_pulse_width = 126;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 1;
        info->video_info.pixel_clock = 108000;
        break;
      case 56: /* 720x480p @ 239.76/240Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 57: /* 720x480p @ 239.76/240Hz 16:9 */
        info->video_info.h_active = 720;
        info->video_info.v_active = 480;
        info->video_info.h_blanking = 138;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 16;
        info->video_info.v_sync_offset = 9;
        info->video_info.h_sync_pulse_width = 62;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 108000;
        break;
      case 58: /* 720(1440)x480i @ 239.76/240Hz 4:3 */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 59: /* 720(1440)x480i @ 239.76/240Hz 16:9 */
        info->video_info.h_active = 1440;
        info->video_info.v_active = 240;
        info->video_info.h_blanking = 276;
        info->video_info.v_blanking = 22;
        info->video_info.h_sync_offset = 38;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 124;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 1;
        info->video_info.pixel_clock = 108000;
        break;
      case 65:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 60: /* 1280x720p @ 23.97/24Hz 16:9 */
        info->video_info.h_active = 1280;
        info->video_info.v_active = 720;
        info->video_info.h_blanking = 2020;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 1760;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 40;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 594000;
        break;
      case 66:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 61: /* 1280x720p @ 25Hz 16:9 */
        info->video_info.h_active = 1280;
        info->video_info.v_active = 720;
        info->video_info.h_blanking = 2680;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 2420;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 40;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 74250;
        break;
      case 67:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 62: /* 1280x720p @ 29.97/30Hz  16:9 */
        info->video_info.h_active = 1280;
        info->video_info.v_active = 720;
        info->video_info.h_blanking = 2020;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 1760;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 40;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 74250;
        break;
      case 78:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 63: /* 1920x1080p @ 119.88/120Hz 16:9 */
        info->video_info.h_active = 1920;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 280;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 88;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 297000;
        break;
      case 77:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 64: /* 1920x1080p @ 100Hz 16:9 */
        info->video_info.h_active = 1920;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 720;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 528;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 297000;
        break;
      case 79:
        info->video_info.h_active = 1680;
        info->video_info.v_active = 720;
        info->video_info.h_blanking = 1620;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 1360;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 40;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 594000;
        break;
      case 80:
        info->video_info.h_active = 1680;
        info->video_info.v_active = 720;
        info->video_info.h_blanking = 1488;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 1228;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 40;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 594000;
        break;
      case 81:
        info->video_info.h_active = 1680;
        info->video_info.v_active = 720;
        info->video_info.h_blanking = 960;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 700;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 40;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 594000;
        break;
      case 82:
        info->video_info.h_active = 1680;
        info->video_info.v_active = 720;
        info->video_info.h_blanking = 520;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 260;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 40;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 82500;
        break;
      case 83:
        info->video_info.h_active = 1680;
        info->video_info.v_active = 720;
        info->video_info.h_blanking = 520;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 260;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 40;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 99000;
        break;
      case 84:
        info->video_info.h_active = 1680;
        info->video_info.v_active = 720;
        info->video_info.h_blanking = 320;
        info->video_info.v_blanking = 105;
        info->video_info.h_sync_offset = 60;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 40;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 165000;
        break;
      case 85:
        info->video_info.h_active = 1680;
        info->video_info.v_active = 720;
        info->video_info.h_blanking = 320;
        info->video_info.v_blanking = 105;
        info->video_info.h_sync_offset = 60;
        info->video_info.v_sync_offset = 5;
        info->video_info.h_sync_pulse_width = 40;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 198000;
        break;
      case 86:
        info->video_info.h_active = 2560;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 1190;
        info->video_info.v_blanking = 20;
        info->video_info.h_sync_offset = 998;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 99000;
        break;
      case 87:
        info->video_info.h_active = 2560;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 640;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 448;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 90000;
        break;
      case 88:
        info->video_info.h_active = 2560;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 960;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 768;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 118800;
        break;
      case 89:
        info->video_info.h_active = 2560;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 740;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 548;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 185625;
        break;
      case 90:
        info->video_info.h_active = 2560;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 440;
        info->video_info.v_blanking = 20;
        info->video_info.h_sync_offset = 248;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 198000;
        break;
      case 91:
        info->video_info.h_active = 2560;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 410;
        info->video_info.v_blanking = 170;
        info->video_info.h_sync_offset = 218;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 371250;
        break;
      case 92:
        info->video_info.h_active = 2560;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 740;
        info->video_info.v_blanking = 170;
        info->video_info.h_sync_offset = 548;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 495000;
        break;
      case 101:
        info->video_info.h_active = 4096;
        info->video_info.v_active = 2160;
        info->video_info.h_blanking = 1184;
        info->video_info.v_blanking = 90;
        info->video_info.h_sync_offset = 968;
        info->video_info.v_sync_offset = 8;
        info->video_info.h_sync_pulse_width = 88;
        info->video_info.v_sync_pulse_width = 10;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 59400;
        break;
      case 100:
        info->video_info.h_active = 4096;
        info->video_info.v_active = 2160;
        info->video_info.h_blanking = 304;
        info->video_info.v_blanking = 90;
        info->video_info.h_sync_offset = 88;
        info->video_info.v_sync_offset = 8;
        info->video_info.h_sync_pulse_width = 88;
        info->video_info.v_sync_pulse_width = 10;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 297000;
        break;
      case 99:
        info->video_info.h_active = 4096;
        info->video_info.v_active = 2160;
        info->video_info.h_blanking = 1184;
        info->video_info.v_blanking = 90;
        info->video_info.h_sync_offset = 968;
        info->video_info.v_sync_offset = 8;
        info->video_info.h_sync_pulse_width = 88;
        info->video_info.v_sync_pulse_width = 10;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 297000;
        break;
      case 102:
        info->video_info.h_active = 4096;
        info->video_info.v_active = 2160;
        info->video_info.h_blanking = 304;
        info->video_info.v_blanking = 90;
        info->video_info.h_sync_offset = 88;
        info->video_info.v_sync_offset = 8;
        info->video_info.h_sync_pulse_width = 88;
        info->video_info.v_sync_pulse_width = 10;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 594000;
        break;
      case 103:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 93: /* 4k x 2k, 30Hz */
        info->video_info.h_active = 3840;
        info->video_info.v_active = 2160;
        info->video_info.h_blanking = 1660;
        info->video_info.v_blanking = 90;
        info->video_info.h_sync_offset = 1276;
        info->video_info.v_sync_offset = 8;
        info->video_info.h_sync_pulse_width = 88;
        info->video_info.v_sync_pulse_width = 10;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 297000;
        break;
      case 104:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 94:
        info->video_info.h_active = 3840;
        info->video_info.v_active = 2160;
        info->video_info.h_blanking = 1440;
        info->video_info.v_blanking = 90;
        info->video_info.h_sync_offset = 1056;
        info->video_info.v_sync_offset = 8;
        info->video_info.h_sync_pulse_width = 88;
        info->video_info.v_sync_pulse_width = 10;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 297000;
        break;
      case 105:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 95:
        info->video_info.h_active = 3840;
        info->video_info.v_active = 2160;
        info->video_info.h_blanking = 560;
        info->video_info.v_blanking = 90;
        info->video_info.h_sync_offset = 176;
        info->video_info.v_sync_offset = 8;
        info->video_info.h_sync_pulse_width = 88;
        info->video_info.v_sync_pulse_width = 10;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 297000;
        break;
      case 106:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 96:
        info->video_info.h_active = 3840;
        info->video_info.v_active = 2160;
        info->video_info.h_blanking = 1440;
        info->video_info.v_blanking = 90;
        info->video_info.h_sync_offset = 1056;
        info->video_info.v_sync_offset = 8;
        info->video_info.h_sync_pulse_width = 88;
        info->video_info.v_sync_pulse_width = 10;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 594000;
        break;
      case 107:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        fallthrough;
      case 97:
        info->video_info.h_active = 3840;
        info->video_info.v_active = 2160;
        info->video_info.h_blanking = 560;
        info->video_info.v_blanking = 90;
        info->video_info.h_sync_offset = 176;
        info->video_info.v_sync_offset = 8;
        info->video_info.h_sync_pulse_width = 88;
        info->video_info.v_sync_pulse_width = 10;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 594000;
        break;
      case 98:
        info->video_info.h_active = 4096;
        info->video_info.v_active = 2160;
        info->video_info.h_blanking = 1404;
        info->video_info.v_blanking = 90;
        info->video_info.h_sync_offset = 1020;
        info->video_info.v_sync_offset = 8;
        info->video_info.h_sync_pulse_width = 88;
        info->video_info.v_sync_pulse_width = 10;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0;
        info->video_info.pixel_clock = 297000;
        break;
      default:
        return -1;
    }
  } else if (info->display_protocol == CVT) {
    switch (info->video_timing_id) {
      case 1:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 640;
        info->video_info.v_active = 480;
        info->video_info.h_blanking = 160;
        info->video_info.v_blanking = 20;
        info->video_info.h_sync_offset = 8;
        info->video_info.v_sync_offset = 1;
        info->video_info.h_sync_pulse_width = 32;
        info->video_info.v_sync_pulse_width = 8;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 23750;
        break;
      case 2:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 800;
        info->video_info.v_active = 600;
        info->video_info.h_blanking = 224;
        info->video_info.v_blanking = 24;
        info->video_info.h_sync_offset = 31;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 81;
        info->video_info.v_sync_pulse_width = 4;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 38250;
        break;
      case 3:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1024;
        info->video_info.v_active = 768;
        info->video_info.h_blanking = 304;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 48;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 104;
        info->video_info.v_sync_pulse_width = 4;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 63500;
        break;
      case 4:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1280;
        info->video_info.v_active = 960;
        info->video_info.h_blanking = 416;
        info->video_info.v_blanking = 36;
        info->video_info.h_sync_offset = 80;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 128;
        info->video_info.v_sync_pulse_width = 4;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 101250;
        break;
      case 5:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1400;
        info->video_info.v_active = 1050;
        info->video_info.h_blanking = 464;
        info->video_info.v_blanking = 39;
        info->video_info.h_sync_offset = 88;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 144;
        info->video_info.v_sync_pulse_width = 4;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 121750;
        break;
      case 6:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1600;
        info->video_info.v_active = 1200;
        info->video_info.h_blanking = 560;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 112;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 68;
        info->video_info.v_sync_pulse_width = 4;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 161000;
        break;
      case 12:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1280;
        info->video_info.v_active = 1024;
        info->video_info.h_blanking = 432;
        info->video_info.v_blanking = 39;
        info->video_info.h_sync_offset = 80;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 136;
        info->video_info.v_sync_pulse_width = 7;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 109000;
        break;
      case 13:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1280;
        info->video_info.v_active = 768;
        info->video_info.h_blanking = 384;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 64;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 128;
        info->video_info.v_sync_pulse_width = 7;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 79500;
        break;
      case 16:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1280;
        info->video_info.v_active = 720;
        info->video_info.h_blanking = 384;
        info->video_info.v_blanking = 28;
        info->video_info.h_sync_offset = 64;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 128;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 74500;
        break;
      case 17:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1360;
        info->video_info.v_active = 768;
        info->video_info.h_blanking = 416;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 72;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 136;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 84750;
        break;
      case 20:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1920;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 656;
        info->video_info.v_blanking = 40;
        info->video_info.h_sync_offset = 128;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 200;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 173000;
        break;
      case 22:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 2560;
        info->video_info.v_active = 1440;
        info->video_info.h_blanking = 928;
        info->video_info.v_blanking = 53;
        info->video_info.h_sync_offset = 192;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 272;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 312250;
        break;
      case 28:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1280;
        info->video_info.v_active = 800;
        info->video_info.h_blanking = 400;
        info->video_info.v_blanking = 31;
        info->video_info.h_sync_offset = 72;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 128;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 83500;
        break;
      case 34:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1920;
        info->video_info.v_active = 1200;
        info->video_info.h_blanking = 672;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 136;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 200;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 193250;
        break;
      case 38:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 3840;
        info->video_info.v_active = 2400;
        info->video_info.h_blanking = 80;
        info->video_info.v_blanking = 69;
        info->video_info.h_sync_offset = 320;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 424;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 580128;
        break;
      case 40:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1600;
        info->video_info.v_active = 1200;
        info->video_info.h_blanking = 160;
        info->video_info.v_blanking = 35;
        info->video_info.h_sync_offset = 48;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 32;
        info->video_info.v_sync_pulse_width = 4;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 124076;
        break;
      case 41:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 2048;
        info->video_info.v_active = 1536;
        info->video_info.h_blanking = 160;
        info->video_info.v_blanking = 44;
        info->video_info.h_sync_offset = 48;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 32;
        info->video_info.v_sync_pulse_width = 4;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 208000;
        break;
      default:
        return -1;
    }
  } else if (info->display_protocol == DMT) {
    switch (info->video_timing_id) {
      case 1:  // HISilicon timing
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 3600;
        info->video_info.v_active = 1800;
        info->video_info.h_blanking = 120;
        info->video_info.v_blanking = 128;
        info->video_info.h_sync_offset = 20;
        info->video_info.v_sync_offset = 2;
        info->video_info.h_sync_pulse_width = 20;
        info->video_info.v_sync_pulse_width = 2;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 645500;
        break;
      case 2:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 3840;
        info->video_info.v_active = 2160;
        info->video_info.h_blanking = 160;
        info->video_info.v_blanking = 62;
        info->video_info.h_sync_offset = 48;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 32;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 533000;
        break;
      case 4:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 640;
        info->video_info.v_active = 480;
        info->video_info.h_blanking = 144;
        info->video_info.v_blanking = 29;
        info->video_info.h_sync_offset = 8;
        info->video_info.v_sync_offset = 2;
        info->video_info.h_sync_pulse_width = 96;
        info->video_info.v_sync_pulse_width = 2;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 25175;
        break;
      case 13:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 800;
        info->video_info.v_active = 600;
        info->video_info.h_blanking = 160;
        info->video_info.v_blanking = 36;
        info->video_info.h_sync_offset = 48;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 32;
        info->video_info.v_sync_pulse_width = 4;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 73250;
        break;
      case 14: /* 848x480p@60Hz */
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 848;
        info->video_info.v_active = 480;
        info->video_info.h_blanking = 240;
        info->video_info.v_blanking = 37;
        info->video_info.h_sync_offset = 16;
        info->video_info.v_sync_offset = 6;
        info->video_info.h_sync_pulse_width = 112;
        info->video_info.v_sync_pulse_width = 8;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI)  */
        ;
        info->video_info.pixel_clock = 33750;
        break;
      case 22:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1280;
        info->video_info.v_active = 768;
        info->video_info.h_blanking = 160;
        info->video_info.v_blanking = 22;
        info->video_info.h_sync_offset = 48;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 32;
        info->video_info.v_sync_pulse_width = 7;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 68250;
        break;
      case 35:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1280;
        info->video_info.v_active = 1024;
        info->video_info.h_blanking = 408;
        info->video_info.v_blanking = 42;
        info->video_info.h_sync_offset = 48;
        info->video_info.v_sync_offset = 1;
        info->video_info.h_sync_pulse_width = 112;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 108000;
        break;
      case 39:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1360;
        info->video_info.v_active = 768;
        info->video_info.h_blanking = 432;
        info->video_info.v_blanking = 27;
        info->video_info.h_sync_offset = 64;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 112;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 85500;
        break;
      case 40:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1360;
        info->video_info.v_active = 768;
        info->video_info.h_blanking = 160;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 48;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 32;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 148250;
        break;
      case 81:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1366;
        info->video_info.v_active = 768;
        info->video_info.h_blanking = 426;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 70;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 142;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 85500;
        break;
      case 86:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1366;
        info->video_info.v_active = 768;
        info->video_info.h_blanking = 134;
        info->video_info.v_blanking = 32;
        info->video_info.h_sync_offset = 14;
        info->video_info.v_sync_offset = 1;
        info->video_info.h_sync_pulse_width = 56;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 72000;
        break;
      case 87:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 4096;
        info->video_info.v_active = 2160;
        info->video_info.h_blanking = 80;
        info->video_info.v_blanking = 62;
        info->video_info.h_sync_offset = 8;
        info->video_info.v_sync_offset = 48;
        info->video_info.h_sync_pulse_width = 32;
        info->video_info.v_sync_pulse_width = 8;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 556744;
        break;
      case 88:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 4096;
        info->video_info.v_active = 2160;
        info->video_info.h_blanking = 80;
        info->video_info.v_blanking = 62;
        info->video_info.h_sync_offset = 8;
        info->video_info.v_sync_offset = 48;
        info->video_info.h_sync_pulse_width = 32;
        info->video_info.v_sync_pulse_width = 8;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 556188;
        break;
      case 41:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1400;
        info->video_info.v_active = 1050;
        info->video_info.h_blanking = 160;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 48;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 32;
        info->video_info.v_sync_pulse_width = 4;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 101000;
        break;
      case 42:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1400;
        info->video_info.v_active = 1050;
        info->video_info.h_blanking = 464;
        info->video_info.v_blanking = 39;
        info->video_info.h_sync_offset = 88;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 144;
        info->video_info.v_sync_pulse_width = 4;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 121750;
        break;
      case 46:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1440;
        info->video_info.v_active = 900;
        info->video_info.h_blanking = 160;
        info->video_info.v_blanking = 26;
        info->video_info.h_sync_offset = 48;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 32;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 88750;
        break;
      case 47:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1440;
        info->video_info.v_active = 900;
        info->video_info.h_blanking = 464;
        info->video_info.v_blanking = 34;
        info->video_info.h_sync_offset = 80;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 152;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 106500;
        break;
      case 51:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1600;
        info->video_info.v_active = 1200;
        info->video_info.h_blanking = 560;
        info->video_info.v_blanking = 50;
        info->video_info.h_sync_offset = 64;
        info->video_info.v_sync_offset = 1;
        info->video_info.h_sync_pulse_width = 192;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 162000;
        break;
      case 57:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1680;
        info->video_info.v_active = 1050;
        info->video_info.h_blanking = 160;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 48;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 32;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 119000;
        break;
      case 58:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1680;
        info->video_info.v_active = 1050;
        info->video_info.h_blanking = 560;
        info->video_info.v_blanking = 39;
        info->video_info.h_sync_offset = 104;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 176;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 146250;
        break;
      case 68:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1920;
        info->video_info.v_active = 1200;
        info->video_info.h_blanking = 160;
        info->video_info.v_blanking = 35;
        info->video_info.h_sync_offset = 48;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 32;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 154000;
        break;
      case 69:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1920;
        info->video_info.v_active = 1200;
        info->video_info.h_blanking = 672;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 136;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 200;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 193250;
        break;
      case 82:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1920;
        info->video_info.v_active = 1080;
        info->video_info.h_blanking = 280;
        info->video_info.v_blanking = 45;
        info->video_info.h_sync_offset = 88;
        info->video_info.v_sync_offset = 4;
        info->video_info.h_sync_pulse_width = 44;
        info->video_info.v_sync_pulse_width = 5;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 148500;
        break;
      case 83:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1600;
        info->video_info.v_active = 900;
        info->video_info.h_blanking = 200;
        info->video_info.v_blanking = 100;
        info->video_info.h_sync_offset = 24;
        info->video_info.v_sync_offset = 1;
        info->video_info.h_sync_pulse_width = 80;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 108000;
        break;
      case 9:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 800;
        info->video_info.v_active = 600;
        info->video_info.h_blanking = 256;
        info->video_info.v_blanking = 28;
        info->video_info.h_sync_offset = 40;
        info->video_info.v_sync_offset = 1;
        info->video_info.h_sync_pulse_width = 128;
        info->video_info.v_sync_pulse_width = 4;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 40000;
        break;
      case 16:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1024;
        info->video_info.v_active = 768;
        info->video_info.h_blanking = 320;
        info->video_info.v_blanking = 38;
        info->video_info.h_sync_offset = 24;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 136;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 65000;
        break;
      case 23:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1280;
        info->video_info.v_active = 768;
        info->video_info.h_blanking = 384;
        info->video_info.v_blanking = 30;
        info->video_info.h_sync_offset = 64;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 128;
        info->video_info.v_sync_pulse_width = 7;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 79500;
        break;
      case 62:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1792;
        info->video_info.v_active = 1344;
        info->video_info.h_blanking = 656;
        info->video_info.v_blanking = 50;
        info->video_info.h_sync_offset = 128;
        info->video_info.v_sync_offset = 1;
        info->video_info.h_sync_pulse_width = 200;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 204750;
        break;
      case 32:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1280;
        info->video_info.v_active = 960;
        info->video_info.h_blanking = 520;
        info->video_info.v_blanking = 40;
        info->video_info.h_sync_offset = 96;
        info->video_info.v_sync_offset = 1;
        info->video_info.h_sync_pulse_width = 112;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 108000;
        break;
      case 73:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1920;
        info->video_info.v_active = 1440;
        info->video_info.h_blanking = 680;
        info->video_info.v_blanking = 60;
        info->video_info.h_sync_offset = 128;
        info->video_info.v_sync_offset = 1;
        info->video_info.h_sync_pulse_width = 208;
        info->video_info.v_sync_pulse_width = 3;
        info->video_info.h_sync_polarity = 0;
        info->video_info.v_sync_polarity = 1;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 234000;
        break;
      case 27:
        info->video_info.h_image_size = 4;
        info->video_info.v_image_size = 3;
        info->video_info.h_active = 1280;
        info->video_info.v_active = 800;
        info->video_info.h_blanking = 160;
        info->video_info.v_blanking = 23;
        info->video_info.h_sync_offset = 48;
        info->video_info.v_sync_offset = 3;
        info->video_info.h_sync_pulse_width = 32;
        info->video_info.v_sync_pulse_width = 6;
        info->video_info.h_sync_polarity = 1;
        info->video_info.v_sync_polarity = 0;
        info->video_info.interlaced = 0; /* (progressive_nI) */
        info->video_info.pixel_clock = 71000;
        break;
      default:
        return -1;
    }
  }
  return 0;
}
