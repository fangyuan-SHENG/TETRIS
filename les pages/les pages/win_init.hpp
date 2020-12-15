#ifndef WIN_INIT_HPP
#define WIN_INIT_HPP

#include <gtk/gtk.h>

class win{
    private:

    int win_w;
    int win_h;
    GtkWidget *window;
    const gchar *win_path;

    public:
/*initialiser un win avec *window w h*/
    win(int w,int h);
/*l'image du background*/
    void set_background(GtkWidget *window,int w,int h,const gchar *path);
    GtkWidget get_window(){return *window;};
    int get_win_w(){return win_w;};
    int get_win_h(){return win_h;};

};






#endif //