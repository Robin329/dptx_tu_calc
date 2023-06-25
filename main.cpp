#include <errno.h>
#include <getopt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <cstring>
#include <iostream>

#include "video.h"

static int g_multipixel = DPTX_MP_SINGLE_PIXEL;
static int g_display_protocol = VCEA;
static int g_refresh_rate = 60000;
static bool g_verbose = false;

#define LOG(fmt...)             \
  ({                            \
    if (g_verbose) printf(fmt); \
  })

int dptx_ts_calculate(struct video_timing *timing, int lane_num, int rate,
                      int bpc, int encoding, int pixel_clock) {
  uint8_t init_threshold;
  int link_rate;
  int link_clk;
  int retval = 0;
  int ts;
  int T1;
  int T2;
  int tu;
  int tu_frac;
  int color_dep;

  switch (rate) {
    case DPTX_PHYIF_CTRL_RATE_RBR:
      link_rate = 162;
      link_clk = 40500;
      break;
    case DPTX_PHYIF_CTRL_RATE_HBR:
      link_rate = 270;
      link_clk = 67500;
      break;
    case DPTX_PHYIF_CTRL_RATE_HBR2:
      link_rate = 540;
      link_clk = 135000;
      break;
    case DPTX_PHYIF_CTRL_RATE_HBR3:
      link_rate = 810;
      link_clk = 202500;
      break;
    default: /* sahakyan */
      link_rate = 162;
      link_clk = 40500;
  }

  switch (bpc) {
    case COLOR_DEPTH_6:
      color_dep = 18;
      break;
    case COLOR_DEPTH_8:
      if (encoding == YCBCR420)
        color_dep = 12;
      else if (encoding == YCBCR422)
        color_dep = 16;
      else if (encoding == YONLY)
        color_dep = 8;
      else
        color_dep = 24;
      break;
    case COLOR_DEPTH_10:
      if (encoding == YCBCR420)
        color_dep = 15;
      else if (encoding == YCBCR422)
        color_dep = 20;
      else if (encoding == YONLY)
        color_dep = 10;
      else
        color_dep = 30;
      break;

    case COLOR_DEPTH_12:
      if (encoding == YCBCR420)
        color_dep = 18;
      else if (encoding == YCBCR422)
        color_dep = 24;
      else if (encoding == YONLY)
        color_dep = 12;
      else
        color_dep = 36;
      break;

    case COLOR_DEPTH_16:
      if (encoding == YCBCR420)
        color_dep = 24;
      else if (encoding == YCBCR422)
        color_dep = 32;
      else if (encoding == YONLY)
        color_dep = 16;
      else
        color_dep = 48;
      break;
    default:
      color_dep = 18;
      break;
  }

  ts = (8 * color_dep * pixel_clock) / (lane_num * link_rate);

  tu = ts / 1000;
  if (tu >= 65) {
    printf("%s: tu(%d) > 65\n", __func__, tu);
    return -EINVAL;
  }

  tu_frac = ts / 100 - tu * 10;

  /* Calculate init_threshold for non DSC mode */
  T1 = 0;
  T2 = 0;
  /* Single Pixel Mode */
  if (g_multipixel == DPTX_MP_SINGLE_PIXEL) {
    if (tu < 16)
      init_threshold = 32;
    else if (timing->video_info.h_blanking <= 40 && encoding >= YCBCR420 &&
             encoding <= YCBCR444)
      init_threshold = 3;
    else if (timing->video_info.h_blanking <= 80 && encoding >= YCBCR420 &&
             encoding <= YCBCR444)
      init_threshold = 12;
    else
      init_threshold = 16;
    /* Multiple Pixel Mode */
  } else {
    switch (bpc) {
      case COLOR_DEPTH_6:
        T1 = (4 * 1000 / 9) * lane_num;
        break;
      case COLOR_DEPTH_8:
        if (encoding == YCBCR422)
          T1 = (1000 / 2) * lane_num;
        else if (encoding == YONLY)
          T1 = lane_num * 1000;
        else if (g_multipixel == DPTX_MP_DUAL_PIXEL)
          T1 = (1000 / 3) * lane_num;
        else
          T1 = (3000 / 16) * lane_num;
        break;
      case COLOR_DEPTH_10:
        if (encoding == YCBCR422)
          T1 = (2000 / 5) * lane_num;
        else if (encoding == YONLY)
          T1 = (4000 / 5) * lane_num;
        else
          T1 = (4000 / 15) * lane_num;
        break;
      case COLOR_DEPTH_12:
        if (encoding == YCBCR422) /* Nothing happens here */
          if (g_multipixel == DPTX_MP_DUAL_PIXEL)
            T1 = (1000 / 6) * lane_num;
          else
            T1 = (1000 / 3) * lane_num;
        else if (encoding == YONLY)
          T1 = (2000 / 3) * lane_num;
        else
          T1 = (2000 / 9) * lane_num;
        break;
      case COLOR_DEPTH_16:
        if (encoding == YONLY) T1 = (1000 / 2) * lane_num;
        if ((encoding != YONLY) && (encoding != YCBCR422) &&
            (g_multipixel == DPTX_MP_DUAL_PIXEL))
          T1 = (1000 / 6) * lane_num;
        else
          T1 = (1000 / 4) * lane_num;
        break;
      default:
        printf("Invalid param BPC = %d\n", bpc);
        return -EINVAL;
    }

    if (encoding == YCBCR420) pixel_clock = pixel_clock / 2;

    T2 = (link_clk * 1000 / pixel_clock);

    init_threshold = T1 * T2 * tu / (1000 * 1000);
  }

  printf("T1 = %d, T2 = %d\n", T1, T2);
  printf("=================================\n");
  printf("tu = %d, tu_frac = %d, init_threshold = %d\n", tu, tu_frac,
         init_threshold);
  printf("=================================\n");
  return 0;
}

