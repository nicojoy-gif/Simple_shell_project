#include <stdio.h>
#include <unistd.h>
/**
 * main - PPID
 *
 * Return: Always 0.
 */

int main(void)
{
	int p_pid;

	p_pid = getppid();
	printf("%d\n", p_pid);
	return (0);
}
