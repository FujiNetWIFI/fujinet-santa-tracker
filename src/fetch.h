/**
 * @brief   Santa Tracker
 * @verbose Fetch data from tracker API
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license GPL v. 3, see LICENSE for details.
 */

#ifndef FETCH_H
#define FETCH_H

#include <stdint.h>
#include "response.h"

/**
 * @brief Fetch data, feed back into response.
 * @param Response pointer to response struct
 */
uint8_t fetch(Response *response);

#endif /* FETCH_H */
