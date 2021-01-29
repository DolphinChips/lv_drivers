/**
 * @file evdev.h
 *
 */

#ifndef TSLIB_H
#define TSLIB_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#ifndef LV_DRV_NO_CONF
#ifdef LV_CONF_INCLUDE_SIMPLE
#include "lv_drv_conf.h"
#else
#include "../../lv_drv_conf.h"
#endif
#endif

#if USE_TSLIB

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the tslib
 */
void tslib_init(void);
/**
 * Get the current position and state of the tslib
 * @param data store the tslib data here
 * @return false: because the points are not buffered, so no more data to be read
 */
bool tslib_read(lv_indev_drv_t * drv, lv_indev_data_t * data);


/**********************
 *      MACROS
 **********************/

#endif /* USE_TSLIB */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* TSLIB_H */
