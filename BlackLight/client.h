#ifndef __Xlib__
#include <X11/Xlib.h>
#define __Xlib__
#endif
#include <X11/Xutil.h>

#include <limits.h>
#include "maskflags.h"

typedef struct Monitor Monitor;
typedef struct Client Client;
struct Client {
    char name[256];
    float mina, maxa;
    int x, y, w, h;
    int oldx, oldy, oldw, oldh;
    int basew, baseh, incw, inch, maxw, maxh, minw, minh;
    int bw, oldbw;
    unsigned int tags;
    int isfixed, isfloating, isurgent, neverfocus, oldstate, isfullscreen;
    Client *next;
    Client *snext;
    Monitor *mon;
    Window win;
};

typedef struct {
    const char *symbol;
    void (*arrange)(Monitor *);
} Layout;

struct Monitor {
    char ltsymbol[16];
    float mfact;
    int nmaster;
    int num;
    int by;               /* bar geometry */
    int mx, my, mw, mh;   /* screen size */
    int wx, wy, ww, wh;   /* window area  */
    unsigned int seltags;
    unsigned int sellt;
    unsigned int tagset[2];
    int showbar;
    int topbar;
    Client *clients;
    Client *sel;
    Client *stack;
    Monitor *next;
    Window barwin;
    const Layout *lt[2];
};

typedef struct {
    const char *class;
    const char *instance;
    const char *title;
    unsigned int tags;
    int isfloating;
    int monitor;
} Rule;

typedef int TagMask;

void attach_client(Client *);
void attach_stack_client(Client *);
void detach_client(Client *);
void detach_stack_client(Client *);

void configure_client(Display *, Client *);
void apply_client_rules(Display *, Client *, Rule *, Monitor *, TagMask);
int apply_client_size_hints(Display *, Client *, int *x, int *y, int *w, int *h, int interact, int sw, int sh, int bh, int resizehints);
void resize_client(Display *, Client *, int *x, int *y, int *w, int *h, int interact, int sw, int sh, int bh, int resizehints);
void arrange_monitors(Display *, Monitor * monitor, Monitor * list_monitors);
void arrange_monitor(Monitor *);
void restack_monitor(Display *, Monitor *);
void show_hide_client(Display *, Client *);

#define broken "broken"
