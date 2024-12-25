#include "window.h"
#include "execute.h"
#include <gtk/gtk.h>
#include <stdbool.h>
#include <stdio.h>

GtkWidget *window;
GtkWidget *text_area;
GtkTextBuffer *buffer;
GtkWidget *text_output;
GtkTextBuffer *buffer_output;
GtkWidget *box;
GtkWidget *button_execute;
struct execute *exec;

void init_prog(int argc, char **argv, struct execute **exec, GtkWidget **window)
{
    gtk_init(&argc, &argv);  // Initialize GTK

    // Create a new top-level window and set the window pointer
    *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Set window properties
    gtk_window_set_title(GTK_WINDOW(*window), "shell tool");
    gtk_window_set_default_size(GTK_WINDOW(*window), 800, 600);
    gtk_window_set_resizable(GTK_WINDOW(*window), FALSE);
}

void createWindow(int argc, char **argv)
{
    init_prog(argc, argv, &exec, &window);

    button_execute = gtk_button_new_with_label("execute");
    g_signal_connect(button_execute, "clicked", G_CALLBACK(callback), (gpointer) "execute");

    // Make the button thinner
    gtk_widget_set_size_request(button_execute, 100, 30);

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
    gtk_box_pack_start(GTK_BOX(box), button_execute, FALSE, FALSE, 0);

    // Add the box to the window container
    gtk_container_add(GTK_CONTAINER(window), box);

    // Connect the destroy signal to gtk_main_quit to exit the program
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // make output not editable and cursor invisblea
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_output), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(text_output), FALSE);

    // Show the widgets
    gtk_widget_show_all(window);
    gtk_main ();
}

int callback(GtkWidget *widget, gpointer data)
{
    //g_print("%s\n", (char *)data);

    // GtkTextBuffer *buffer_of_button =
    // gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_area));
    GtkTextIter start, end;
    create_exec(&exec);

    if (!buffer)
    {
        g_print("buffer is empty");
        return 1;
    }

    
    if (!exec)
    {
        g_print("the struct is NULL!\n");
    }
    
    // set buffers
    gtk_text_buffer_get_start_iter(buffer, &start);
    gtk_text_buffer_get_end_iter(buffer, &end);

    // Extract text
    //g_print("getting input\n");
    gchar *input = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    //g_print("input: %s\n", input);

    //g_print("validating input\n");
    if (input[0] == '\0')
    {
        g_print("input is empty");
        return 1;
    }

    //g_print("casting into struct\n");
    create_script(exec, strlen(input));
    strcpy(exec->script, input);
    input = NULL;

    //g_print("executing script:\n%s\n", exec->script);
    bool success = execute_script(exec);

    if (!success)
    {
        g_print("Error executing script!\n");
    }
    else
    {

        set_text_in_widget(text_output, exec->script);
        g_print("%s\n", exec->script); // debug stuff! ----
    }

    // free(exec->script);
    g_free(exec->script);
    free(exec);

    return 0;
}

void set_text_in_widget(GtkWidget *widget, const gchar *text)
{
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(widget));
    gtk_text_buffer_set_text(buffer, text, -1); // Set text in buffer
}
