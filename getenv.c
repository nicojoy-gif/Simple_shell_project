#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include shell.h

/**
 * _getenv - get environmental variable
 * @name: character used
 * Return: environmental value
 */
char *_getenv(const char *name)
{
  int cLoop = 0;

	while (environ[cLoop] != NULL)
	{
    if (_strstr(environ[cLoop], name, 1) != NULL)
		{
			return (environ[cLoop]);
		}
		cLoop++;
	}

	return (NULL);
}
