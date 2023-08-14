#include "main.h"

int main(void)
{
	char *envp[] = { NULL };
	char *command_line = NULL;
	char *argument_line[] = { "/bin/ls", "-l", "-a", NULL };
	pid_t pid;
	size_t arg_count = 0;

	while (1)
	{
		print_prompt();
		getline(&command_line, &arg_count, stdin);

		pid = fork();
		if (pid == 0)
			execve("/bin/ls", argument_line, envp);
		sleep(1);
	}
	return (0);
}
