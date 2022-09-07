#include "shell.h"
/**
 * prompt-function to creating terminal prompt
 *
 * @void:'Null variable'
 *
 * Return:Void.
 */
void prompt(void)
{
	char args[] = "#cisfun$ ";
	int i = 0;

	while (args[i])
	{
		_putchar(args[i]);
		i++;
	}
}
