#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * _strlen - returns the length of a string
 * @s: char pointer
 * Return: Size of the string
 */
int _strlen(char *s)
{
  if (s == NULL || *s == '\0')
		return (0);
	return (_strlen(s + 1) + 1);
}
/**
 * str_concat - concatenates two strings.
 * @s1: char pointer to concatenate
 * @s2: char pointer to concatenate
 * Return: char pointer concatenated
 */
char *_str_concat(char *s1, char *s2)
{
  char *s;
	int cLoop1, cLoop2, size;

  if (s1 == NULL)
		s1 = "\0";
  if (s2 == NULL)
		s2 = "\0";

	size = strlen(s1) + strlen(s2);
	s = malloc(sizeof(char) * (size + 1));

	if (s == NULL)
		return (NULL);

	for (cLoop1 = 0; s1[cLoop1]; cLoop1++)
		s[cLoop1] = s1[cLoop1];
  for (cLoop2 = 0; s2[cLoop2]; cLoop1++, cLoop2++)
		s[cLoop1] = s2[cLoop2];

	s[cLoop1] = '\0';

	return (s);
  /**
   * _strstr - locates a substring.
 *
 * @haystack: string where to search
 * @needle: string to search
 * @prmBegin: force to start at begin if true 
 *
 * Return: the address to first location
 */
char *_strstr(char *haystack, char *needle, int prmBegin)
{
	int haystackLoop = 0, needleLoop = 0, size = _strlen(needle);

	if (needle[0] == '\0')
	{
		return (haystack);
	}

	for (
		haystackLoop = 0, needleLoop = 0;
		haystack[haystackLoop + needleLoop] != '\0';
		needleLoop++
	)
	{
		if (needle[needleLoop] != haystack[haystackLoop + needleLoop])
		{
			if (prmBegin == 0)
			{
				haystackLoop += needleLoop;
				needleLoop = 0;
			}
			else
				return (NULL);
		}

		if (needleLoop == size - 1)
		{
			return (&haystack[haystackLoop]);
		}
	}

	return (NULL);
}

/**
 * _strdup - a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 * @str: char pointer to copy
 *
 * Return: a new char pointer
 char *_strdup(char *str)
 {
  char *s;
	int cLoop;

	if (str == NULL)
	{
		return (NULL);
	}
  
  s = malloc(sizeof(char) * (_strlen(str) + 1));
  if (s == NULL)
  {
      return (NULL);
  }
  for (cLoop = 0; cLoop < _strlen(str) + 1; cLoop++)
	{
		s[cLoop] = str[cLoop];
	}

	return (s);
/**
 * _strspn - gets the length of a prefix substring.
 *
 * @s: string to search
 * @accept: characters to accept
 *
 * Return: a pointer to the first occurrence of the character c
 *         in the string s, or NULL if the character is not found
 */
unsigned int _strspn(char *s, char *accept)
{
	int sLoop, aLoop;

	for (sLoop = 0; s[sLoop] != '\0'; sLoop++)
	{
		for (aLoop = 0; accept[aLoop] != s[sLoop]; aLoop++)
		{
			if ('\0' == accept[aLoop])
			{
				return (sLoop);
			}
		}
	}

	return (sLoop);
}

/**
 * _strchr - locates a character in a string.
 *
 * @s: string where to search
 * @c: character to search
 *
 * Return: A pointer to the first occurence of c
 */
char *_strchr(char *s, char c)
{
	while (*s >= '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	return (NULL);
}

/**
 * _strncat - concatenates two string
 *
 * @dest: char pointer
 * @src: char pointer
 * @n: number of character
 *
 * Return: string
 */
char *_strncat(char *dest, char *src, int n)
{
	int length, d_size;

	d_size = _strlen(dest);

	for (length = 0; length < n; length++)
	{
		dest[d_size + length] = src[length];
	}

	return (dest);
}

/**
 * _strcpy - copies the string pointed to by src,
 *               including the terminating null byte (\0),
 *               to the buffer pointed to by dest
 *
 * @dest: char pointer
 * @src: char pointer
 *
 * Return: char*
 */
char *_strcpy(char *dest, char *src)
{
	int cLoop, size = _strlen(src);

	for (cLoop = 0; cLoop < size; cLoop++)
	{
		dest[cLoop] = src[cLoop];
	}

	dest[size] = '\0';

	return (dest);
}   
