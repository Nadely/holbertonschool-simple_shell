#include "main.h"
/**
 * **parse_command_line - function to get the executable
 * @command: pointer to the command line
 * @arguments: array of pointers to arguments
 *
 * Description: cut the command line into arguments and make an array with it
 * Return: NOTHING
 */
char **parse_command_line(char *command, char **arguments)
{
	char *line = strdup(command), *arg;
	int i = 0, count_args = 0;

	arg = strtok(line, " \n");
	while (arg != NULL) /* counts the number of arguments for malloc*/
	{
		arg = strtok(NULL, " \n");
		count_args++;
	} /* finished counting*/

	free(line);
	if (count_args == 0)
		return (0);

	arguments = realloc(arguments, sizeof(char *) * (count_args + 1));
	if (arguments == NULL)
		exit(EXIT_FAILURE);

	arguments[count_args] = NULL;
	line = strdup(command); /*go back to start*/

	/* put arguments inside array arguments*/
	arg = strtok(line, " \n");
	while (arg != NULL)
	{
		arguments[i] = strdup(arg);
		arg = strtok(NULL, " \n");
		i++;
	}
	free(line);
	return (arguments);
}
