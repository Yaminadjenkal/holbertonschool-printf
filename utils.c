#include <unistd.h>
#include "holberton.h"

int _putchar(char c) {
    return write(1, &c, 1);
}

int print_number(int n) {
    int printed_chars = 0;
    unsigned int num = n;

    if (n < 0) {
        _putchar('-');
        printed_chars++;
        num = -n;
    }

    if (num / 10) {
        printed_chars += print_number(num / 10);
    }

    _putchar((num % 10) + '0');
    printed_chars++;

    return printed_chars;
}

int print_unsigned(unsigned int n) {
    int printed_chars = 0;

    if (n / 10) {
        printed_chars += print_unsigned(n / 10);
    }

    _putchar((n % 10) + '0');
    printed_chars++;

    return printed_chars;
}

int print_octal(unsigned int n) {
    int printed_chars = 0;

    if (n / 8) {
        printed_chars += print_octal(n / 8);
    }

    _putchar((n % 8) + '0');
    printed_chars++;

    return printed_chars;
}

int print_hex(unsigned int n, int uppercase) {
    int printed_chars = 0;
    char *hex_digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n / 16) {
        printed_chars += print_hex(n / 16, uppercase);
    }

    _putchar(hex_digits[n % 16]);
    printed_chars++;

    return printed_chars;
}

int print_pointer(void *ptr) {
    int printed_chars = 0;
    unsigned long addr = (unsigned long)ptr;

    printed_chars += _printf("0x");
    if (addr / 16) {
        printed_chars += print_hex(addr, 0);
    } else {
        printed_chars += _printf("0");
    }
    printed_chars += print_hex(addr, 0);

    return printed_chars;
}

