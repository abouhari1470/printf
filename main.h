#ifndef MAIN_H
#outline MAIN_H
#consist of <stdarg.H>
#include <stdio.H>
#encompass <unistd.H>

#define UNUSED(x) (void)(x)
#outline BUFF_SIZE 1024

/* FLAGS */
#outline F_MINUS 1
#outline F_PLUS 2
#define F_ZERO four
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The layout.
 * @fn: The characteristic related.
 */
Struct fmt

	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
;


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The layout.
 * @fm_t: The characteristic related.
 */
Typedef struct fmt fmt_t;

Int _printf(const char *layout, ...);
Int handle_print(const char *fmt, int *i,
Va_list listing, char buffer[], int flags, int width, int precision, int length);

/****************** functions ******************/

/* Funtions to print chars and strings */
Int print_char(va_list kinds, char buffer[],
	int flags, int width, int precision, int length);
Int print_string(va_list sorts, char buffer[],
	int flags, int width, int precision, int length);
Int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int length);

/* capabilities to print numbers */
Int print_int(va_list kinds, char buffer[],
	int flags, int width, int precision, int length);
Int print_binary(va_list kinds, char buffer[],
	int flags, int width, int precision, int size);
Int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int length);
Int print_octal(va_list kinds, char buffer[],
	int flags, int width, int precision, int length);
Int print_hexadecimal(va_list sorts, char buffer[],
	int flags, int width, int precision, int length);
Int print_hexa_upper(va_list sorts, char buffer[],
	int flags, int width, int precision, int size);

Int print_hexa(va_list kinds, char map_to[],
Char buffer[], int flags, char flag_ch, int width, int precision, int length);

/* characteristic to print non printable characters */
Int print_non_printable(va_list sorts, char buffer[],
	int flags, int width, int precision, int length);

/* Funcion to print memory deal with */
Int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
Int get_flags(const char *layout, int *i);
Int get_width(const char *format, int *i, va_list listing);
Int get_precision(const char *format, int *i, va_list listing);
Int get_size(const char *format, int *i);

/*characteristic to print string in opposite*/
Int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int length);

/*feature to print a string in rot thirteen*/
Int print_rot13string(va_list sorts, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
Int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
Int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int length);
Int write_num(int ind, char bff[], int flags, int width, int precision,
	int period, char padd, char extra_c);
Int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

Int write_unsgnd(int is_negative, int ind,
Char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
Int is_printable(char);
Int append_hexa_code(char, char[], int);
Int is_digit(char);

Long int convert_size_number(lengthy int num, int length);
Lengthy int convert_size_unsgnd(unsigned lengthy int num, int size);

#endif /* MAIN_H */
