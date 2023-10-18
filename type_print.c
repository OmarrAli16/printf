#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * spec_print - Print a formatted character or string
 * @in: input to analyized
 * @arg: argument
 * Return: The number of characters printed.
 */
int spec_print(char *in, va_list arg_list)
{
    int res;

    res = 0;
    switch (*in) {
        case 'c':
            res = _putchar(va_arg(arg_list, int));
            break;
        case 's':
            res = string_print(va_arg(arg_list, char *));
            break;
        default:
            res = res + write(1, in, 1);
    }

    return (res);
}
