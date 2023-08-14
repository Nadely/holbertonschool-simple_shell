#include <unistd.h>
#include <string.h>
#include <stdio.h>
void faire_quelque_chose()
{

}
int main(void)
{
	const int buffer_size = 1024;
	char path[1024];
	char *envp[] = { NULL };
	char *command_line = NULL;
	char *argument_line[] = { "/bin/ls", "-l", "-a", NULL };
	pid_t pid;
	size_t arg_count = 0;

	while (1)
	{
		getcwd(path, buffer_size);
		write(1, path, strlen(path));
		write(1, "$ ", 2);
		getline(&command_line, &arg_count, stdin);

		pid = fork();
		if (pid == 0)
			execve("/bin/ls", argument_line, envp);
		sleep(1);
		faire_quelque_chose();
	}
	return (0);
}
