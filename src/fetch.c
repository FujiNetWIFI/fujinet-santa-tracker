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
uint8_t fetch(Response *response)
{
    char nowStr[16];
    char takeoffStr[16];
    char durationStr[16];
    char latLonStr[32];
    char *latp = NULL;
    char *lonp = NULL;
    uint8_t err = 0;

    memset(response,0,sizeof(Response));
    memset(nowStr,0,sizeof(nowStr));
    memset(takeoffStr,0,sizeof(takeoffStr));
    memset(durationStr,0,sizeof(durationStr));
    memset(latLonStr,0,sizeof(latLonStr));

    network_init();

    err = network_open(url,OPEN_MODE_HTTP_GET,OPEN_TRANS_LF);
    if (err != FN_ERR_OK)
        goto bye;

    err = network_json_parse(url);
    if (err != FN_ERR_OK)
        goto bye;

    err = network_json_query(url,query_now,nowStr);
    if (err != FN_ERR_OK)
        goto bye;

    err = network_json_query(url,query_takeoff,takeoffStr);
    if (err != FN_ERR_OK)
        goto bye;

    err = network_json_query(url,query_duration,durationStr);
    if (err != FN_ERR_OK)
        goto bye;

    err = network_json_query(url,query_latlon,latLonStr);
    if (err != FN_ERR_OK)
        goto bye;

    latp = strtok(latLonStr,",");
    lonp = strtok(NULL,"\n");

    response->now = atol(nowStr);
    response->takeoff = atol(takeoffStr);
    response->duration = atol(durationStr);
    response->lat = atoi(latp);
    response->lon = atoi(lonp);

bye:
    network_close(url);

    return err;
}
