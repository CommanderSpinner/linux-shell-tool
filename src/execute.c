#include "execute.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

bool execute_script(struct execute *exec) {
  if (exec == NULL) {
    return false;
  }


  split_script_lines(exec);

  for(int i = 0; i < exec->count_lines; i++){
    system(exec->lines_of_script[i]);
  }

  return true;
}

void split_script_lines(struct execute *exec) {
  char *line = strtok(exec->script, "\n");
  exec->count_lines = 0;

  while (line != NULL) {
    exec->count_lines++;
    exec->lines_of_script[exec->count_lines - 1] = line;  // Store the line in the array
    line = strtok(NULL, "\n");
  }
}

/*
void split_script_lines(struct execute *exec){
  char *line = malloc(strlen(exec->script) * sizeof(char));

  line = strtok(exec->script, "\n");
  while (line != NULL) {
    exec->count_lines++;
    exec->lines_of_script = &line;
    line = strtok(NULL, "\n");
  }

}
*/

void create_script(struct execute *exec, unsigned int size) {
  exec->script = malloc(size + 1);
  if (exec->script == NULL) {
        fprintf(stderr, "Memory allocation failed for script\n");
        exit(1); 
  }
  exec->lines_of_script = malloc(strlen(exec->script) * sizeof(char));
}

void create_exec(struct execute** exec){
    *exec = malloc(sizeof(struct execute));
    if (exec == NULL){
        g_print("Memory allocation failed for exec\n");
        exit(1); // Exit if memory allocation fails
    }
}

void cleanup_script(struct execute* exec){
    free(exec->lines_of_script);
    free(exec->script);
    free(exec);
}
