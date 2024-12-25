#ifndef EXECUTE_H
#define EXECUTE_H

#include <stdbool.h>
#include <gtk/gtk.h>

struct execute{
    char *script;
    char **lines_of_script;
    int count_lines;
};

void create_script(struct execute *exec, unsigned int size);
bool execute_script(struct execute *exec);
void create_exec(struct execute** exec);
void split_script_lines(struct execute* exec);
void cleanup_script(struct execute* exec);

#endif
