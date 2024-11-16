#include <stdlib.h>
#include "execute.h"
#include <stdbool.h>

bool execute_script(struct execute *exec){
    if (exec == NULL) {
        return false;
    }

    system(exec->script);

    return true;
}