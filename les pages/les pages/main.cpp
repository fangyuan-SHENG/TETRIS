#include <gtk/gtk.h>
#include "buttons.hpp"

void activate(GtkApplication *app,gpointer data);
static void fonction_page_1(GtkWidget *button,gpointer data);

   
int main(int argc,char *argv[])
{
/* GtkApplication */
  GtkApplication *app;
  int app_status;

  app = gtk_application_new("org.tetris.gtk",G_APPLICATION_FLAGS_NONE);

  g_signal_connect(app , "activate" , G_CALLBACK(activate) , NULL);

  app_status=g_application_run(G_APPLICATION(app),argc,argv); 

  g_object_unref(app); 

  return app_status;
}
//g++ main.cpp win_init.cpp `pkg-config --cflags --libs gtk+-3.0` -Wall -o win




void activate(GtkApplication *app,gpointer data)
{
  GtkWidget *window;

  window = gtk_application_window_new(app);

  gtk_window_set_title(GTK_WINDOW(window),"TETRIS");

  gtk_window_set_default_size(GTK_WINDOW(window),500,500);

  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  //GtkWidget* image=gtk_image_new_from_file("background.jpg");

  //gtk_container_add(GTK_CONTAINER(window), image);
  GdkPixbuf *pixbuf;

  image = gtk_image_new_from_file ("background.jpg");
  pixbuf = gtk_image_get_pixbuf (GTK_IMAGE(image));
  pixbuf = gdk_pixbuf_scale_simple(pixbuf, 
       gdk_screen_get_width(screen) - 16, // 16: window border SHIFT 
       gdk_screen_get_height(screen) - 140, // 140: height SHIFT
       GDK_INTERP_BILINEAR);
  gtk_image_set_from_pixbuf(GTK_IMAGE(image), pixbuf);
    // 我放到fixed里了，这个随便
 // gtk_fixed_put(GTK_FIXED(fixed), image, 0, 0);


  buttons button_jeu_solo(window,"jeu");
  g_signal_connect(button_jeu_solo.button , "clicked" , G_CALLBACK(fonction_page_1) , NULL);
  gtk_container_add(GTK_CONTAINER(button_jeu_solo.button_box) , button_jeu_solo.button);

  gtk_widget_show_all(window);


}




static void fonction_page_1(GtkWidget *button,gpointer data){
    printf("Hello , world!\n");
}


/*
int main( int argc, char *argv[]) { 
  GtkWidget *window; 
  GtkWidget *layout; 
  GtkWidget *image; 
  GtkWidget *button; 
  gtk_init(&argc, &argv); 
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
  gtk_window_set_default_size(GTK_WINDOW(window), 290, 200); 
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER); 
  layout = gtk_layout_new(NULL, NULL); 
  gtk_container_add(GTK_CONTAINER (window), layout); 
  gtk_widget_show(layout); 
  image = gtk_image_new_from_file("bg.jpg"); 
  gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0); 
  button = gtk_button_new_with_label("Button"); 
  gtk_layout_put(GTK_LAYOUT(layout), button, 20, 50); 
  gtk_widget_set_size_request(button, 80, 35); 
  g_signal_connect_swapped(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL); 
  gtk_widget_show_all(window); 
  gtk_main(); 
  return 0;
  }*/