#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
/**
 * setenv - set environment variable
 * @name: character used
 * @value: character used
 * @overwrite: integer used
 * Return: success
 */
int setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL || value == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	if (getenv(name) != NULL && overwrite == 0)
		return (0);
	unsetenv(name);
	char *es = malloc(strlen(name) + strlen(value) + 2);
	if (es == NULL)
		return (-1);
	 strcpy(es, name);
	 strcat(es, "=");
	 strcat(es, value);

	 return (putenv(es) != 0) ? -1 : 0;
}
