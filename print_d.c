#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * print_d - Fonction pour gérer le spécificatr
 * @args: Une va_list contenant l'entier imprimer
 *
 * Description : Cette fonction récupère un enti
 *et l'imprime. Elle gère les nombres négatifs en ajount
 *un signe moins, et convertit l'entier en chaîne de caract�es
 *pour l'impression
 *
 * Return: Le nombre de caractères imprim�
 */
int print_d(va_list args)
{
	int num = va_arg(args, int);
	char buffer[50];
	int len = 0;
	int count;
	int i;

	num = handle_negative(num, buffer, &len);
	len += calculate_length(num);
	convert_to_string(num, buffer, len);

	count = 0;
	for (i = 0; buffer[i] != '\0'; i++)
	{
		write(1, &buffer[i], 1);
		count++;
	}

	return (count);
}
