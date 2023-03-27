#include "main.h"

/**
 * _printf - formats a character string using %c, %s
 * outputs to the stdout
 * @format: the character string
 * Return: returns the number of characters printed
 * (excluding '\0' )
 *
 */

int _printf(const char *format, ...)
{
	int count;
	char c, *s;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, char);
				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				while (*s != '\0')
				{
					_putchar(*s);
					s++, count++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
