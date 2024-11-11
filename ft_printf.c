/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:01:58 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/11 17:22:27 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putchars(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	putstrs(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		putchars(s[i]);
		i++;
	}
	return (i);
}

static int	putnbrs(int n)
{
	long	nb;
	int		i;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		i += putchars('-');
		nb = -nb;	
	}
	if (nb > 9)
		i += putnbrs(nb / 10);
	i += putchars(nb % 10 + 48);
	return (i);
}

static int	putunbrs(unsigned int n)
{
	int		i;

	i = 0;
	if (n > 9)
		i += putnbrs(n / 10);
	i += putchars(n % 10 + 48);
	return (i);
}

static int	puthexa(long nb, int ismaj)
{
	char	*hexa;
	int		i;

	i = 0;
	hexa = "0123456789abcdef";
	if (nb < 0)
	{
		i += putchars('-');
		nb = -nb;
	}
	if (nb > 15)
		i += puthexa(nb / 16, ismaj);
	if (nb / 16 == 0 && ismaj == 2)
		i += putstrs("0x");
	if (nb > 9 && ismaj == 1)
		i += putchars(hexa[nb % 16] - 32);
	else
		i += putchars(hexa[nb % 16]);
	return (i);
}

static int	putvar(char c, va_list arg)
{
	if (c == 'c')
		return (putchars(va_arg(arg, int)));
	if (c == 's')
		return (putstrs(va_arg(arg, char *)));
	if (c == 'p')
		return (puthexa((long) va_arg(arg, void *), 2));
	if (c == 'd' || c == 'i')
		return (putnbrs(va_arg(arg, int)));
	if (c == 'u')
		return (putunbrs(va_arg(arg, unsigned int)));
	if (c == 'x')
		return (puthexa((long) va_arg(arg, int), 0));
	if (c == 'X')
		return (puthexa((long) va_arg(arg, int), 1));
	if (c == '%')
		return (putchars('%'));
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		psize;
	va_list	args;

	i = 0;
	psize = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			psize += putvar(str[i + 1], args);
			i++;
		}
		else
			psize += putchars(str[i]);
		i++;
	}
	va_end(args);
	return (psize);
}

#include <stdio.h>

int	main(void)
{
	char	test;
	
	ft_printf("%d - ", ft_printf("Ceci est un test %d %p\n", 50, &test));
	printf("%d - ", printf("Ceci est un test %d %p\n", 50, &test));
}