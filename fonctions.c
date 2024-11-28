#include "main.h"

int handle_negative(int num, char *buffer, int *len)
{
    if (num < 0)
    {
        buffer[(*len)++] = '-';
        return -num;
    }
    return num;
}

int calculate_length(int num)
{
    int len = 0;
    do {
        len++;
        num /= 10;
    } while (num != 0);
    return len;
}

void convert_to_string(int num, char *buffer, int len)
{
    buffer[len] = '\0';
    while (num != 0)
    {
        buffer[--len] = (num % 10) + '0';
        num /= 10;
    }
    if (len == 1)
    {
        buffer[0] = '0';
    }
}
