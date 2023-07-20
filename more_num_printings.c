#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_buffer - Prints a buffer that ends with a '\0'.
 * @buff: buff to be printed ended with an '\0'
 * Return: Nothing.
 */

void print_buffer(char buff[])
{
	int i = 0;

	while (buff[i] != '\0')
	{
		_putchar(buff[i]);
		i++;
	}
}

/**
 * print_unsigned - Prints an unsigned int.
 * @arg: Num to be printed.
 * Return: amount of characters printed.
 */

int print_unsigned(va_list arg)
{
	int i = 0;
	int j = 1;
	char *buff;
	unsigned int copia = va_arg(arg, unsigned int);
	unsigned int num = copia;

	buff = malloc(sizeof(char) * (12 + 1));

	if (buff == NULL)
		return (-1);

	while (copia >= 10)
	{
		j = j * 10;
		copia = copia / 10;
	}

	while (j >= 1)
	{
		buff[i] = (num / j) % 10 + '0';
		j = j / 10;
		i++;
	}

	buff[i] = '\0';

	print_buffer(buff);

	free(buff);
	return (i);

}


/**
 * print_octal - Prints an unsigned int.
 * @arg: num to be converted.
 * Return: amount of characters printed.
 */

int print_octal(va_list arg)
{
	int i = 0;
	int j = 1;
	char *buff;
	unsigned int copia = va_arg(arg, unsigned int);
	unsigned int num = copia;

	buff = malloc(sizeof(char) * (8 + 1));

	if (buff == NULL)
		return (-1);

	while (copia >= 8)
	{
		j = j * 8;
		copia = copia / 8;
	}

	while (j >= 1)
	{
		buff[i] = (num / j) % 8 + '0';
		j = j / 8;
		i++;
	}

	buff[i] = '\0';
	print_buffer(buff);
	free(buff);

	return (i);
}


/**
 * print_up_hex - Prints an int in hexadecimal uppercase.
 * @arg: num to be converted.
 * Return: amount of characters printed.
 */

int print_up_hex(va_list arg)
{
	int i = 0;
	int j = 1;
	char *buff;
	unsigned int copia = va_arg(arg, unsigned int);
	unsigned int num = copia;

	char *up_hex = "0123456789ABCDEF";

	buff = malloc(sizeof(char) * 16);

	if (buff == NULL)
		return (-1);

	while (copia >= 16)
	{
		j = j * 16;
		copia = copia / 16;
	}

	while (j >= 1)
	{
		buff[i] = up_hex[(num / j) % 16];
		j = j / 16;
		i++;
	}

	buff[i] = '\0';
	print_buffer(buff);
	free(buff);

	return (i);
}


/**
 * print_low_hex - Prints an int in hexadecimal lowercase.
 * @arg: num to be converted.
 * Return: amount of characters printed.
 */


int print_low_hex(va_list arg)
{
	int i = 0;
	int j = 1;
	char *buff;
	unsigned int copia = va_arg(arg, unsigned int);
	unsigned int num = copia;

	char *low_hex = "0123456789abcdef";

	buff = malloc(sizeof(char) * 16);

	if (buff == NULL)
		return (-1);

	while (copia > 16)
	{
		j = j * 16;
		copia = copia / 16;
	}

	while (j >= 1)
	{
		buff[i] = low_hex[(num / j) % 16];
		j = j / 16;
		i++;
	}

	buff[i] = '\0';
	print_buffer(buff);
	free(buff);

	return (i);
}
