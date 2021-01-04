#include "buttons.hpp"
#include <gtk/gtk.h>

buttons::buttons(GtkWidget *win,const char *label){
    button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add(GTK_CONTAINER(win),button_box);
    button = gtk_button_new_with_label("label");
}