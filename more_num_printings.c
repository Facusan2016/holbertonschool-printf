#include "main.h"
#include <stdlib.h>

/**
 * print_unsigned - Prints an unsigned int.
 * @arg: num to be converted.
 * Return: amount of characters printed.
 */

int print_unsigned(va_list arg)
{
	int i = 0;
	int j = 1;
	unsigned int copia = va_arg(arg, int);
	unsigned int num = copia;

	while (copia > 10)
	{
		j = j * 10;
		copia = copia / 10;
	}

	while (j >= 1)
	{
		_putchar((num / j) % 10 + '0');
		j = j / 10;
		i++;
	}

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
	unsigned int copia = va_arg(arg, unsigned int);
	unsigned int num = copia;

	while (copia > 8)
	{
		j = j * 8;
		copia = copia / 8;
	}

	while (j >= 1)
	{
		_putchar((num / j) % 8 + '0');
		j = j / 8;
		i++;
	}

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
	unsigned int copia = va_arg(arg, unsigned int);
	unsigned int num = copia;

	int up_hex[] = {0 + '0', 1 + '0', 2 + '0', 3 + '0', 4 + '0', 5 + '0'
			 , 6 + '0', 7 + '0', 8 + '0', 9 + '0', 'A', 'B', 'C', 'D', 'E',
			'F'};

	while (copia > 16)
	{
		j = j * 16;
		copia = copia / 16;
	}

	while (j >= 1)
	{
		_putchar(up_hex[(num / j) % 16]);

		j = j / 16;
		i++;
	}

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
	unsigned int copia = va_arg(arg, unsigned int);
	unsigned int num = copia;

	int low_hex[] = {0 + '0', 1 + '0', 2 + '0', 3 + '0', 4 + '0', 5 + '0'
			 , 6 + '0', 7 + '0', 8 + '0', 9 + '0', 'a', 'b', 'c', 'd', 'e',
			'f'};

	while (copia > 16)
	{
		j = j * 16;
		copia = copia / 16;
	}

	while (j >= 1)
	{
		_putchar(low_hex[(num / j) % 16]);

		j = j / 16;
		i++;
	}

	return (i);
}
