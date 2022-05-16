#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * strtok - split the string
 * @str: character used
 * @delim: integer used
 * Return: success
 */
char *strtok(char *str, const char *delim)
{
	static char *remember = NULL;
	int string_length = 0;
	int i = 0;
	int search_hit=0;

	if((str == NULL) && (remember == NULL))
		return (NULL);
	if(str == NULL)
		str = remember;
	string_length = strlen(str) + 1;
	for(i = 0;i < string_length;i++)
	{
		if(str[i] == delim[0])
		{
	search_hit = 1 ;
	break;
		}
	}
	if(search_hit != 1)
	{
		remember = NULL;
		return (str);
	}
	str[i] = '\0';
	if((str + i + 1) != NULL)
		remember = str + i + 1;
	else
		remember = NULL;
	return (str);
}
