#include "main.h"
#include <stdio.h> /* Include stdio.h for snprintf */

/**
 * _printf - Implémentation personnalisée de la fonction printf
 * @format: La chaîne de format
 *
 * Retour: Le nombre de caractères imprimés
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    const char *ptr;

    va_start(args, format);
    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%')
        {
            ptr++;
            if (*ptr == 'c')
            {
                char c = (char)va_arg(args, int);
                count += write(1, &c, 1);
            }
            else if (*ptr == 's')
            {
                char *str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    count += write(1, str, 1);
                    str++;
                }
            }
            else if (*ptr == 'd' || *ptr == 'i')
            {
                int num = va_arg(args, int);
                char buf[12];
                int len = snprintf(buf, sizeof(buf), "%d", num);
                count += write(1, buf, len);
            }
            else if (*ptr == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);
                char buf[12];
                int len = snprintf(buf, sizeof(buf), "%u", num);
                count += write(1, buf, len);
            }
            else if (*ptr == 'o')
            {
                unsigned int num = va_arg(args, unsigned int);
                char buf[12];
                int len = snprintf(buf, sizeof(buf), "%o", num);
                count += write(1, buf, len);
            }
            else if (*ptr == 'x' || *ptr == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                char buf[12];
                int len = snprintf(buf, sizeof(buf), (*ptr == 'x' ? "%x" : "%X"), num);
                count += write(1, buf, len);
            }
            else if (*ptr == 'p')
            {
                void *addr = va_arg(args, void *);
                char buf[18];
                int len = snprintf(buf, sizeof(buf), "%p", addr);
                count += write(1, buf, len);
            }
            else if (*ptr == '%')
            {
                count += write(1, "%", 1);
            }
            else
            {
                count += write(1, ptr, 1);
            }
        }
        else
        {
            count += write(1, ptr, 1);
        }
    }
    va_end(args); /* Corrected line */
    return count;
}

