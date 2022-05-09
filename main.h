#include <stdio.h>
#include <stddef.h>
#ifndef MAIN_H
#define MAIN_H
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void displayWords(char *wordArray[], int numWords);
int countSpaces(char theString[]);
char *strtok(char *str, const char *delim);
#endif
