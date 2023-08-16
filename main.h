#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>

void print_prompt(void);

int execute_command(char *command, char **arguments, char **env, char
**argv, int *count_command);

char **parse_command_line(char *command, char **arguments);
void free_args(char **arguments);
char *get_path(char *command, char **env);

#endif
