#ifndef WINDOW_H
#define WINDOW_H
#include <gtk/gtk.h>

extern GtkWidget *window;
extern GtkWidget *text_area;
extern GtkTextBuffer *buffer;
extern GtkWidget *text_output;
extern GtkTextBuffer *buffer_output;

void createWindow(int argc, char** argv);

void mainProcess();

#endif