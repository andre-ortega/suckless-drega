#include <X11/XF86keysym.h>
/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 0;       /* gap pixel between windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *altbarcmd        = "$HOME/.config/polybar/bar.sh"; /* Alternate bar launch command */
static const int vertpad            = 0;       /* vertical padding of bar */
static const int sidepad            = 0;       /* horizontal padding of bar */
static const int user_bh            = 35;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
//static const char *fonts[]          = { "Lekton Nerd Font:style=Regular:size=12" };
//static const char dmenufont[]       = "Monofur Nerd Font Mono:style=Regular:size=12";
static const char *fonts[]          = { "JetBrainsMonoNL Nerd Font:size=11", "JoyPixels:pixelsize=11:antialias=true:autohint=true"};
static const char dmenufont[]       = "JetBrainsMonoNL Nerd Font:size=11";
static const char col_gray1[]       = "#9064e3";
static const char col_gray2[]       = "#c2a6f7";
static const char col_gray3[]       = "#c2a6f7";
static const char col_gray4[]       = "#9064e3";
static const char col_cyan[]        = "#9daafa";
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
/*static const char *colors[][3]      = {*/
	/*               fg         bg         border   */
/*	[SchemeNorm] = { col_gray3, col_gray1, col_gray1 },*/
/*	[SchemeSel]  = { col_gray4, col_gray2,  col_cyan  },*/
/*};*/

#include "/home/roe/git/suckless-drega/dwm/colors-wal-dwm.h"

static const unsigned int alphas[][3]      = {
    /*               fg      bg        border*/
    [SchemeNorm] = { OPAQUE, baralpha, 0x00U },
	  [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

static const char *const autostart[] = {
	"slstatus", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "󰣇", "󰈹", "", "", "", "", ""};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "󱞟",      tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL};
static const char *termcmd[]  = { "st", NULL };
static const char *firefoxcmd[]  = { "firefox", NULL };

/* Knob vol */
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute", "@DEFAULT_SINK@", "toggle", NULL };
static const char *upvol[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "+1%", NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "-1%", NULL };

#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */
  { 0,              XF86XK_AudioMute,        spawn,          {.v = mutevol } },
  { 0,              XF86XK_AudioRaiseVolume, spawn,          {.v = upvol } },
  { 0,              XF86XK_AudioLowerVolume, spawn,          {.v = downvol } },
//{ 0,                            XK_Super_L,spawn,          {.v = dmenucmd } },
  { MODKEY,                       XK_BackSpace,spawn,        {.v = dmenucmd } },
	{ MODKEY,                       XK_space,  spawn,          {.v = termcmd } },
  { MODKEY,                       XK_p,      spawn,          {.v = firefoxcmd } },
//{ MODKEY|ShiftMask,             XK_f,      spawn,          SHCMD("st -e ranger")},
  { MODKEY,                       XK_f,      zoom,           {0} },
//{ MODKEY|ShiftMask,             XK_F10,    spawn,          SHCMD("st -e cava")},
  { MODKEY|ShiftMask,             XK_BackSpace,      spawn,  SHCMD("shutdown now")},
//{ MODKEY|ShiftMask,             XK_F5,     spawn,          SHCMD(" st -e bashtop")},
	{ MODKEY,                       XK_b,      togglebar,      {0} },
//{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
//{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
  { MODKEY,                       XK_h,      focusstack,     {.i = -1 } },
  { MODKEY,                       XK_l,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_s,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_j,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_k,      setmfact,       {.f = +0.05} },
//  { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
//  { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
//{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
//{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
//{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
//{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
//{ MODKEY,                       XK_space,  setlayout,      {0} },
  { MODKEY,                       XK_w,      setlayout,      {.v = &layouts[0]} },
  { MODKEY,                       XK_e,      setlayout,      {.v = &layouts[1]} },
  { MODKEY,                       XK_r,      setlayout,      {.v = &layouts[2]} },
  { MODKEY,                       XK_Return, setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_f,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,             XK_y,      spawn,          SHCMD("flameshot gui") },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
  { MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
  { MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
  { MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};

