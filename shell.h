#ifndef SHELL_H
#define SHELL_H

#define SEPARATORS " \n\t\r\a\v"
#define PATH_SEPARATOR ":"
#define PROMPT "$ "

extern char **environ;

#include <stddef.h>

/**
 * Struct environment - environment variable
 *
 * @name: environment name
 * @value: environment value
 * @next: points to the next node
 */
typedef struct environment_s
{
	char *name;  /* ex: PATH */
	char *value; /* ex: /bin:/usr/bin */
	struct environment_s *next;
} environment_t;

/**
 * Strings
 */
int _strlen(char *s);
char *_str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
char *_strstr(char *haystack, char *needle, int prmBegin);
char *_strdup(char *str);
unsigned int _strspn(char *s, char *accept);
char *_strchr(char *s, char c);
char *_strncat(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
/**
 * Build
 */
int _isBuildIn(char *prmCommandName);
void _execCmd(char *prmArguments[]);
/**
 * Base
 */
char *_getenv(const char *name)
char *_which(char *prmCommandName);

/**
 * Linkedlist
 */
environment_t *_createNode(char *prmName, char *prmValue);
environment_t *_getLastNode(environment_t *prmHeadNode);
environment_t *_addNodeEnd(environment_t **prmHead, char *prmName, char *prmValue);
void _freeList(environment_t *head);
size_t _printLinkedList(const environment_t *h);

/**
 * Parsing
 */
void _parsingString(char *prmString, char *prmSeparator, char *prmArgv[]);
void _parsingArguments(char *prmParametersLine, char *prmArgv[]);
environment_t *_parsingEnvironment(char *prmEnvironmentName);
char *strtok(char *str, const char *delim)
 

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void displayWords(char *wordArray[], int numWords);
int countSpaces(char theString[]);
char *strtok(char *str, const char *delim);
#endif
