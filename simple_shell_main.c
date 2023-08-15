#include "main.h"
/**
 * main - function simple shell
 *
 * Return: int
 */
int main(int argc, char **argv, char **env)
{
	char *command_line = NULL;
	size_t arg_count = 0;
	struct stat file_stats;
	int result;

	(void)argc;
	(void)argv;
	while (1)
	{
		print_prompt();
		if (command_line != NULL)
		{
			free(command_line);
			command_line = NULL;
		}

		result = getline(&command_line, &arg_count, stdin);
		if(result == -1)
			break;
		command_line = strtok(command_line, " \n");

		if (strcmp(command_line, "exit") == 0)
			break;
		if (stat(command_line, &file_stats) == 0)
			execute_command(command_line, env);
		else
			fprintf(stderr, "Command not fount: %s\n", command_line);

	}
	free(command_line);
	return (0);
}
