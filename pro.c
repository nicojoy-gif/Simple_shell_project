#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "shell.h"
/**
 * main - check the code
 *
 * Return(0);
 */
int main(void)
{
	FILE* stream;
	stream = fopen("stream.txt", "r");
	char *s;

	if ((s = getline(*lineptr, 3, stream)) != NULL)
		printf("%s\n", s);
	free(s);
	if ((s = getline(*lineptr, 5, stream)) != NULL)
		printf("%s\n", s);
	free(s);
	fclose(stream);
	return (0);
}
