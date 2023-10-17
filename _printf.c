#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - a function for printing
 *
 * @format:
 *
 * Return: the number of char printed
 */

int _printf(const char *format, ...)
{
	va_list arg_list;
	int pr_chr = 0;
	int i;
	int c;
	char *s;

	va_start(arg_list, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
		}
		else
		{
			break;
		}
		if (format[i] == 'c')
		{
			c = va_arg(arg_list, int);
			pr_chr = pr_chr + write(1, &c, 1);
		}
		else if (format[i] == 's')
		{

			s = va_arg(arg_list, char *);
			if (s != NULL)
			{
				while (*s)
				{
					pr_chr = pr_chr + write(1, s, 1);
					s++;
				}
			}
		}
	}
	va_end(arg_list);
	return (pr_chr);
}
