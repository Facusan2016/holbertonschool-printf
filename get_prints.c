#include "main.h"
#include <stdlib.h>

/**
 * select_func - Function that selects the corresponding function.
 * @car: Char that is preceded by a '%'
 * Return: The corresponding function.
 */

int (*select_func(char car))(va_list)
{
	int i = 0;

	fun_sel_t ops[] = {
		{'s', print_string},
		{'c', print_char},
		{'i', print_num},
		{'d', print_num},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'X', print_up_hex},
		{'x', print_low_hex},
		{'S', print_str_noprint},
		{'r', print_rev_str},
		{'R', print_rot13},
		{'%', print_percent},
		{0, print_percent_car}
	};

	while (ops[i].c != car && ops[i].c != 0)
		i++;

	return (ops[i].f);

}
