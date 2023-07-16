#include "main.h"
#include <stdlib.h>

/**
 * print_sp - Prints the special characters
 * @c: special caracter to be printed (preceded by a \);
 * Return: (1)
 */

int print_sp(char c)
{
	sp_char_t valid_char[] = {
		{'\\', '\\'},
		{'"', '"'},
		{'\'', '\''},
		{'%', '%'},
		{'a', '\a'},
		{'b', '\b'},
		{'f', '\f'},
		{'n', '\n'},
		{'r', '\r'},
		{'t', '\t'},
		{'v', '\v'}
	};

	int i = 0;

	while (i <= 11)
	{
		if (c == valid_char[i].c1)
		{
			_putchar(valid_char[i].c2);
			break;
		}
		i++;

	}

	if (i == 12)
		_putchar(c);

	return (1);
}


/**
 * print_string - Prints a string.
 * @arg: String to be printed.
 * Return: Lenght
 */

int print_string(va_list arg)
{
	int i = 0;
	char *str = va_arg(arg, char *);

	while (str != NULL && str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * print_char - Prints a char.
 * @arg: char to be printed.
 * Return: 1 (because is a char).
 */

int print_char(va_list arg)
{
	_putchar(va_arg(arg, int));
	return (1);
}

/**
 * print_percent - Prints a '%'.
 * @arg: Must be a char.
 * Return: 1 (because is a char).
 */

int print_percent(va_list arg)
{
	(void) arg;
	_putchar('%');
	return (1);
}
