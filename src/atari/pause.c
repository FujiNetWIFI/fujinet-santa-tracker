/**
 * @brief   Santa Tracker
 * @verbose Pause function
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license GPL v. 3, see LICENSE for details.
 */

#include <atari.h>
#include "../pause.h"

/**
 * @brief wait for a bit, system-dependent.
 */
void pause(void)
{
    unsigned char c=0;

    // Clear jiffy clock.
    OS.rtclok[0]=OS.rtclok[1]=OS.rtclok[2]=0;

    // Wait and do a bit of color cycling.
    while (OS.rtclok[1]<60)
    {
        c++;
        OS.color1 = (c & 0xF0) + 0x0A;
        OS.pcolr0 = c++;
        waitvsync();
    };
}
