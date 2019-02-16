/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:03:20 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/16 19:43:19 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	check2(const char *str, va_list ap, size_t i, size_t j)
{
	if (str[i + 1] == 'p')
	{
		ft_putstr(ft_strsub(str, i, i - j));
		percent_p(ap);
		j = i;
	}
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
	{
		ft_putstr(ft_strsub(str, i, i - j));
		ft_putnbr(va_arg(ap, int));
		j = i;
	}
	if (str[i + 1] == 'o')
	{
		ft_putstr(ft_strsub(str, i, i - j));
		percent_o(ap);
		j = i;
	}
	if (str[i + 1] == 'u')
	{
		ft_putstr(ft_strsub(str, i, i - j));
		ft_putnbru(va_arg(ap, unsigned int));
		j = i;
	}
}

void	check(const char *str, va_list ap)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
			{
				ft_putstr(ft_strsub(str, j, i - j));
				ft_putchar((char)va_arg(ap, int));
				j = i;
			}
			if (str[i + 1] == 's')
			{
				ft_putstr(ft_strsub(str, j, i - j));
				ft_putstr(va_arg(ap, char *));
				j = i;
			}
			check2(str, ap, i, j);
		}
		++i;
	}
}

int		ft_printf(const char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	check(str, ap);
	va_end(ap);
	return (0);
}

int		main(void)
{
	char		a;
	char		*s;
	char		*s2;
	unsigned	i;

	i = -33;
	a = 'z';
	s = ft_strdup("\nBonjour messieurs ceci est un test\n");
	s2 = ft_strdup("Ceci est un autre test");
	printf("Le vrai PRINTF : Le pourcentage u = %u\n", i);
	ft_printf("Mon printf : Le pourcentage u = %u\n", i);
	return (0);
}
