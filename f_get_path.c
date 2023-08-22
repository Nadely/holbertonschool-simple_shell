#include "main.h"
/**
 * *get_path - get a path where the command can be found
 * @ev: environment variables
 * @command: the command we are searching for
 *
 * Description: Take as input the command typed by the user and return a
 * string containing the path were the command can be found
 * Return: a pointer to the path or null (failure)
 */
char *get_path(char *command, char **ev)
{
	char *path = NULL, *result = NULL, *token = NULL;
	int i, result_len = 0;
	struct stat file_info;

	if (command[0] == '/' || (command[0] == '.'))
		if (stat(command, &file_info) == 0) /*if the command start with '/' or '.'*/
			return (strdup(command)); /*no need to search for a path*/

	for (i = 0; ev[i]; i++) /*get path from environment*/
		if (ev[i][0] == 'P' && ev[i][1] == 'A' && ev[i][2] == 'T' && ev[i][4] == '=')
			path = strdup(ev[i]);

	if (path != NULL)
	{
		token = strtok(path, "="); /*remove "PATH="*/
		token = strtok(NULL, ":");
		while (token != NULL) /*combine each path with the command*/
		{
			result_len = strlen(token) + strlen(command) + 2;
			result = malloc(result_len);
			for (i = 0; i < result_len; i++)
				result[i] = 0;

			strcat(result, token);
			strcat(result, "/");
			strcat(result, command);
			if (stat(result, &file_info) == 0) /*test if the command exist here*/
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
