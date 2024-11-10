/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:01:58 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/10 14:42:31 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	select(char c)
{
	if (c == 'c')
		//char
	if (c == 's')
		// s
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
	int	sum;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			sum += select(str[i + 1]);
			i++;
		}
		i++;
		sum;
	}
}