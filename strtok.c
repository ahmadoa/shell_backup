#include "main.h"
/**
 * sim - checks if a char matches another
 * @c: character
 * @s: string
 * Return: 1 if it successeds, 0 if it fails
 */
unsigned int sim(char c, const char *s)
{
	unsigned int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (c == s[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - parse a string to tokens
 * @s: string
 * @delim: delimiter/ seperator
 * Return: NULL if it fails, or next token
 */
char *_strtok(char *s, const char *delim)
{
	static char *first_tok, *second_tok;
	unsigned int i;

	if (str != NULL)
		second_tok = str;
	first_tok = second_tok;
	if (ts == NULL)
		return (NULL);
	for (i = 0; first_tok[i] != '\0'; i++)
	{
		if (sim(first_tok[i], delim) == 0)
			break;
	}
	if (second_tok[i] == '\0' || second_tok[i] == '#')
	{
		second_tok = NULL;
		return (NULL);
	}
	first_tok = second_tok + i;
	second_tok = first_tok;
	for (i = 0; second_tok[i] != '\0'; i++)
	{
		if (sim(second_tok[i], delim) == 1)
			break;
	}
	if (second_tok[i] == '\0')
		second_tok = NULL;
	else
	{
		second_tok[i] = '\0';
		second_tok = second_tok + i + 1;
		if (*second_tok == '\0')
			second_tok = NULL;
	}
	return (ts);
}