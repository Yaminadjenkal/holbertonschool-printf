#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int print_decimal(va_list args)
{
    int num = va_arg(args, int);
    char buffer[20];
    int count = 0;

    if (num == 0)
    {
        buffer[count++] = '0';
    }
    else
    {
        int temp = num, len = 0;
        while (temp != 0)
        {
            len++;
            temp /= 10;
        }

        for (int i = len - 1; i >= 0; i--)
        {
            buffer[i] = (num % 10) + '0';
            num /= 10;
        }

        count = len;
    }

    write(1, buffer, count);
    return count;
}
