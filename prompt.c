#include <stdio.h>
#include "shell.h"
#include <stddef.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#if !(defined _POSIX_C_SOURCE)
typedef long int ssize_t;
#endif

#if !(defined _POSIX_C_SOURCE) || _POSIX_C_SOURCE < 200809L

#if !(defined SSIZE_MAX)
#define SSIZE_MAX (SIZE_MAX >> 1)
#endif

/**
 * getline - prints "$ ", wait for the user to enter a command,
 *@lineptr: character used
 *@n: integer used
 *@stream: file used
 */
ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	const size_t INITALLOC = 16;
	const size_t ALLOCSTEP = 16;
	size_t num_read = 0;

	if ((NULL == lineptr) || (NULL == n) || (NULL == stream))
	{
		errno = EINVAL;
		return (-1);
	}
	if (NULL == *lineptr)
	{
		*lineptr = malloc(INITALLOC);
		if (NULL == *lineptr)
		{
			return (-1);
		}
		else
		{
			*n = INITALLOC;
		}
	}
	int c;
	while (EOF != (c = getc(stream)))
	{
		num_read++;
		if (num_read >= *n)
		{
			size_t n_realloc = *n + ALLOCSTEP;
			char *tmp = realloc(*lineptr, n_realloc + 1);
			if (NULL != tmp)
			{
				*lineptr = tmp;
				n = n_realloc;
			}
			else
			{
				return (-1);
			}
			if (SSIZE_MAX < *n)
			{
				errno = ERANGE;
				return (-1);
			}
		}
		(*lineptr)[num_read - 1] = (char) c;
		if (c == '\n')
		{
			break;
		}
	}
	if (EOF == c)
	{
		errno = 0;
		return (-1);
	}
}
(*lineptr)[num_read] = '\0';
return (ssize_t) num_read;
}
#endif
