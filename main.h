#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdarg.h>

/**
 * struct fun_sel - This struct is used to select one of the printing functions
 * @c: This member is used for selecting the corresponding function.
 * @f: This member contains a pointer to the printing function.
 *
 * Description: This type of data was created to recreate a diccionary
 * structure, is used in func_selec function to have an easy access to the
 * function that we want to select depending of the char passed to it.
 */

typedef struct fun_sel
{
	char c;
	int (*f)(va_list arg);

} fun_sel_t;

/**
 * struct sp_char - This structure is used to have an easy accces to special
 * characters preceded by a '\' depending on a single char.
 * @c1: Contains a character.
 * @c2: Contains a special character that is a special character.
 *
 * Description: This structure is used to print the corresponding special
 * characters such as newlines, tabs, etc. Depending of the char that is
 * passed to the function, the special character that is going to be printed.
 */

typedef struct sp_char
{
	char c1;
	char c2;

} sp_char_t;

int _putchar(char c);
int printformat(const char *format, va_list arg);
int _printf(const char *format, ...);
int (*select_func(char c))(va_list);
int print_sp(char c);
int print_string(va_list arg);
int print_char(va_list arg);
int print_percent(va_list arg);
int print_percent_car(va_list arg);
int print_num(va_list arg);
int print_binary(va_list arg);
int print_unsigned(va_list arg);
int print_octal(va_list arg);
int print_up_hex(va_list arg);
int print_low_hex(va_list arg);
char *itoa(long int i, char b[]);

#endif
