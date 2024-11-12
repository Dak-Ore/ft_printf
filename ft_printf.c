/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:29:08 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/12 09:34:08 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putaddr(void *adr)
{
	int	count;

	count = 0;
	if (adr == NULL)
		return (putstrs("(nil)"));
	count += putstrs("0x");
	count += puthexa((unsigned long) adr, 0);
	return (count);
}

static int	putvar(char c, va_list arg)
{
	if (c == 'c')
		return (putchars(va_arg(arg, int)));
	if (c == 's')
		return (putstrs(va_arg(arg, char *)));
	if (c == 'p')
		return (putaddr(va_arg(arg, void *)));
	if (c == 'd' || c == 'i')
		return (putnbrs(va_arg(arg, int)));
	if (c == 'u')
		return (putunbrs(va_arg(arg, unsigned int)));
	if (c == 'x')
		return (puthexa(va_arg(arg, unsigned int), 0));
	if (c == 'X')
		return (puthexa(va_arg(arg, unsigned int), 1));
	if (c == '%')
		return (putchars('%'));
	return (0);
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

/*
#include <stdio.h>

int	main(void)
{
	long long int	t;

	t = -9223372036854775808;
	printf("%d - ", printf("Ceci est un test %p %p\n", 0, 0));
	//ft_printf("%d - ", ft_printf("Ceci est un test %x\n", t));
}*/