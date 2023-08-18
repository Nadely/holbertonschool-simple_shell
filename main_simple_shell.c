#include "main.h"
/**
 * main - function simple shell
 * @argc: argument count (not used)
 * @argv: argument values (not used)
 * @env: environ variables
 *
 * Descrpition: command interpretor
 * Return: int
 */
int main(int argc, char **argv, char **env)
{
	size_t arg_count = 0;
	int count_command = 0, status = 0, i;
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
			count_command++;
			i = 0;
			if (strcmp(arguments[0], "env") == 0)
				while (env[i]) /*print the environment*/
					printf("%s\n", env[i++]);
			else /*test exit*/
			{
				if (strcmp(arguments[0], "exit") == 0)
					break;
				full_path = get_path(arguments[0], env);

				status = execute_command(full_path, arguments, env, argv, &count_command);
			}
			free_args(arguments);
		}
		arguments = NULL;
	}
	free_args(arguments);
	free(command_line);
	return (status);
}
