#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * string_print - a function for string
 *
 * @in: a pointer var for string
 *
 * Return: the string with it's length
 */

int string_print(char *str)
{
	int length;

	for (; *s; s++)
	{
		length = length + write(1, str, 1);
	}
	return(length);
}