static struct option long_options[] = {
    {"protocol", optional_argument, NULL, 'p'},
    {"timing", required_argument, NULL, 't'},
    {"refresh", optional_argument, NULL, 'f'},
    {"lane", required_argument, NULL, 'l'},
    {"rate", optional_argument, NULL, 'r'},
    {"bpc", required_argument, NULL, 'b'},
    {"multi", optional_argument, NULL, 'm'},
    {"verbose", no_argument, NULL, 'v'},
    {"help", no_argument, NULL, 'h'},
    {NULL, 0, NULL, 0}  // 结束标记
};
static const char *shortopts = "p:t:l:r:f:b:m:vh";

void print_help(const char *name) {
  printf("\n");
  printf("\tUsage:\t");
  printf("\t  %s [opt] ...\n", name);
  printf("\t     -t, --timing  : 'VCEA','DMT','USER' timing id\n");
  printf(
      "\t     -p, --protocol  :  '0:VCEA','1:CVT','2:DMT','3:USER'display "
      "protocol\n");
  printf("\t     -f, --refresh   : timing refresh rate\n");
  printf("\t     -l, --lane      : lane num  - 1/2/3/4 lane\n");
  printf("\t     -r, --rate      : lane rate - 0:RBR,1:HBR,2:HBR2,3:HBR3\n");
  printf("\t     -b, --bpc     : bit per color, 6/8/10/12/16\n");
  printf(
      "\t     -e, --encoding: color encode format. "
      "0:RGB,1:YUV420,2:YUV422,3:YUV444,4:YONLY\n");
  printf("\t     -m, --multi   : multi pixel, 0:single 1:dual 2:quad");
  printf("\t     -v, --verbose : more debug log\n");
  printf("\t     -h, --help    : print help info\n");
}

int main(int argc, char **argv) {
  struct video_timing timing;
  int opt;
  int ret;
  int option_index = 0;
  int lane = 1, rate = DPTX_PHYIF_CTRL_RATE_RBR, bpc = COLOR_DEPTH_8,
      encoding = RGB;

  int requir_param = 0;

  memset(&timing, 0, sizeof(video_timing));
  while ((opt = getopt_long(argc, argv, shortopts, long_options,
                            &option_index)) != -1) {
    switch (opt) {
      case 'h':
        print_help(argv[0]);
        break;
      case 't':
        timing.video_timing_id = atoi(optarg);
        LOG("video_timing_id = %d", timing.video_timing_id);
        break;
      case 'p':
        timing.display_protocol = atoi(optarg);
        LOG("display_protocol = %d", timing.display_protocol);
        break;
      case 'f':
        g_refresh_rate = atoi(optarg);
        break;
      case 'l':
        lane = atoi(optarg);
        break;
      case 'b':
        bpc = atoi(optarg);
      case 'r':
        rate = atoi(optarg);
        break;
      case 'e':
        encoding = atoi(optarg);
        break;
      case 'm':
        g_multipixel = atoi(optarg);
        break;
      case 'v':
        g_verbose = true;
        break;
      case '?':
      default:
        break;
    }
  }
  for (int i = 0; i < sizeof(long_options) / sizeof(struct option); ++i) {
    if (long_options[i].has_arg == required_argument) {
      printf("You need input : %c\n", long_options[i].val);
      requir_param++;
    }
  }
  if (argc < requir_param) {
    printf("Error, please input right's parameters!\n");
    print_help(argv[0]);
    return -1;
  }

  LOG("refresh rate:%d\n", g_refresh_rate);
  LOG("        lane:%d\n", lane);
  LOG("         bpc:%d\n", bpc);
  LOG("        rate:%d\n", rate);
  LOG("    encoding:%d\n", encoding);
  LOG("  multipixel:%d\n", g_multipixel);
  LOG("     verbose:%d\n", g_verbose);
  LOG("   timing id:%d\n", timing.video_timing_id);
  ret = get_video_timing(&timing, g_refresh_rate);
  if (ret < 0) {
    printf("get video timing ERROR!\n");
    return -1;
  }

  LOG("         pixel_clock:%d\n", timing.video_info.pixel_clock);
  LOG("          interlaced:%d\n", timing.video_info.interlaced);
  LOG("            h_active:%d\n", timing.video_info.h_active);
  LOG("          h_blanking:%d\n", timing.video_info.h_blanking);
  LOG("        h_image_size:%d\n", timing.video_info.h_image_size);
  LOG("       h_sync_offset:%d\n", timing.video_info.h_sync_offset);
  LOG("  h_sync_pulse_width:%d\n", timing.video_info.h_sync_pulse_width);
  LOG("     h_sync_polarity:%d\n", timing.video_info.h_sync_polarity);
  LOG("            v_active:%d\n", timing.video_info.v_active);
  LOG("        v_image_size:%d\n", timing.video_info.v_image_size);
  LOG("       v_sync_offset:%d\n", timing.video_info.v_sync_offset);
  LOG("  v_sync_pulse_width:%d\n", timing.video_info.v_sync_pulse_width);
  LOG("     v_sync_polarity:%d\n", timing.video_info.v_sync_polarity);

  ret = dptx_ts_calculate(&timing, lane, rate, bpc, encoding,
                          timing.video_info.pixel_clock);

  if (ret < 0) {
    printf("dptx tu calc FAILED!\n");
    return -1;
  }
  return 0;
}