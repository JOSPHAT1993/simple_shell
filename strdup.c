#include "shell.h"
/**
 * _strdup-function to duplicate string
 *
 * @str:'string variable to be handled'
 *
 * Return:new string
 */
char *_strdup(char *str)
{
	int i, a;
	char *new_str;

	if (str == NULL)
	{
		return ('\0');
	}
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	new_str = malloc((i * sizeof(char)) + 1);

	if (new_str == NULL)
	{
		return ('\0');
	}
	for (a = 0; a < i; a++)
	{
		new_str[a] = str[a];
	}
	new_str[a] = '\0';
	return (new_str);
}
