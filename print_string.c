#include "main.h"

int print_string(va_list args) {
    char *str = va_arg(args, char*);
    int count = 0;

    while (str && str[count]) {
        count += write(1, &str[count], 1);
    }
    return (count);
}
