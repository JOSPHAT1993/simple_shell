#include "shell.h"
/**
 * token_num- main function to count num of tokens created
 *
 * @str:'String variable repr string to be handle'
 *
 * Return: int Number of tokens
 */
unsigned int token_num(char *str)
{
	char *token_one;
	char sep1[] = "" "'\n''\t'";
	unsigned int i = 0;

	token_one = strtok(str, sep1);

	while (token_one)
	{
		token_one = strtok(NULL, sep1);
		i++;
	}
	return (i);
}

/**
 * split_token-main function to split string into token
 *
 * @split_str:'String variable'
 * @str:'String variable'
 * @n:'Number of token'
 *
 * Return:string tokens
 */

char **split_token(char **split_str, char *str, unsigned int n)
{
	char *token_two;
	char sep2[] = "" "'\n''\t'";
	unsigned int j = 0;

	token_two = strtok(str, sep2);

	while (j < n)
	{
		split_str[j] = _strdup(token_two);

		if (split_str[j] == NULL)
		{
			while (j > 0)
			{
				free(split_str[j]);
				j--;
			}
			free(split_str[0]);
			free(split_str);
			free(str);
			msgerr("Error in spliting tokens", 1);
		}
		token_two = strtok(NULL, sep2);
		j++;
	}
	split_str[j] = '\0';

	return (split_str);
}
/**
 * str_to_arrays-function to convert token to arrays
 *
 * @buffer_size:'Integer variable'
 *
 * Return:Arrays of tokens
 */
char **str_to_arrays(char *buffer_size)
{
	char *aux_len, *aux_split;
	char **splt_str;
	unsigned int i;

	aux_len = _strdup(buffer_size);

	if (aux_len == NULL)
	{
		msgerr("Error in allocating memmroy", 1);
	}

	aux_split = _strdup(buffer_size);
	if (aux_split == NULL)
	{
		free(aux_len);
		msgerr("Error in allocating memmroy", 1);
	}
	i = token_num(aux_len);
	aux_len = '\0';
	free(aux_len);
	splt_str = malloc((i * sizeof(char *)) + 1);
	if (splt_str == NULL)
	{
		free(aux_split);
		msgerr("Error in allocating memmroy", 1);
	}
	splt_str = split_token(splt_str, aux_split, i);
	aux_split = '\0';
	free(aux_split);

	return (splt_str);
}

