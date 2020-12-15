#include <gtk/gtk.h>
#include "win_init.hpp"




int main( int argc, char *argv[] )
{
/* GtkWidget*/
    win win_a(200,100);

/* initial*/
    gtk_init (&argc, &argv);
    win_a.set_background("background.jpg");
/*show the window*/
    gtk_widget_show (win_a.get_window());


    gtk_main ();

    return 0;
}