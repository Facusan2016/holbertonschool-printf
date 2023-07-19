#include "main.h"
#include <stdlib.h>
#include <limits.h>

/**
 * itoa - Converts int to a string.
 * @i: num to be converted.
 * @b: String where the result is saved.
 * Return: amount of characters printed.
 */

char *itoa(long int i, char b[])
{
	char const digit[] = "0123456789";

	int shifter;

	char *p = b;

	shifter = i;

	if (i < 0)
	{
		*p++ = '-';
		i = -i;
	}

	do {
		++p;
		shifter = shifter / 10;
	} while (shifter != 0);

	*p = '\0';

	do {
		*--p = digit[i % 10];
		i = i / 10;
	} while (i != 0);

	return (b);
}

/**
 * itob - transforms an int to its value in binary.
 * @num: number to be transfored.
 * Return: binary format of the int.
 */
void itob(unsigned int num, int *i)
{
	if (num < 2)
	{
		_putchar(num + '0');
		*i += 1;
	} else
	{
	itob(num / 2, i);
	_putchar((num % 2) + '0');
	*i += 1;
}
}

/**
 * print_num - Prints a number in base 10.
 * @arg: num to be printed.
 * Return: amount of characters printed.
 */

int print_num(va_list arg)
{
	char result[13];
	int i = 0;
	int num = va_arg(arg, int);

	itoa(num, result);

	while (result != NULL && result[i] != '\0')
	{
		_putchar(result[i]);
		i++;
	}

	return (i);
}

/**
 * print_binary - Prints an unsigned int in base 2.
 * @arg: num to be printed.
 * Return: amount of characters printed.
 */

int print_binary(va_list arg)
{
	int i = 0;

	itob(va_arg(arg, unsigned int), &i);
	return (i);
}
