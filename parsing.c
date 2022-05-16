#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell.h"

/**
 * _parsingString - split string to array
 *
 * @prmString: argument's string
 * @prmSeparator: separators
 */
void _parsingString(char *prmString, char *prmSeparator, char *prmArgv[])
{
	char *strToken;
	int i = 0;

	strToken = strtok(prmString, prmSeparator);

	if (strToken == NULL)
		return;

	while (strToken != NULL && _strcmp(strToken, "\n") != 0)
	{
		prmArgv[i] = strToken;
		strToken = strtok(NULL, prmSeparator);

		if (strToken == NULL)
		{
			prmArgv[i + 1] = NULL;
			return;
		}
		i++;
	}
	prmArgv[i] = NULL;
	free(strToken);
}

/**
 * _parsingArguments - split argument's string to array
 *
 * @prmParametersLine: argument's string
 * @prmArgv: argument's array
 */
void _parsingArguments(char *prmParametersLine, char *prmArgv[])
{
	if (prmParametersLine == NULL || prmArgv == NULL)
		return;

	_parsingString(prmParametersLine, SEPARATORS, prmArgv);
}

/**
 * _parsingEnvironment - split environment variable
 *
 * @prmEnvironmentName: environment name
 *
 * Return: linked list
 */
environment_t *_parsingEnvironment(char *prmEnvironmentName)
{
	char *name, *strToken, *environmentVariable, *tmpEnv;
	environment_t *environmentList;
	int sizeEnv;

	environmentList = NULL;
	environmentVariable = _getenv(prmEnvironmentName);

	sizeEnv = _strlen(environmentVariable);
	tmpEnv = malloc(sizeof(char) * sizeEnv + 1);
	if (tmpEnv == NULL)
		return (NULL);
	tmpEnv = _strcpy(tmpEnv, environmentVariable);

	strToken = strtok(tmpEnv, "=");

	if (strToken == NULL)
		return (NULL);

	name = strToken;

	while (strToken != NULL)
	{
		if (strToken != name)
		{
			_addNodeEnd(&environmentList, name, strToken);
		}
		strToken = strtok(NULL, ":");
	}
	free(tmpEnv);

	return (environmentList);
}
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
