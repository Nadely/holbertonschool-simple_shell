#include "main.h"
/**
 * print_prompt - prints the current working directory
 * Return: printing the command line prompt indicator in the terminal
 */
void print_prompt(void)
{
	const int buffer_size = 1024;
	char path[1024];

	getcwd(path, buffer_size);
	write(1, path, strlen(path));
	write(1, "$ ", 2);
}

