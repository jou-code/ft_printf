#include <stdarg.h>
#include <unistd.h>

int	ft_printnbr(long va_arg, int base, char *set,  int u)
{
	int	sig;
	char	str[16];
	unsigned long int	nb;
	int	i;

	i = 0;
	sig = 0;
	if (va_arg < 0 && !u)
	{
		va_arg *= -1;
        	sig++;
	}
	nb = va_arg;
	while (nb != 0)
	{
		str[i++] = set[nb % base];
		nb /= base;
	}
	if (sig && !u)
		str[i++] = '-';
	str[i] = '\0';
	return (str);
}

int	ft_printchr(char *va_arg)
{
	int	i;

	i = 0;
	while (va_arg[i])
	{
		write(1, &va_arg[i], 1);
		i++;
	}
	return (i);
}

int	ft_checkspec(va_list args, char spec)
{
	int	count;
	char	c;

	if (spec == 'c')
	{
		c = va_arg(args, int);
		count = write(1, &c, 1);
	}
	else if (spec == 'i' || spec == 'd')
		count = ft_printnbr(va_arg(args, int), 10, "0123456789", 0);
	else if (spec == 'u')
		count = ft_printnbr(va_arg(args, unsigned int), 10, "0123456789", 1);
	else if (spec == 's')
		count = ft_printchr(va_arg(args, char *));
	else if (spec == 'x' || spec == 'p')
	{
		if (spec == 'p')
			count = write(1, "0x", 2);
		count += ft_printnbr(va_arg(args, int), 16, "0123456789abcdef", 1);
	}
	else if (spec == 'X')
		count = ft_printnbr(va_arg(args, int), 16, "0123456789ABCDEF", 1);
	else if (spec == '%')
		count = write(1, "%", 1);
	return (count);
}
  
int	ft_printf(const char *str, ...)
{
	int	i;
	int	count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while(str[i])
	{
		if (str[i] == '%')
			count += ft_checkspec(args, str[++i]);
		else
			write(1, &str[i], 1);
		count++;
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	ft_printf("teste int %c", 't');
	return (0);
}
