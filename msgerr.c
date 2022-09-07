#include "shell.h"
/**
 * msgerr-main function to print error
 *
 * @str:'String variable for error'
 * @n:'Integer variable for exit value'
 */
void msgerr(const char *str, int n)
{
	perror(str);
	exit(n);
}
