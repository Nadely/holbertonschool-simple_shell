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
	size_t arg_count = 0;
	int count_command = 0, status = 0;
	char **arguments = NULL, *command_line = NULL, *full_path;

	(void)argc;

	while (1)
	{
		print_prompt();
		if (getline(&command_line, &arg_count, stdin) == -1)
			break;
		arguments = parse_command_line(command_line, arguments);

		if (arguments != NULL)
		{
			if (strcmp(arguments[0], "exit") == 0)
				break;
			count_command++;
			full_path = get_path(arguments[0], env);
			if (full_path != NULL)
				status = execute_command(full_path, arguments, env);
			else
			{
				status = 127;
				fprintf(stderr, "%s: %d: %s: not found\n", argv[0],
				count_command, arguments[0]);
			}
			free_args(arguments);
		}
		arguments = NULL;
	}
	free_args(arguments);
	free(command_line);
	return (status);
}
