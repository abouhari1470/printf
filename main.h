#include <stdio.h>  // Including the standard input-output header file for functions like printf.
#include <stdarg.h> // Including the standard argument header file for handling variable arguments.

/**
 * Custom printf function that handles the conversion specifiers 'c', 's', and '%'.
 *
 * @param format: A character string representing the format of the output.
 * @param ...: Variable number of arguments to be formatted and printed.
 * @return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char* format, ...) {
    va_list args;  // Variable argument list.
    va_start(args, format);  // Initializing the argument list.

    int count = 0;  // Counter for the number of characters printed.

    while (*format != '\0') {
        if (*format == '%') {
            format++;  // Move to the next character after '%'.

            if (*format == 'c') {
                // Print a single character.
                int c = va_arg(args, int);
                putchar(c);
                count++;
            } else if (*format == 's') {
                // Print a string.
                char* s = va_arg(args, char*);
                while (*s != '\0') {
                    putchar(*s);
                    s++;
                    count++;
                }
            } else if (*format == '%') {
                // Print a '%' character.
                putchar('%');
                count++;
            }
        } else {
            // Print any other character.
            putchar(*format);
            count++;
        }

        format++;  // Move to the next character in the format string.
    }

    va_end(args);  // Clean up the argument list.

    return count;  // Return the number of characters printed.
}

// Usage example for _printf

int main() {
    int count = _printf("Hello, %s! Today is %c.\n", "ALX", 'M');
    printf("Number of characters printed: %d\n", count);

    return 0;
}
