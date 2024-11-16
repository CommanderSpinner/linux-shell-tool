#include <gtk/gtk.h>
#include "window.h"
#include <stdbool.h>

void callback(GtkWidget *widget, gpointer data);

GtkWidget *window;
GtkWidget *text_area;
GtkTextBuffer *buffer;
GtkWidget *text_output;
GtkTextBuffer *buffer_output;
GtkWidget *box;
GtkWidget *button;

void createWindow(int argc, char** argv){
    
    gtk_init (&argc, &argv);
    gtk_window_set_title (GTK_WINDOW (window), "shell tool");
        
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_resizable(GTK_WINDOW (window), FALSE);

    button = gtk_button_new_with_label("Execute");
    g_signal_connect(button, "clicked", G_CALLBACK(callback), (gpointer)"execute");

    // Make the button thinner
    gtk_widget_set_size_request(button, 100, 30);

    // Create the text buffer and text area
    buffer = gtk_text_buffer_new(NULL);
    buffer_output = gtk_text_buffer_new(NULL);

    text_area = gtk_text_view_new_with_buffer(buffer);
    text_output = gtk_text_view_new_with_buffer(buffer_output);

    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_area), GTK_WRAP_WORD);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_output), GTK_WRAP_WORD);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);  // 10px spacing between widgets

    // Add the text_area and text_output to the box
    gtk_box_pack_start(GTK_BOX(box), text_area, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), text_output, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);

    // Add the box to the window container
    gtk_container_add(GTK_CONTAINER(window), box);

    // Connect the destroy signal to gtk_main_quit to exit the program
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    //g_signal_connect (GTK_OBJECT (button), "clicked", GTK_SIGNAL_FUNC (callback), (gpointer) "execute");

    // make output not editable and cursor invisblea
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_output), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(text_output), FALSE);

    // Show the widgets
    gtk_widget_show_all(window);
    gtk_main ();
}

void callback (GtkWidget *widget, gpointer data)
{
    g_print ("%s\n", (char *) data);
}