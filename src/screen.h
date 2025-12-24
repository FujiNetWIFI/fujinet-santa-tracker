/**
 * @brief   Santa Tracker
 * @verbose Screen API
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license GPL v. 3, see LICENSE for details.
 */

#ifndef SCREEN_H
#define SCREEN_H

#include "response.h"

/**
 * @brief Show error screen
 */
void screen_error(void);

/**
 * @brief show screen
 * @param response Pointer to Response struct
 */
void screen(Response *response);

#endif /* SCREEN_H */
