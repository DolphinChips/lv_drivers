/**
 * @file tslib.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "tslib.h"
#if USE_TSLIB != 0

#include <stdio.h>
#include <tslib.h>
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static struct tsdev *ts;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Initialize the tslib interface
 */
void tslib_init(void)
{
    ts = ts_setup(NULL, 0);
    if (!ts) {
        perror("Unable to setup touchscreen");
        return;
    }
}
/**
 * Get the current position and state of the tslib
 * @param data store the tslib data here
 * @return false: because the points are not buffered, so no more data to be read
 */
bool tslib_read(lv_indev_drv_t * drv, lv_indev_data_t * data)
{
    struct ts_sample samp;
    int ret;

    ret = ts_read(ts, &samp, 1);
    if (ret < 0) {
        perror("Error reading data from touchscreen");
        return false;
    }

    data->point.x = samp.x;
    data->point.y = samp.y;

    data->state = LV_INDEV_STATE_PR;

    if(data->point.x < 0)
      data->point.x = 0;
    if(data->point.y < 0)
      data->point.y = 0;
    if(data->point.x >= lv_disp_get_hor_res(drv->disp))
      data->point.x = lv_disp_get_hor_res(drv->disp) - 1;
    if(data->point.y >= lv_disp_get_ver_res(drv->disp))
      data->point.y = lv_disp_get_ver_res(drv->disp) - 1;

    return false;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif
