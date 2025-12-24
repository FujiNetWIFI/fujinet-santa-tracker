/**
 * @brief   Santa Tracker
 * @verbose Screen API
 * @author  Thomas Cherryhomes
 * @email   thom dot cherryhomes at gmail dot com
 * @license GPL v. 3, see LICENSE for details.
 */

#include <atari.h>
#include <ctype.h>
#include <string.h>
#include "../screen.h"
#include "map.h"
#include "charset.h"

/**
 * @brief Pointer to response screen display memory
 * @verbose UPPER and LOWER refer to ANTIC boundaries for display list
 */
#define SCREEN       0x8150
#define SCREEN_UPPER 0x8150
#define SCREEN_LOWER 0x9000
#define SCREEN_OSD   0x9C40
#define CHARSET      0x7C00

/**
 * @brief error message to display, 40 chars
 * @value "COULDN'T FETCH DATA   WAITING TO RETRY"
 */
const char msg_error[40] =
    {
        0x23,0x2F,0x35,0x2C,0x24,0x2E,0x07,0x34,0x00,0x26,0x25,0x34,0x23,0x28,0x00,0x24,0x21,0x34,0x21,0x00,
        0x00,0x00,0x77,0x61,0x69,0x74,0x69,0x6E,0x67,0x00,0x74,0x6F,0x00,0x72,0x65,0x74,0x72,0x79,0x00,0x00
    };

const char msg_title[20] = "google\x00santa\x00tracker";

// UTILITY FUNCTIONS ///////////////////////////////////////////////////

/**
 * @brief Put character at position pointed to by p
 * @param p pointer into screen RAM
 * @param c Character to output (0x00-0x3F)
 * @param color Color to output (0-3)
 */
void screen_putc(unsigned char *p, char c, unsigned char color)
{
    // Convert character to uppercase screencode and apply color
    c = toupper(c);
    c -= 0x20;
    c <<= color;

    // Plot to screen.
    *p = c;
}

/**
 * @brief Put string at position pointed to by p
 * @param p pointer into screen ram
 * @param x column (0-19)
 * @param y row (0-3)
 * @param s pointer to null terminated string
 * @param color Color to output (0-3)
 */
void screen_puts(unsigned char *p,
                 char *s,
                 unsigned char x,
                 unsigned char y,
                 unsigned char color)
{
    char c=0;

    p += (y*20) + x;

    while (c = *s++)
    {
        screen_putc(p++,c,color);
    }
}

// ERROR SCREEN ////////////////////////////////////////////////////////

/**
 * @brief Display list for error page
 */
static void dlist_error =
    {
        DL_BLK8,
        DL_BLK8,
        DL_BLK8,
        DL_BLK8,
        DL_BLK8,
        DL_BLK8,
        DL_BLK8,
        DL_BLK8,
        DL_BLK8,
        DL_BLK8,                 // Vertically Center
        DL_LMS(DL_CHR20x16x2),   // First Line
        &msg_error,
        DL_BLK3,                 // 3 Pixel margin
        DL_CHR20x16x2,           // Second line
        DL_JVB,
        &dlist_error
    };

/**
 * @brief Show error screen
 */
void screen_error(void)
{
    OS.sdlst = &dlist_error;
    OS.color4 = 0x44; // Red
    OS.color0 = 0xB8; // Festive Green
    OS.color1 = 0xFF; // Gold
}

static void dlist_screen =
    {
        DL_BLK8,
        DL_BLK8,
        DL_BLK8,
        DL_LMS(DL_CHR20x8x2),
        msg_title,
        DL_BLK3,
        DL_LMS(DL_MAP160x1x4), // 93 lines
        SCREEN_UPPER,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
     DL_LMS(DL_MAP160x1x4), // 97 lines
        SCREEN_LOWER,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,
        DL_MAP160x1x4,

        DL_LMS(DL_CHR20x8x2),
        SCREEN_OSD,
        DL_CHR20x8x2,
        DL_CHR20x8x2,

        DL_JVB,
        &dlist_screen
    };

/**
 * @brief show screen
 * @param response Pointer to Response struct
 */
void screen(Response *response)
{
    OS.sdlst = &dlist_screen;
    OS.color1 = 0xFF;
    OS.color4 = 0x42; // Red
    OS.color2 = 0xBC; // Festive green

    memcpy((unsigned char *)CHARSET,charset,sizeof(charset));
    memcpy((unsigned char *)SCREEN,map,sizeof(map));

    OS.chbas = 0x7C;
}
