#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    int count = 0;
    va_list args;
    va_start(args, format);
    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    fputs(va_arg(args, char *), stdout);
                    count += strlen(va_arg(args, char *));
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar(*format);
                    count++;
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }
    va_end(args);
    return count;
}
