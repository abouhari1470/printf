#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct Format - Struct Format
 *
 * @format: The format.
 * @function: The function associated.
 */
struct Format
{
	char format;
	int (*function)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct Format Format_t - Typedef for struct Format
 *
 * @format: The format.
 * @function: The function associated.
 */
typedef struct Format Format_t;

int my_printf(const char *format, ...);
int handle_print(const char *format, int *index,
	va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print characters and strings */
int print_character(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_integer(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int print_hexadecimal(va_list args, char map_to[],
	char buffer[], int flags, char flag_char, int width, int precision, int size);

/* Function to print non-printable characters */
int print_non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print memory address */
int print_pointer(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *index);
int get_width(const char *format, int *index, va_list args);
int get_precision(const char *format, int *index, va_list args);
int get_size(const char *format, int *index);

/* Function to print string in reverse */
int print_reverse(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print a string in ROT13 */
int print_rot13_string(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int index, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int index, char buffer[], int flags, int width, int precision,
	int length, char padding, char extra_char);
int write_pointer(char buffer[], int index, int length,
	int width, int flags, char padding, char extra_char, int padding_start);

int write_unsigned(int is_negative, int index,
	char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char c);
int append_hexa_code(char c, char map_to[], int index);
int is_digit(char c);

long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif /* PRINTF_H */
