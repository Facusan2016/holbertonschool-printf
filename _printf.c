#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * printformat - Function that recreates the behavior of printf.
 * @format: String to be passed to the function.
 * @arg: va.
 * Return: The amount of characters printed.
 */

int printformat(const char *format, va_list arg)
{
	int i = 0, total = 0;

	while (format[i] != '\0')
	{
		if(format[i] == '%' && format[i+1] == '\0')
			return (-1);

		if (format[i] == '%')
		{
			i++;
			total += select_func(format[i])(arg);

			if (select_func(format[i]) == print_percent_car)
				_putchar(format[i]);
		}	else if (format[i] == '\\')
		{
			i++;
			total += print_sp(format[i]);

		} else
		{
			_putchar(format[i]);
			total++;
		}

		i++;
	}

	return (total);
}

/**
 * _printf - Function that recreates the behavior of printf.
 * @format: String to be passed to the function.
 * Return: The amount of characters printed.
 */

int _printf(const char *format, ...)
{
	int i = 0;
	va_list arg;

	va_start(arg, format);

	if (format == NULL)
		return (-1);

	i = printformat(format, arg);
	va_end(arg);

	return (i);
}
