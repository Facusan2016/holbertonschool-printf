# _____printf
## content
1. [Description](#Description)
2. [Flowchart](#Flow)
3. [Locations and use of functions](#Func)
4. [Directives](#Direct)
5. [Special characters](#spchar)
6. [Example](#Examp)
7. [Authors](#Auth)
	---
## Description <a name=Description><a>
This function should be used to print content, mainly text, in the standard output, with the possibility with the addition of certain directives, (using %), wich will allow the printing of different kind of variables, like ints, strings, characters, etc.

We opted for the use of function pointers considering that it is the most efficient way of executing the different functionalities. 

Approaching the project this way we consider to have the chance of making it more scalable, being able to later add functionalities.

## Directives <a name=Direct><a>
Combination|Use
---|---
%s | Prints a string.
%c | Prints a character.
%% | Prints the "%" character.
%d | Prints a decimal number.
%i | Prints an integer.
%b | Prints an unsigned int on binary base.
%u | Prints an unsigned int.
%o | Prints an unsigned int on octal base.
%x | Prints an unsigned int in lowercase hexadecimal base.
%X | Prints an unsigned int in lowercase hexadecimal base.
%S | Prints a string with the non printable characters represented with \x and the ascii value of the char.
%r | Prints a reversed string.
%R | Prints a Rot13'ed string.
%'\0' | Prints until it encounters this and returns -1.
%(unkown) | Prints the "%" character and the following one.

## Flowchart (Functions explained) <a name=Flow><a>

You can see the flowchart in [here](https://miro.com/app/board/uXjVM1hBo4g=/).

## Locations and use of functions <a name=Func><a>

### _printf: 

_printf: initializes the arguments of the variadic function and the i (amount of chars printed), then calls printformat. (Called by command).

printformat: (prints the format and calls functions depending on the character). (Called by _printf()).

### get_prints: 

select_func: depending on the character passed selects a function to execute. (Called by printformat).

### basic_printings:

print_sp: prints special characters that are preceded by a “\”. (Called by select_func). 

print_string: prints a string. (Called by select_func).

print_char: prints a character. (Called by select_func).

print_percent: prints a “%” sign. (Called by select_func).

print_percent_car: prints a “%” sign followed by the following character in the format. (Called by select_func).

### num_printings:

itoa: transforms an integer into a string. (Called by print num).

itob: transforms an integer into it´s binary value. (Called by print_binary).

print_num: prints a number after transforming it to string by using itoa. (Called by select_func).

print_binary: calls the itob function to print binary.

### more_num_printings:

print_buffer: prints the content of the buffer. (Called by print_unsigned, print_octal, print_up_hex, print_low_hex).

print_unsigned: prints an unsigned int by putting  it into the buffer and calling print_buffer.(Called by get_prints).

print_octal: prints an int in octal format by putting  it into the buffer and calling print_buffer.(Called by get_prints).

print_up_hex: prints an int in hexadecimal format by putting  it into the buffer and calling print_buffer.(Called by get_prints).

print_low_hex: prints an int in uppercase hexadecimal format by putting  it into the buffer and calling print_buffer.(Called by get_prints).

### special_printings:

print_str_noprint: Prints a string with the non printable characters represented with \x and the ascii value of the char. (Called by get_prints).

print_rev_str: Prints a reversed string.(Called by get_prints).

print_rot13: Prints a Rot13'ed string.(Called by get_prints).

## Special characters <a name=spchar><a>
Combination|Use
---|---
\\\\ | Prints \\.
\\" | Prints ".
\\' | Prints the "%" character.
\\% | Prints a decimal number.
\\a | Prints an integer.
\\b | Prints an unsigned int on binary base.
\\f | Prints an unsigned int.
\\n | Prints an unsigned int on octal base.
\\r | Prints an unsigned int in lowercase hexadecimal base.
\\t | Prints an unsigned int in lowercase hexadecimal base.
\\v | Prints until it encounters this and returns -1.
	
## Example <a name=Examp><a>
```c
#include "main.h"
/**
  * struct student_grade - Student object
  * @name: Name of the student.
  * @surname: Surname of the student.
  * @day: Day corrected.
  * @month: Month corrected.
  * @grade: Grade of the student.
  *
  * Description: Longer description
  */

	typedef struct student_grade
{
	char *name;
	char *surname;
	int day;
	int month;
	char grade;						
} student_grade;

/**
 * print_all - Prints all the data.
 * @data: Array with the students data.
 * @size: Amount of students.
 * Return: Nothing.
 */

int print_all(student_grade data[], int size)
{
	int i = 0;
	int total = 0;

	while(i < size)
	{
		total += _printf("%s %s:\n", data[i].name, data[i].surname);
		total += _printf("\tGrade: %c\n", data[i].grade);
		total += _printf("\tCorrected on: %d/%i\n", data[i].day, data[i].month);
		total += _printf("\n");
		i++;
	}
	return (total);
}

/**
 * main - Main Function.
 * Return: The amount of characters printed.
 */

int main(void)
{
	int i;

	student_grade data[3] = {
		{"Juan", "Sierra", 16, 10, 'b'},
		{"Carlos", "Galzerano", 24, 02, 'a'},
		{"Jose", "Rodriguez", 11, 05, 'f'}

	};

	i = print_all(data, 3);
	_printf("Return value: %i\n", i);
	return(0);					
}
```
## Authors <a name=Auth><a>
This project was developed by Facundo Sánchez and Facundo Villagra.
