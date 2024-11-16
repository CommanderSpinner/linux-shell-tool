#include "window.h"
#include <gtk/gtk.h>

void createWindow(int argc, char** argv){
    
    gtk_init (&argc, &argv);
        
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_show (window);
    
    gtk_main ();
}