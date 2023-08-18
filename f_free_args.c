#include "main.h"
/**
 * free_args - free arguments
 * @arguments: arguments
 *
 * Description: free memory
 * Return: Nothing
 */
void free_args(char **arguments)
{
	int i;

	if (arguments != NULL)
	{
		for (i = 0; arguments[i] != NULL; i++)
			free(arguments[i]);
		free(arguments);
	}
}
