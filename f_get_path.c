#include "main.h"
/**
 * *get_path - get a path where the command can be found
 * @ev: environment variables
 * @command: the command we are searching for
 * Return: a pointer to the path or null (failure)
 */
char *get_path(char *command, char **ev)
{
	char *path = NULL, *result = NULL, *token = NULL;
	int i, res_len = 0;
	struct stat file_info;

	if (command[0] == '/' || (command[0] == '.') || strcmp(command, "env") == 0)
		if (stat(command, &file_info) == 0)
			return (strdup(command));
	for (i = 0; ev[i]; i++)
		if (ev[i][0] == 'P' && ev[i][1] == 'A' && ev[i][2] == 'T' && ev[i][4] == '=')
			path = strdup(ev[i]);
	if (path != NULL)
	{
		token = strtok(path, "=");
		token = strtok(NULL, ":");
		while (token != NULL) /* counts the number of arguments for malloc*/
		{
			res_len = strlen(token) + strlen(command) + 2;
			result = malloc(res_len);
			for (i = 0; i < res_len; i++)
				result[i] = 0;

			strcat(result, token);
			strcat(result, "/");
			strcat(result, command);
			if (stat(result, &file_info) == 0)
			{
				free(path);
				return (result);
			}
			free(result);
			result = NULL;
			token = strtok(NULL, ":");
		}
	}
	free(path);
	return (0);
}
