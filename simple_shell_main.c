#include "main.h"
/**
 * main - function simple shell
 *
 * Return: int
 */
int main(void)
{
	char *envp[] = { NULL };
	char *command_line = NULL;
	char *argument_line[] = { "/bin/ls", "-l", "-a", NULL };
	pid_t pid;
	size_t arg_count = 0;

	while (1)
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
	}
	return (0);
}
