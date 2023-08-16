#include "main.h"
/**
 * print_prompt - prints the current working directory
 * Return: printing the command line prompt indicator in the terminal
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);
}
