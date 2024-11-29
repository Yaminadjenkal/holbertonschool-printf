#include "main.h"
#include <stdio.h>

int main(void)
{
    int len;

    len = _printf("Let's try to printf a simple sentence.\n");
    printf("Length: %d\n", len);

    len = _printf("Number (%%d): %d\n", -12345);
    printf("Length: %d\n", len);

    len = _printf("Number (%%i): %i\n", 67890);
    printf("Length: %d\n", len);

    len = _printf("Unknown:[%r]\n", "reverse this string");
    printf("Length: %d\n", len);

    return 0;
}
