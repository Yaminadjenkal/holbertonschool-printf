#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * convert_to_string - Convertit le nombre en chaîne de caractères.
 * @num: Le nombre a convertir.
 * @buffer: Le tampon pour stocker la chaîne.
 * @len: La longueur du nombre.
 */
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
