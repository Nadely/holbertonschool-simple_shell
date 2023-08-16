#include "main.h"
/**
 * execute_command - execute a command
 * @command: the command to execute
 * @arguments: array of pointers to arguments
 * @env: environment variables
 * Description : Cette fonction prend une commande en argument et l'exécute
 * à l'aide de l'appel système execve. Elle crée un processus enfant en
 * utilisant l'appel système fork, puis utilise execve pour remplacer le
 * processus enfant par la commande souhaitée. Le processus parent attend que
 * le processus enfant ait terminé son exécution avant de continuer
 *
 * Return: status
 */

int execute_command(char *command, char **arguments, char **env)
{
	pid_t pid;
	int status = 0;
	/*struct stat file_stats;*/

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		execve(command, arguments, env);
	}
	else
	{
		wait(&status);
		/*
		*if (strcmp(arguments[0], "/bin/ls") == 0)
		*if (stat(arguments[1], &file_stats) != 0 && arguments[1] != NULL)
		*return(2);
		*/
	}
	return (status);
}
