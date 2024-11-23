#include "execute.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

bool execute_script(struct execute *exec) {
  if (exec == NULL) {
    return false;
  }

  system(exec->script);

  return true;
}

// not sure what to do with it
void create_script(struct execute *exec, unsigned int size) {
  exec->script = malloc(size + 1);
  if (exec->script == NULL) {
        fprintf(stderr, "Memory allocation failed for script\n");
        exit(1); 
    }
}

void allocateExec(struct execute** exec){
    *exec = malloc(sizeof(struct execute));
    if (exec == NULL)
    {
        g_print("Memory allocation failed for exec\n");
        exit(1); // Exit if memory allocation fails
    }
}