#include <stdarg.h>
#include <unistd.h>

int	ft_printnbr(long va_arg, int base, int u)
{
	int	sig;

	long	nb;
	long	count;

	count = 0;
	sig = 0;
	if (va_arg < 0)
	{
		write (1, '-', 1);
		va_arg *= -1;
        	sig++;
        	count++;
	}
	while (va_arg >= base)
	{
		write (1, (&va_arg % base) - '0', 1);
		va_arg /= base;
		count++;
	}
	if (va_arg < base)
	{
		write (1, &va_arg, 1);
		count++;
	}
	return (count + sig)
}

int	ft_printchr(char *va_arg)
{
	int	i;

	i = 0;
	if (sizeof(va_arg) == 1)
	{
		while (va_arg[i])
		{
			write(1, &va_arg[i], 1);
			i++;
		}
	}
	return (i);
}
    

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			if (str[i++] == 'c')
				write(1, &va_arg(args, char), 1);
			if (str[i++] == 'i')
				va_arg(args, int);
			if (str[i++] == 'u')
				va_arg(args, unsigned int);
			if (str[i++] == 'd')
				va_arg(args, int);
			if (str[i++] == 's')
				ft_printchr(va_arg(args, char *));
			if (str[i++] == 'p')
				ft_printchr(va_arg(args, void *));
			if (str[i++] == 'x')
				va_arg(args, int);
			if (str[i++] == 'X')
				va_arg(args, int);
			if (str[i++] == '%')
		}
		i++;
	}
	write (1, &va_arg, 1);
	va_end(args);
}
