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
		{'%', print_percent},
		{0, print_percent_car}
	};

	while (ops[i].c != car && ops[i].c != 0)
		i++;

	return (ops[i].f);

}
