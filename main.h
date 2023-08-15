#ifndef MAIN
#define MAIN

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void print_prompt();
int execute_command(char *command, char **env);

#endif
