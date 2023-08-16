#include "main.h"
/**
 * execute_command - execute a command
 * @command: the command to execute
 * @arguments: array of pointers to arguments
 * @env: environment variables
 * @argv: arguments of the ./simple shell
 * @count_command: counts the number of commands executed
 * Description : Cette fonction prend une commande en argument et l'exécute
 * à l'aide de l'appel système execve. Elle crée un processus enfant en
 * utilisant l'appel système fork, puis utilise execve pour remplacer le
 * processus enfant par la commande souhaitée. Le processus parent attend que
 * le processus enfant ait terminé son exécution avant de continuer
 *
 * Return: status
 */

int execute_command(char *command, char **arguments, char **env,
char **argv, int *count_command)
{
	pid_t pid;
	int status = 0;
	/*struct stat file_stats;*/

	if (command != NULL)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return (-1);
		}
		if (pid == 0)
			execve(command, arguments, env);
		else
		{
			wait(&status);
			if (WIFEXITED(status) && WEXITSTATUS(status) == 2)
				status = 2;
		}
		free(command);
	}
	else
	{
		status = 127;
		fprintf(stderr, "%s: %d: %s: not found\n", argv[0],
		*count_command, arguments[0]);
	}
	return (status);
}
