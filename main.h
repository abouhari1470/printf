#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

struct Format
{
    char format;
    int (*function)(va_list, char[], int, int, int, int);
};

#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *format, ...);

int my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    
    int count = 0;
    const char *p = format;
    
    while (*p != '\0') {
        if (*p == '%') {
            p++;
            if (*p == '\0') {
                break;
            }
            switch (*p) {
                case 'c':
                    count += printf("%c", va_arg(args, int));
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case 'd':
                    count += printf("%d", va_arg(args, int));
                    break;
                case 'x':
                    count += printf("%x", va_arg(args, int));
                    break;
                default:
                    count += printf("%c", *p);
                    break;
            }
        } else {
            count += printf("%c", *p);
        }
        p++;
    }
    
    va_end(args);
    
    return count;
}
