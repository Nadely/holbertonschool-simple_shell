#include "main.h"
/**
 * *get_path - get a path where the command can be found
 * @command: the command we are searching for
 * Return: a pointer to the path or null (failure)
 */
char *get_path(char *command, char **env)
{
	char *path = NULL, *result = NULL, *token = NULL;
	int i, res_len = 0;
	struct stat file_info;

	/*if (stat(command, &file_info) == 0)
		return (strdup(command));*/
	for (i = 0; env[i]; i++)
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' && env[i][4] == '=')
			path = strdup(env[i]);

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
	free(path);
	return (0);
}
