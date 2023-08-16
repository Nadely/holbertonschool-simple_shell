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
	int result, status = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		result = execve(command, arguments, env);
		if (result == -1)
			perror("execve");
		exit(0);
	}
	wait(&status);
	return (status);
}
