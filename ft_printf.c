/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:01:58 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/11 07:48:01 by rsebasti         ###   ########.fr       */
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

static int	putvar(char c, va_list arg)
{
	if (c == 'c')
		return (putchar((char) arg));
	if (c == 's')
		return (putstrs((char *) arg));
	if (c == 'p')
		//void
	if (c == 'd')
		// base decimal 10
	if (c == 'i')
		// integer
	if (c == 'u')
		//unsigned decimal
	if (c == 'x')
		// hexa mini
	if (c == 'X')
		//exa maj
	if (c == '%')
		// %
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
