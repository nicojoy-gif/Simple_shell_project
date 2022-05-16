#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
/**
 * _unsetenv - deletes the variable name from environment
 * @name: character used
 * Return: 0;
 */
int _unsetenv(const char *name)
{
	char **args = name->tokens + 1;

	if (*args)
	{
		while (*args)
			del_dict_node(&name->env, *args++);
		name->status = EXIT_SUCCESS;
	}
	else
	{
		perrorl("Too few arguments.", *name->tokens, NULL);
		name->status = EXIT_FAILURE;
	}
	return (name->status);
}
	
