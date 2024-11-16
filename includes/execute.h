#ifndef EXECUTE_H
#define EXECUTE_H

#include <stdbool.h>

struct execute{
    char *script;
};

bool execute_script(struct execute *exec);

#endif