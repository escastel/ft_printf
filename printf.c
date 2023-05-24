/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:16:16 by escastel          #+#    #+#             */
/*   Updated: 2023/05/24 17:24:36 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

static int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int	ft_puthexa(unsigned long long nb, char c)
{
	char	hexa;
	int		count;

	if (nb < 16)
	{
		if (c == 'X')
			ft_putchar("0123456789ABCDEF"[nb % 16]);
			count++;
		if (c == 'x')
			ft_putchar("0123456789abcdef"[nb % 16]);
			count++;
	}
	else
		ft_puthexa(nb / 16);
	return (count);
}

static	int	ft_putptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	count += ft_putchar("0x");
	count += ft_puthexa(ptr, 'x');
	return (count);
}

static int	ft_count_nb(int nb)
{
	int	count;

	count = 1;
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static int	ft_putnbr(int nb)
{
	int	count;

	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
		count = 1;
	}
	if (nb >= 0 && nb <= 9)
	{
		nb += '0';
		write(1, &nb, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (ft_count_nb(nb) + count);
}

static int	ft_putunsignbr(unsigned int nb)
{
	if (nb >= 0 && nb <= 9)
	{
		nb += '0';
		write(1, &nb, 1);
	}
	else
	{
		ft_putunsignbr(nb / 10);
		ft_putunsignbr(nb % 10);
	}
	return (ft_count_nb(nb));
}

static int	t_filter(char const *str, int i, va_list	*args)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_putchar(va_arg(*args, int));
	if (str[i] == 's')
		count += ft_putstr(va_arg(*args, char *));
	if (str[i] == 'p')
		count += ft_putptr(va_arg(*args, void *));
	if (str[i] == 'd')
		count += ft_putnbr(va_arg(*args, int));
	if (str[i] == 'i')
		count += ft_putnbr(va_arg(*args, int));
	if (str[i] == 'u')
		count += ft_putunsignbr(va_arg(*args, unsigned int));
	if (str[i] == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_filter(str, i, &args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	char	d;
	char	*i;

	d = 'a';
	i = &d;
	ft_printf("%p", i);
	return (0);
}
