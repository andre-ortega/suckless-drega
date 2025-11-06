/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 0;                      /* -b  option; if 0, dmenu appears at bottom     */
static const unsigned int alpha = 0xFF;     /* Amount of opacity. 0xff is opaque             */
static int centered = 1;                    /* -c option; centers dmenu on screen */
static int min_width = 600;                    /* minimum width when centered */
static const float menu_height_ratio = 2.0f;  /* This is the ratio used in the original calculation */
static const int user_bh = 5;               /* add an defined amount of pixels to the bar height */

static const char *fonts[] = {
	"JetBrainsMonoNL Nerd Font:size=12",
	"JoyPixels:pixelsize=12:antialias=true:autohint=true"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */

#include "/home/roe/git/suckless-drega/dmenu/colors-wal-dmenu.h"

static const unsigned int alphas[SchemeLast][2] = {
	[SchemeNorm] = { OPAQUE, alpha },
	[SchemeSel] = { OPAQUE, alpha },
	[SchemeOut] = { OPAQUE, alpha },
};
static unsigned int lines = 10;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 4;
