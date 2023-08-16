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
	int result, i, count_command = 0, status = 0;
	char **arguments = NULL;
	char exec_path[50] = "/bin/";

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_prompt();
		result = getline(&command_line, &arg_count, stdin);


		if (result == -1)
			break;
		arguments = parse_command_line(command_line, arguments);

		if (arguments != NULL)
		{
			if (strcmp(arguments[0], "exit") == 0)
				break;
			count_command++;
			strcat(exec_path, arguments[0]);
			if (stat(arguments[0], &file_stats) == 0)
				status = execute_command(arguments[0], arguments, env);
			else if (stat(exec_path, &file_stats) == 0)
				status = execute_command(exec_path, arguments, env);
			else
			{
				status = 127;
				fprintf(stderr, "%s: %d: %s: not found\n", argv[0], count_command, arguments[0]);
			}
			strcpy(exec_path, "/bin/");

			for (i = 0; arguments[i] != NULL; i++)
				free(arguments[i]);

			free(arguments);
		}
		arguments = NULL;
	}
	if (arguments != NULL)
	{
		for (i = 0; arguments[i] != NULL; i++)
			free(arguments[i]);
		free(arguments);
	}
	free(command_line);
	return (status);
}
