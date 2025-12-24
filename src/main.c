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

Response response;

/**
 * @brief entrypoint
 */
void main(void)
{
    screen(&response);

    while(1);
    while(1)
    {
        if (fetch(&response) != FN_ERR_OK)
            screen_error();
        else
            screen(&response);

        pause();
    }
}
