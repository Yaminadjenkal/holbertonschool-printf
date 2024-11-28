#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * handle_negative - Gère les nombres négatifs.
 * @num: Le nombre à vérifier.
 * @buffer: Le tampon pour stocker le signe négatif.
 * @len: Le compteur de longueur.
 * 
 * Return: La valeur absolue du nombre.
 */
int handle_negative(int num, char *buffer, int *len)
{
	if (num < 0)
	{
		buffer[(*len)++] = '-';
		return -num;
	}
	return num;
}
