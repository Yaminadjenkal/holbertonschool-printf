#include "main.h"

/**
 * handle_negative - G�re les nombres n�gatifs.
 * @num: Le nombre a v�rifier.
 * @buffer: Le tampon pour stocker le signe négatif.
 * @len: Le compteur de longueur.
 * Description: Cette fonction vérifie si un nombre est egatif
 * Si c'est le cas, elle ajoute un signe '-'
 * au tampon et retourne la valeur absolue du nombre
 * Return: La valeur absolue du nombre.
 **/
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
 *calculate_length - Calcule la longueur du nombre.
 *@num: Le nombre mesure
 *Description: Cette fonction calcule le nombre de chiffres
 *dans un nombre entier
 *Return: La longueur du nombre.
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
 *convert_to_string - Convertit le nombre en chaine de caract�res
 *@num: Le nombre a convertir
 *@buffer: Le tampon pour stocker la chaine
 *@len: La longueur du nombre.
 *Description: Cette fonction convertit un nombre entier en une
 *chaine de caract�res et stocke le r�sultat
 *le tampon fourni.
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
