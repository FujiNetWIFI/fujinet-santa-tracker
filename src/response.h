#ifndef RESPONSE_H
#define RESPONSE_H

/**
 * @brief Response data type
 */
typedef struct _response
{
    unsigned long now;        /* Current time */
    unsigned long takeoff;    /* Sleigh takeoff time */
    unsigned long duration;   /* Duration of trip */
    int lat;                  /* Latitude */
    int lon;                  /* Longitude */
} Response;

#endif
