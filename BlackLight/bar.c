#include "bar.h"

void
item_action_draw_rect(Drw *drw, int x, int y, unsigned int w, unsigned int h, ...){
    va_list prop;
    va_start(prop, h);

    int filled = va_arg(prop, int);
    int invert = va_arg(prop, int);

    va_end(prop);

    drw_rect(drw, x, y, w, h, filled, invert);
}

void
item_action_draw_text(Drw *drw, int x, int y, unsigned int w, unsigned int h, ...){
    va_list prop;
    va_start(prop, h);

    unsigned int lpad = va_arg(prop, unsigned int);
    char *text = va_arg(prop, char *);
    int invert = va_arg(prop, int);

    va_end(prop);

    drw_text(drw, x, y, w, h, lpad, text, invert);
}

Item * create_item(Clr * scheme, Type type){
    Item item = (Item){
        .scheme = scheme,
        .type = type,
    };

    if (item.type == Rect)
        item.action = item_action_draw_rect;
    else
        item.action = item_action_draw_text;

    return &item;
}

void
drawbar(Item *items){

}
