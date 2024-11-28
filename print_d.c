#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * handle_negative - Gère les nombres négatifs.
 * @num: Le nombre a  vérifier.
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
        return (-num);
    }
    return (num);
}

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
    return (len);
}

/**
 * convert_to_string - Convertit le nombre en chaîne de caractères.
 * @num: Le nombre à convertir.
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
/**
 * print_d - Fonction pour gérer le spécificateur %d.
 * @args: Une va_list contenant l'entier imprimer.
 * 
 * Description : Cette fonction récupère un entier de la va_list 
 *              et l'imprime. Elle gère les nombres négatifs en ajoutant 
 *              un signe moins, et convertit l'entier en chaîne de caractères 
 *              pour l'impression.
 * 
 * Return: Le nombre de caractères imprimés.
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
