#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
				switch (*format)
				{
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
		}
					else
					{
						putchar(*format);
						count++;
					}
						format++;

						va_end(args);
						return (count);
}
