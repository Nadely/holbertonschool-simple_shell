#include "main.h"
/**
 * **parse_command_line - function to get the executable
 * @command: pointer to the command line
 *
 * Return: NOTHING
 */
char **parse_command_line(char *command)
{
	char *line = strdup(command), *arg;
	int i = 0, count_args = 0;
	char **arguments;

	arg = strtok(line, " \n");
	while (arg != NULL) /* counts the number of arguments for malloc*/
	{
		arg = strtok(NULL, " \n");
		count_args++;
	} /* finished counting*/

	free(line);
	if (count_args == 0)
		return (0);
	arguments = malloc(sizeof(char *) * (count_args + 1));
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