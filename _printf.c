#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
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

        for (; *str; str++)
        {
                length = length + write(1, str, 1);
        }
        return(length);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

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
			format++;
			if (*format == '\0')
			{
				pr_chr = pr_chr + write(1, "%", 1);
			}
			else
			{
				 switch (*format)
				 {
					 case 'c':
						 pr_chr = pr_chr + _putchar(va_arg(arg_list, int));
						 break;
					 case 's':
						 pr_chr = pr_chr + string_print(va_arg(arg_list, char *));
						 break;
					 default:
						 pr_chr = pr_chr + write(1, format, 1);
				 }
			}
		}
		else
		{
			pr_chr = pr_chr + write(1, format, 1);
		}
		format++;
	}
	va_end(arg_list);
	return (pr_chr);
}
