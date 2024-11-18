#ifndef EXECUTE_H
#define EXECUTE_H

#include <stdbool.h>

struct execute{
    char *script;
};

void create_script(struct execute *exec, unsigned int size);
bool execute_script(struct execute *exec);

#endif