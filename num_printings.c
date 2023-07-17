#include "main.h"
#include <stdlib.h>

/**
 * itoa - Converts int to a string.
 * @i: num to be converted.
 * @b: String where the result is saved.
 * Return: amount of characters printed.
 */

char *itoa(int i, char b[])
{
	char const digit[] = "0123456789";

	int shifter;

	char *p = b;

	if (i < 0)
	{
		*p++ = '-';
		i *= -1;
	}

	shifter = i;

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
 * print_num - Prints a number in base 10.
 * @arg: num to be printed.
 * Return: amount of characters printed.
 */

int print_num(va_list arg)
{
	char result[11];
	int i = 0;

	itoa(va_arg(arg, int), result);

	while (result != NULL && result[i] != '\0')
	{
		_putchar(result[i]);
		i++;
	}

	return (i);
}
