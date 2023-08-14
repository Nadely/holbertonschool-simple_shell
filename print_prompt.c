#include "main.h"
void print_prompt()
{
	const int buffer_size = 1024;
	char path[1024];

	getcwd(path, buffer_size);
	write(1, path, strlen(path));
	write(1, "$ ", 2);
}
