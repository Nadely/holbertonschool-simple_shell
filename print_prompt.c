#include "main.h"
/**
 * print_prompt - prints the current working directory
 * Return: printing the command line prompt indicator in the terminal
 */
void print_prompt(char *path)
{
	write(1, path, strlen(path));
	write(1, "$ ", 2);
}

