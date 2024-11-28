#include "main.h"
#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * print_i - Fonction pour gérer le spécificate
 * @args: Une va_list contenant l'entier a imprimer
 * Description : Cette fonction récupère un entier de la va_li
 *et l'imprime. Elle gère les nombres négatifs en ajouta
 *un signe moins, et convertit l'entier en chaîne de caractèr
 *pour l'impression.
 * Return: Le nombre de caractères imprim�
 */
int print_i(va_list args)
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
