/**
 * @brief   Santa Tracker
 * @verbose Main program
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license GPL v. 3, see LICENSE for details.
 */

#include <fujinet-network.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "screen.h"
#include "pause.h"
#include "fetch.h"

int lat=0;
int lon=0;

/**
 * @brief entrypoint
 */
void main(void)
{
    while(1)
    {
        if (fetch(&lat,&lon) != FN_ERR_OK)
            screen_error();
        else
            screen(lat,lon);

        pause();
    }
}
