#include "main.h"

int print_integer(va_list args) {
    int num = va_arg(args, int);
    char buffer[20];
    int len = 0;

    if (num == 0) {
        buffer[len++] = '0';
    } else {
        int temp = num;
        if (num < 0) {
            buffer[len++] = '-';
            temp = -temp;
        }
        int i = len;
        while (temp > 0) {
            buffer[i++] = (temp % 10) + '0';
            temp /= 10;
        }
        for (int i = len, j = i + len - 1; i < j; i++, j--) {
            char temp_char = buffer[i];
            buffer[i] = buffer[j];
            buffer[j] = temp_char;
        }
        len = i;
    }
    return write(1, buffer, len);
}
