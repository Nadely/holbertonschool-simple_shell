#include "main.h"
/**
 * main - function simple shell
 * @argc: argument count (not used)
 * @argv: argument values (not used)
 * @env: environ virables
 * Return: int
 */
int main(int argc, char **argv, char **env)
{
	char *command_line = NULL;
	size_t arg_count = 0;
	struct stat file_stats;
	int result, i;
	char **arguments = NULL;

	(void)argc;
	(void)argv;

	while (1)
	{
		/*print_prompt(path);*/
		/*if (command_line != NULL)
		{
			free(command_line);
			command_line = NULL;
		}*/
		result = getline(&command_line, &arg_count, stdin);

		if (result == -1)
			break;
		arguments = parse_command_line(command_line, arguments);
		/*free(command_line);*/

		if (strcmp(arguments[0], "exit") == 0)
			break;
		if (stat(arguments[0], &file_stats) == 0)
			execute_command(arguments[0], arguments, env);
		else
			fprintf(stderr, "Command not found: %s\n", arguments[0]);

		for (i = 0; arguments[i] != NULL; i++)
			free(arguments[i]);

		free(arguments);
		arguments = NULL;
	}
	if (arguments != NULL)
	{
		for (i = 0; arguments[i] != NULL; i++)
			free(arguments[i]);
		free(arguments);
	}
	free(command_line);
	return (0);
}
