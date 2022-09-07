#include "shell.h"
/**
 * msg-function for message signall
 *
 * @sig:'Signal variable'
 *
 * Return:Void
 */
void msg(int sig)
{
	if (sig == SIGINT)
	{
		_putchar('\n');
		prompt();
	}
}

/**
 * process-function to create a new process
 *
 * @buffer:'String variable'
 *
 * Return:Void.
 */

void process(char *buffer)
{
	pid_t pid;
	char **str;

	str = str_to_arrays(buffer);

	pid = fork();

	if (pid == -1)
	{
		msgerr("Error creating memory", 1);
	}
	else if (pid == 0)
	{

		if (execve(str[0], str, environ) == -1)
		{
			msgerr(str[0], 1);
		}
	}
	else
	{
		wait(NULL);
		signal(SIGINT, msg);
	}
}
