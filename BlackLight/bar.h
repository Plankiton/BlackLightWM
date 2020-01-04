#include <stdarg.h>

#include "drw.h"

typedef enum {
    Rect,
    Text
} Type;

typedef struct {
    Clr scheme;
    Type type;
    void (* action)(Drw *drw, int x, int y, unsigned int w, unsigned int h, ...);
} Item;

void item_action_draw_rect(Drw *drw, int x, int y, unsigned int w, unsigned int h, ...);
void item_action_draw_text(Drw *drw, int x, int y, unsigned int w, unsigned int h, ...);
