#include <stdlib.h>
#include <stdio.h>

#define FILENAME "example.txt"
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	int line_count = 0;
	ssize_t line_size;
	FILE *fp = fopen(FILENAME, "r");
	if (!fp)
	{
		fprintf(stderr, "Error opening file '%s'\n", FILENAME);
		return EXIT_FAILURE;
	}
	line_size = getline(&line_buf, &line_buf_size, fp);
	while (line_size >= 0)
	{
		line_count++;
		printf("%s\n", line_buf);
		line_size = getline(&line_buf, &line_buf_size, fp);
	 }
	free(line_buf);
	line_buf = NULL;
	fclose(fp);
	return EXIT_SUCCESS;
}
