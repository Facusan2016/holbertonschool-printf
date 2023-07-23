#include "main.h"
#include <stdlib.h>

/**
 *	print_str_noprint - Prints the string with the not printable characters.
 *	@arg: va_list element that contains the element to be printed.
 *	Return: Amount of characters printed.
 */

int print_str_noprint(va_list arg)
{
	int i = 0, counter = 0;
	char *str = va_arg(arg, char *);
	char c;

	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
	{

		c = str[i];

		if (((c > 0) && (c < 32)) || c >= 127)
		{
			_putchar('\\');
			_putchar('x');
			counter += 2;
			if (c < 15)
			{
				_putchar('0');
				counter++;
			}

			counter += _printf("%X", c);
			i++;

		} else
		{
			_putchar(str[i]);
			counter++;
			i++;
		}
	}

	return (counter);
}

/**
 * print_rev_str - Prints a string in reverse.
 * @arg: String to be printed.
 * Return: Amount of chars printed.
 */

int print_rev_str(va_list arg)
{
	char *rev = va_arg(arg, char *);
	int nul = 0, j = 0, i = 0, cont = 0;

	if (rev == NULL)
	{
		rev = "(null)";
		nul = 1;
	}
		while (rev[cont] != '\0')
	{
		cont++;
		i++;
	}
	i--;

	if (nul == 1)
	{
		while (rev[j] != '\0')
		{
			_putchar(rev[j]);
			j++;
		}
	} else
	{
		while (i >= 0)
		{
			_putchar(rev[i]);
			i--;
		}
	}
	return (cont);
}

/**
 * print_rot13 - prints a string
 * @arg: string to be printed
 * Return: amount of characters printed.
 */
int print_rot13(va_list arg)
{
	int i = 0, nul = 0;
	char copy, *str = va_arg(arg, char *);

	if (str == NULL)
	{
		str = "(null)";
		nul += 1;
	}
	if (nul != 1)
	{
		while (str[i] != '\0')
		{
			if ((str[i] >= 97 && str[i] <= 122) ||
				(str[i] >= 65 && str[i] <= 90))
			{
				if (str[i] > 109 || (str[i] > 77 && str[i] < 91))
				{
					copy = str[i] - 13;
				} else
					copy = str[i] + 13;
			} else
				copy = str[i];

			i++;
			_putchar(copy);
		}
	} else
	{
		i = 0;
		while (str[i] != '\0')
		{
			_putchar(str[i]);
			i++;
		}
	}
	return (i);
}
