#ifndef EXECUTE_H
#define EXECUTE_H

#include <stdbool.h>
#include <gtk/gtk.h>

struct execute{
    char *script;
};

void create_script(struct execute *exec, unsigned int size);
bool execute_script(struct execute *exec);
void allocateExec(struct execute** exec);

#endif