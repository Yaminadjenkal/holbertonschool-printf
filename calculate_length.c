#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * calculate_length - Calcule la longueur du nombre.
 * @num: Le nombre à mesurer.
 * 
 * Return: La longueur du nombre.
 */
int calculate_length(int num)
{
	int len = 0;
	do {
		len++;
		num /= 10;
	} while (num != 0);
	return len;
}
