/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:01:58 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/11 11:24:55 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putchars(char c)
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

static int	putvar(char c, va_list arg)
{
	if (c == 'c')
		return (putchar(va_arg(arg, char)));
	if (c == 's')
		return (putstrs(va_arg(arg, char *)));
	if (c == 'p')
		return (puthexa(va_arg(arg, void *), 0));
	if (c == 'd' || 'i')
		return putnbrs(va_arg(arg, int));
	if (c == 'u')
		//unsigned decimal
	if (c == 'x')
		// hexa mini
	if (c == 'X')
		//exa maj
	if (c == '%')
		return (putchar('%'));
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
	if (nb > 9)
		i += putnbrs(nb / 10);
	i += putchars(nb % 10 + 48);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	psize;
	va_list	args;

	i = 0;
	va_start(args, 0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			psize += select(str[i + 1]);
			i++;
		}
		else
			psize = putchars(str[i]);
		i++;
	}
	va_end(args);
	return (psize);
}
int