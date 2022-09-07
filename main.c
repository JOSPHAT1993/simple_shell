#include "shell.h"
/**
 * main-entry point of the project
 *
 * @ac:'integer variable repr num of args'
 * @av:'Array variable repr array of argcs'
 *
 * Return:buffer string
 */
int main(__attribute__((unused)) int ac, __attribute__((unused)) char *av[])
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t line = 0;

	if (!isatty(0))
	{
		line = getline(&buffer, &buffer_size, stdin);
		process(buffer);
	}
	else
	{
		do {
			prompt();
			line = getline(&buffer, &buffer_size, stdin);
			if (line == EOF)
			{
				free(buffer);
				_putchar('\n');
				return (EXIT_SUCCESS);
			}
			process(buffer);
		} while (line != EOF);
	}
	return (EXIT_SUCCESS);
}

