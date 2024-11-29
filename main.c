#include "main.h"
#include <stdio.h>

int main() {
    _printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", 39, 39);
    _printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", 2147484671);
    _printf("Unsigned octal:[%o]\n", 20000001777);
    _printf("Unsigned hexadecimal:[%x, %X]\n", 0x800003ff, 0x800003FF);
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", (void*)0x7ffe637541f0);
    _printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", 12);
    _printf("Unknown:[%r]\n");
    return 0;
}

