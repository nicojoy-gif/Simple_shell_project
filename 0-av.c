#include <stdio.h>

/**
 * main - entry point
 * @av: argument used
 * @ac: integer used
 * Return: success
 */
int main(__attribute__((unused))int ac, char **av)
{
	while (*av != NULL)
	{
		printf("%s\n", *av);
		av++;
	}
	return (0);
}
