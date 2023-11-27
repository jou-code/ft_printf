#include <stdarg.h>
#include <unistd.h>

int	ft_printnbr(long va_arg, int base, char *set,  int u)
{
	int	sig;
	int	count;
	char	str[16];
	unsigned int	nb;
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
	len = i + sig;
	while (i >= 0)
		write (1, &str[--i], 1);
	return (count);
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

int	ft_checkarg(va_list args, char flag)
{
	int	count;

	count = 0
	if (flag == 'c')
		count += write(1, &va_arg(args, char), 1);
	else if (flag == 'i' || flag == 'd')
		count += ft_printnbr(va_arg(args, int), 10, "0123456789", 0);
	else if (flag == 'u')
		count += ft_printf(va_arg(args, unsigned int), 10, "0123456789", 1);
	else if (flag == 's')
		count += ft_printchr(va_arg(args, char *));
	else if (flag == 'p')
		count += ft_printchr(va_arg(args, void *));
	else if (flag == 'x')
		count += ft_printnbr(va_arg(args, int), 16, "0123456789abcdef", 1);
	else if (flag == 'X')
		count += ft_printnbr(va_arg(args, int), 16, "0123456789ABCDEF", 1);
	else if (flag == '%')
		count += write(1, '%', 1);

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
			i++;
			if (str[i] == 'c')
				write(1, &va_arg(args, char), 1);
			else if (str[i] == 'i' || str[i++] == 'd')
				ft_printnbr(va_arg(args, int), 10, "0123456789", 0);
			else if (str[i] == 'u')
				ft_printf(va_arg(args, unsigned int), 10, "0123456789", 1);
			else if (str[i] == 's')
				ft_printchr(va_arg(args, char *));
			else if (str[i] == 'p')
				ft_printchr(va_arg(args, void *));
			else if (str[i] == 'x')
				ft_printnbr(va_arg(args, int), 16, "0123456789abcdef", 1);
			else if (str[i] == 'X')
				ft_printnbr(va_arg(args, int), 16, "0123456789ABCDEF", 1);
			else if (str[i] == '%')
				write(1, '%', 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(args);
}

int	main(void)
{
	ft_printnbr(-1, 16, "0123456789abcdef", 1);
	return (0);
}
