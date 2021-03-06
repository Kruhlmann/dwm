/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char statussep         = ';';      /* separator between status bars */
static const char *fonts[]          = { "FiraCode Nerd Font:size=14" };
static const char dmenufont[]       = "FiraCode Nerd Font:size=14";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "爵 Web", " Vim", "ﭮ Discord", " Teams", " Bitwarden", " Docs", " Games", ": Steam", " Settings" };
static const char *tagsalt[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class            instance    title       tags mask     isfloating, noswallow monitor */

    /* class */
	{ "Gimp",           NULL,       NULL,       0,            1,          0,        -1 },
	{ "(?i)virtualbox", NULL,       NULL,       0,            1,          0,        -1 },
	{ "Caprine",        NULL,       NULL,       0,            1,          0,        -1 },
	{ "stacer",         NULL,       NULL,       0,            1,          0,        -1 },
    { "blueberry.py",   NULL,       NULL,       0,            1,          0,        -1 },

    /* instance */
	{ NULL,     "floatme",      NULL,           0,            1,          0,        -1 },

    /* title */
	{ NULL,             NULL,      "alsamixer",                       0,    1,   0, -1 },
	{ NULL,             NULL,      "Microsoft Teams Notification",    0,    1,   0, -1 },

    /* tags */
	{ "discord",        NULL,       NULL,       3,            0,           0,       -1 },
	{ "Mainwindow.py",  NULL,       NULL,       4,            0,           0,       -1 },
	{ "TeamViewer",     NULL,       NULL,       9,            0,           0,       -1 },
	{ "ProtonMail Bridge",NULL,     NULL,       9,            0,           0,       -1 },
	{ "ckb-next",       NULL,       NULL,       9,            0,           0,       -1 },

    /* swallow */
	{ "termite",       NULL,        NULL,       9,            0,           1,       -1 },
	{ "kitty",         NULL,        NULL,       9,            0,           1,       -1 },
	{ "st",            NULL,        NULL,       9,            0,           1,       -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
 	{ "[@]",      spiral },/* first entry is default */
	{ "[]=",      tile },    
	{ "[M]",      monocle },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
 	{ "[\\]",     dwindle },
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
/* #define MODKEY Mod1Mask */
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
static const char *termcmd[]  = { "termite", NULL };
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
    /* spawn */
	{ MODKEY,                       XK_d,      spawn,          SHCMD("rofi -modi drun -show drun") },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,			            XK_w,	   spawn,		   SHCMD("qutebrowser") },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
    { MODKEY|ShiftMask,	            XK_x,      spawn,		   SHCMD("betterlockscreen -l") },
    { MODKEY,	                    XK_x,      spawn,		   SHCMD("rofi -show ssh") },
    { MODKEY|ShiftMask,	            XK_s,      spawn,		   SHCMD("maim -sl -u -c 0.2,0.4,1.0,0.7 -b 0 | xclip -selection clipboard -t image/png") },
    { MODKEY,	                    XK_u,      spawn,		   SHCMD("termite --name floatme -e fzmp") },
    { MODKEY,	                    XK_g,      spawn,		   SHCMD("termite --name floatme -e lazygit") },
    { MODKEY,	                    XK_e,      spawn,		   SHCMD("termite --name floatme -e ranger") },
    { MODKEY,	                    XK_n,      spawn,		   SHCMD("termite --name floatme -e ncmpcpp") },
    { MODKEY,	                    XK_m,      spawn,		   SHCMD("termite --name floatme -e neomutt") },
    { MODKEY,	                    XK_a,      spawn,		   SHCMD("termite --name floatme -e calcurse") },
    { MODKEY|ShiftMask,	            XK_v,      spawn,		   SHCMD("$HOME/.scripts/cbp") },
    { MODKEY,	                    XK_period, spawn,		   SHCMD("mpc next") },
    { MODKEY,	                    XK_comma,  spawn,		   SHCMD("mpc prev") },
    { MODKEY,	                    XK_space,  spawn,		   SHCMD("mpc toggle") },

    /* window manipulation */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_o,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_f,      togglefullscr,  {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },

    /* layouts */
	/* { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, */
	/* { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} }, */
	/* { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} }, */
	/* { MODKEY,                       XK_space,  setlayout,      {0} }, */

    /* { MODKEY,                       XK_b,      togglebar,      {0} }, */
	/* { MODKEY,                       XK_Return, zoom,           {0} }, */
	/* { MODKEY,                       XK_Tab,    view,           {0} }, */
	/* { MODKEY,                       XK_0,      view,           {.ui = ~0 } }, */
	/* { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, */
	/* { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } }, */
	/* { MODKEY,                       XK_period, focusmon,       {.i = +1 } }, */
	/* { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } }, */
	/* { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } }, */

    /* tags */

	{ MODKEY,                       XK_b,      togglealttag,   {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {.v = &layouts[0]} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[1]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

