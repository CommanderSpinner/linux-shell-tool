#include "execute.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

#define MAX_LINES 100

bool execute_script(struct execute *exec)
{
	if (exec == NULL) {
		return false;
	}

	split_script_lines(exec);

	for (int i = 0; i < exec->count_lines; i++) {
		system(exec->lines_of_script[i]);
	}

	return true;
}

void split_script_lines(struct execute *exec)
{
	char *line = strtok(exec->script, "\n");
	exec->count_lines = 0;

	while (line != NULL) {
		if (exec->count_lines >= MAX_LINES) {
			fprintf(stderr, "Too many script lines, increase MAX_LINES\n");
			break;  // Avoid buffer overflow
		}

		exec->lines_of_script[exec->count_lines] = strdup(line); // Store a copy of the line
		if (exec->lines_of_script[exec->count_lines] == NULL) {
			fprintf(stderr, "Memory allocation failed for script line\n");
			break;
		}

		exec->count_lines++;
		line = strtok(NULL, "\n");
	}
}


void create_script(struct execute *exec, unsigned int size)
{
	exec->script = malloc(size + 1);  // Allocate memory for the script text
	if (exec->script == NULL) {
		fprintf(stderr, "Memory allocation failed for script\n");
		exit(1);
	}

	// Allocate memory for the array of line pointers
	exec->lines_of_script = malloc(sizeof(char *) * MAX_LINES); // 500 is max lines
	if (exec->lines_of_script == NULL) {
		fprintf(stderr, "Memory allocation failed for script lines\n");
		free(exec->script);  // Free script memory before exiting
		exit(1);
	}
}


void create_exec(struct execute **exec)
{
	*exec = malloc(sizeof(struct execute));
	if (exec == NULL) {
		g_print("Memory allocation failed for exec\n");
		exit(1);	// Exit if memory allocation fails
	}
}

void cleanup_script(struct execute *exec)
{
	//free each line of the script
	for (int i = 0; i < exec->count_lines; i++) {
		free(exec->lines_of_script[i]);
	}

	free(exec->script);
	free(exec);
}
