#ifndef MAIN
#define MAIN

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>

void print_prompt(char *path);
int execute_command(char *command, char **env);

#endif
