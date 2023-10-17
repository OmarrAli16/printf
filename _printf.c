#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - a function for printing
 *
 * @format: strrr
 *
 * Return: the number of char printed
 */

int _printf(const char *format, ...)
{
	va_list arg_list;
	int pr_chr = 0;

	va_start(arg_list, format);
	while (*format)
	{
		if (*format == '%')
		{
			pr_chr = pr_chr + spec_print(*++format, arg_list);
		}
		else
		{
			pr_chr = pr_chr + write(STDOUT_FILENO, "%", 1);
			++format;
		}
	}
	va_end(arg_list);
	return (pr_chr);
}
