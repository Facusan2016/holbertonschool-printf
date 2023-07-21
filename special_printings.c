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
