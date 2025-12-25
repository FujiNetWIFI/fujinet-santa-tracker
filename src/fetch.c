/**
 * @brief   Santa Tracker
 * @verbose Fetch data from tracker API
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license GPL v. 3, see LICENSE for details.
 */

#include <fujinet-network.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "response.h"

/**
 * @brief URL for santa tracker
 */
const char *url = "N:https://santa-api.appspot.com/info?client=web&language=en&fingerprint=&routeOffset=0&streamOffset=0";

/**
 * @brief Query URLs
 */
const char *query_now = "/now";
const char *query_takeoff = "/takeoff";
const char *query_duration = "/duration";
const char *query_latlon = "/location";

/**
 * @brief Fetch data, feed back into response.
 * @param Response pointer to response struct
 */
uint8_t fetch(int *lat, int *lon)
{
    char latLonStr[32];
    char *latp = NULL;
    char *lonp = NULL;
    uint8_t err = 0;

    memset(latLonStr,0,sizeof(latLonStr));

    network_init();

    err = network_open(url,OPEN_MODE_HTTP_GET,OPEN_TRANS_LF);

    err = network_json_parse(url);

    err = network_json_query(url,query_latlon,latLonStr);

    latp = strtok(latLonStr,",");
    lonp = strtok(NULL,"\n");

    *lat = atoi(latp);
    *lon = atoi(lonp);

bye:
    network_close(url);

    return FN_ERR_OK;
}
