#include "Hell.h"

/**
 * _strchr - checks string for a particular character
 * @str: string to check
 * @c: character
 * Return: Return pointer to the found character
 */

char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}

/**
 * _strlen - measures the length of a string
 * @str: string
 * Return: Return the number of characters in str
 */

int _strlen(const char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

/**
 * _strcpy - copy string from source to destination
 * @dest: destination
 * @src: source
 * Return: Return pointer to the beginning of the destination string
 */

char *_strcpy(char *dest, const char *src)
{
	char *start = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (start);
}

/**
 * _strconcat - concatenate strings
 * @prefix:prefix
 * @suffix: suffix
 * Return: Return pointer to the new string
 */

char *_strconcat(const char *prefix, const char *suffix)
{
	int prefix_len = _strlen(prefix);
	int suffix_len = _strlen(suffix);
	char *result = malloc(prefix_len + suffix_len + 1);

	if (!result)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	_strcpy(result, prefix);  /*  Copy prefix to result */
	_strcpy(result + prefix_len, suffix);
	return (result);
}
