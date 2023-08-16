#include "main.h"
/**
 * *get_path - get a path where the command can be found
 * @command: the command we are searching for
 * Return: a pointer to the path or null (failure)
 */
char *get_path(char *command, char **env)
{
	char *path, *result = NULL, *token;
	int i, res_len;
	struct stat file_info;

	for (i = 0; env[i]; i++)
		if (env[i][0] == 'P' && env[i][1] == 'A')
			path = strdup(env[i]);

	token = strtok(path, "=");
	token = strtok(NULL, ":");
	while (token != NULL) /* counts the number of arguments for malloc*/
	{
		/*printf("%s\n", token);*/
		res_len = strlen(token) + strlen(command) + 2;
		result = malloc(res_len);

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
