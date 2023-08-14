#include "main.h"
/**
 * main - function simple shell
 *
 * Return: int
 */
int main(void)
{
	char *envp[] = {NULL};
	char *command_line = NULL;
	char *argument_line[] = {"/bin/ls", NULL};
	pid_t pid;
	size_t arg_count = 0;

	do
	{
		print_prompt();
		if (command_line != NULL)
			free(command_line);
		getline(&command_line, &arg_count, stdin);
		command_line = strtok(command_line, " \n");
		pid = fork();
		if (pid == 0)
			execve(command_line, argument_line, envp);
		sleep(1);
	} while (strcmp(command_line, "exit") != 0);
	return (0);
}
