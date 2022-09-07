#include "shell.h"

/**
 * _putchar-function to write
 *
 * @c:'Character variable'
 *
 * Return:write.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
