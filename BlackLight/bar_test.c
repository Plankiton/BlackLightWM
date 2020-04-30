#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "bar.h"

enum { CurNormal, CurResize, CurMove, CurLast }; /* cursor */
enum { SchemeNorm, SchemeSel }; /* color schemes */
enum { NetSupported, NetWMName, NetWMState, NetWMCheck,
    NetWMFullscreen, NetActiveWindow, NetWMWindowType,
    NetWMWindowTypeDialog, NetClientList, NetLast }; /* EWMH atoms */
enum { WMProtocols, WMDelete, WMState, WMTakeFocus, WMLast }; /* default atoms */
enum { ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
    ClkClientWin, ClkRootWin, ClkLast }; /* clicks */

/* variables */
static int screen;
static int sw, sh;           /* X display screen geometry width, height */
static int bh, blw = 0;      /* bar geometry */
static int textpadding;            /* sum of left and right padding for text */
static int (*xerrorxlib)(Display *, XErrorEvent *);
static unsigned int numlockmask = 0;
static Atom wmatom[WMLast], netatom[NetLast];
static int running = 1;
static Cur *cursor[CurLast];
static Clr **scheme;
static Display *dpy;
static Drw *drw;
static Window root;

int main (int argc, char ** argv){
    Item *items;
    XSetWindowAttributes wa;
    XClassHint ch = { "bar", "bar" };
    char stext[255] = "Joao";

    int bx = 0, by = 0, bw = 1000, bh = 30;
    Window barwin = XCreateWindow(dpy, root, bx, by, bw, bh, 0, DefaultDepth(dpy, screen),
            CopyFromParent, DefaultVisual(dpy, screen),
            CWOverrideRedirect|CWBackPixmap|CWEventMask, &wa);
    XDefineCursor(dpy, barwin, cursor[CurNormal]->cursor);
    XMapRaised(dpy, barwin);
    XSetClassHint(dpy, barwin, &ch);


    {
        int x, w, sw = 0;
        int boxs = drw->fonts->h / 9;
        int boxw = drw->fonts->h / 6 + 2;
        unsigned int i, occ = 0, urg = 0;

        /* draw status first so it can be overdrawn by tags later */
        drw_setscheme(drw, scheme[SchemeNorm]);
        sw = strlen(stext) - textpadding + 2; /* 2px right padding */
        drw_text(drw, bw - sw, 0, sw, bh, 0, stext, 0);

        drw_map(drw, barwin, 0, 0, bw, bh);

        /*
        for (i = 0; i < LENGTH(tags); i++) {
            w = strlen(tags[i]);
            drw_setscheme(drw, scheme[m->tagset[m->seltags] & 1 << i ? SchemeSel : SchemeNorm]);
            drw_text(drw, x, 0, w, bh, textpadding / 2, tags[i], urg & 1 << i);
            if (occ & 1 << i)
                drw_rect(drw, x + boxs, boxs, boxw, boxw,
                        m == selmon && selmon->sel && selmon->sel->tags & 1 << i,
                        urg & 1 << i);
            x += w;
        }

        w = blw = TEXTW(m->ltsymbol);
        drw_setscheme(drw, scheme[SchemeNorm]);
        x = drw_text(drw, x, 0, w, bh, textpadding / 2, m->ltsymbol, 0);

        if ((w = m->ww - sw - x) > bh) {
            if (m->sel) {
                drw_setscheme(drw, scheme[m == selmon ? SchemeSel : SchemeNorm]);
                drw_text(drw, x, 0, w, bh, textpadding / 2, m->sel->name, 0);
                if (m->sel->isfloating)
                    drw_rect(drw, x + boxs, boxs, boxw, boxw, m->sel->isfixed, 0);
            } else {
                drw_setscheme(drw, scheme[SchemeNorm]);
                drw_rect(drw, x, 0, w, bh, 1, 1);
            }
        }

        drw_map(drw, barwin, 0, 0, bw, bh);
        */
    }

return 0;
}
