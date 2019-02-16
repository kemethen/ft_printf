/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:03:20 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/16 16:50:48 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	check2(const char *str, va_list ap, int i)
{
	if (str[i + 1] == 'p')
		percent_p(ap);
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		ft_putnbr(va_arg(ap, int));
	if (str[i + 1] == 'o')
		percent_o(ap);
	if (str[i + 1] == 'u')
		percent_u(ap);
}

void	test(const char *str, va_list ap)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				ft_putchar((char)va_arg(ap, int));
			if (str[i + 1] == 's')
				ft_putstr(va_arg(ap, char *));
			check2(str, ap, i);
		}
		++i;
	}
}

int		ft_printf(const char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	test(str, ap);
	va_end(ap);
	return (0);
}

int		main(void)
{
	char	a;
	char	*s;
	char	*s2;
	int		i = -100;

	a = 'z';
	s = ft_strdup("\nBonjour messieurs ceci est un test\n");
	s2 = ft_strdup("Ceci est un autre test");
	printf("Le vrai PRINTF : Le pourcentage u = %o\n", i);
	ft_printf("%o\n", i);
	return (0);
}
