#ifndef BUTTONS_HPP
#define BUTTONS_HPP

#include <gtk/gtk.h>

class buttons{
    public:
    GtkWidget *button;
    GtkWidget *button_box;

    buttons(GtkWidget *win,const char *label);

};



#endif //