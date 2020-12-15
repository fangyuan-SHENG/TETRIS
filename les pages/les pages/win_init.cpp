#include <gtk/gtk.h>
#include "win_init.hpp"

win::win(int w,int h):win_w(w),win_h(h){
    this->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
     /* title*/
    gtk_window_set_title(GTK_WINDOW (this->window), "TETRIS");
    /*position*/
    gtk_window_set_position(GTK_WINDOW(this->window), GTK_WIN_POS_CENTER);
    /*set background*/    
    gtk_widget_set_size_request(this->window,this->win_h,this->win_w);

}


void win::set_background(const gchar *path){
/*allow the window to draw*/
    win=get_window();
    gtk_widget_set_app_paintable(win, TRUE);	

    gtk_widget_realize(win);	
    gtk_widget_queue_draw(win);
 
	GdkPixbuf *src_pixbuf = gdk_pixbuf_new_from_file(path, NULL);


	GdkPixbuf *dst_pixbuf = gdk_pixbuf_scale_simple(src_pixbuf, get_win_w(),get_win_h(), GDK_INTERP_BILINEAR);
 
	GdkPixmap *pixmap = NULL;

	gdk_pixbuf_render_pixmap_and_mask(dst_pixbuf, &pixmap, NULL, 255);

	gdk_window_set_back_pixmap(win->window, pixmap, FALSE);
 
	g_object_unref(src_pixbuf);
	g_object_unref(dst_pixbuf);
	g_object_unref(pixmap);




}