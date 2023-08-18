#include "main.h"
/**
 * print_prompt - prints the prompt
 *
 * Description: print a prompt
 * Return: nothing
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);
}
