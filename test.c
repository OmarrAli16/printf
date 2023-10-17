#include <stdio.h>
#include "main.h"

int main() {
    char *str = "Hello, world!";
    char c = 'A';

    int count = _printf("Printing a character: %c\nPrinting a string: %s\nPrinting a percent sign: %%\n", c, str);
    printf("\nTotal characters printed: %d\n", count);

    return 0;
}

