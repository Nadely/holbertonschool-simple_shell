#include "main.h"
/**
 * execute_command - execute a command
 * @command: the command to execute
 * @env: environment variables
 * Description : Cette fonction prend une commande en argument et l'exécute
 * à l'aide de l'appel système execve. Elle crée un processus enfant en
 * utilisant l'appel système fork, puis utilise execve pour remplacer le
 * processus enfant par la commande souhaitée. Le processus parent attend que
 * le processus enfant ait terminé son exécution avant de continuer
 *
 * Return: 0 if successful, -1 on failure
 */

int execute_command(char *command, char **env)
{
	char *argument_line[] = {"notnull", NULL};
	pid_t pid;
	int result, *for_child_to_finish = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		result = execve(command, argument_line, env);
		if (result == -1)
			perror("execve");
		exit(0);
	}
	wait(for_child_to_finish);
	return (0);
}
