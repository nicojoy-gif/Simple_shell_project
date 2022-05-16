#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
/**
 * unsetenv - deletes the variable name from environment
 * @name: character used
 * Return: 0;
 */
int unsetenv(const char *name)
{
	extern char **environ;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	size_t len = strlen(name);
	for (char **ep = environ; *ep != NULL; )
		if (strncmp(*ep, name, len) == 0 && (*ep)[len] == '=')
		{
			for (char **sp = ep; *sp != NULL; sp++)
				*sp = *(sp + 1);
		}
		else
		{
			ep++;
		}
	return (0);
}
