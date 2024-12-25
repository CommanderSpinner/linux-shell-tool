#ifndef WINDOW_H
#define WINDOW_H
#include <gtk/gtk.h>
#include "execute.h"

extern GtkWidget *window;
extern GtkWidget *text_area;
extern GtkTextBuffer *buffer;
extern GtkWidget *text_output;
extern GtkTextBuffer *buffer_output;
extern GtkWidget *button;
extern GtkWidget *box;
extern struct execute *exec;

void run_programm(int argc, char **argv);
void init_prog(int argc, char **argv, GtkWidget ** window);
void set_text_in_widget(GtkWidget * widget, const gchar * text);
int callback(GtkWidget * widget, gpointer data);

#endif
