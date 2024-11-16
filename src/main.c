#include <gtk/gtk.h>
#include "window.h"

int main (int argc, char *argv[])
{
    createWindow(argc, argv);
    mainProcess();
    return 0;
}
