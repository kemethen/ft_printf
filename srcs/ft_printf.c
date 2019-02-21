/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:03:20 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/21 17:43:39 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t	check3(const char *str, va_list ap, size_t i, size_t j)
{
	if (str[i + 1] == 'x')
	{
		hexa_low(va_arg(ap, unsigned int));
		j = i + 2;
	}
	if (str[i + 1] == 'X')
	{
		hexa_up(va_arg(ap, unsigned int));
		j = i + 2;
	}
	if (str[i + 1] == 'h')
		j = percent_h(str, ap, i, j);
	j = percent_l(str, ap, i, j);
	return (j);
}

size_t	check2(const char *str, va_list ap, size_t i, size_t j)
{
	if (str[i + 1] == 'p')
	{
		percent_p(ap);
		j = i + 2;
	}
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
	{
		ft_putnbr(va_arg(ap, int));
		j = i + 2;
	}
	if (str[i + 1] == 'o')
	{
		percent_o(va_arg(ap, unsigned int));
		j = i + 2;
	}
	if (str[i + 1] == 'u')
	{
		ft_putnbru(va_arg(ap, unsigned int));
		j = i + 2;
	}
	j = check3(str, ap, i, j);
	return (j);
}

void	check(const char *str, va_list ap, t_var *v)
{
	while (str[v->i] != '\0')
	{
		while (str[v->i] != '%' && str[v->i] != '\0')
			++v->i;
		if (str[v->i + 1] == '%')
			v->i += 2;
		v->str = ft_strsub(str, v->j, v->i - v->j);
		ft_putstr(v->str);
		free(v->str);
		if (str[v->i + 1] == 'c')
		{
			ft_putchar((char)va_arg(ap, int));
			v->j = v->i + 2;
		}
		if (str[v->i + 1] == 's')
		{
			ft_putstr(va_arg(ap, char *));
			v->j = v->i + 2;
		}
		v->j = check2(str, ap, v->i, v->j);
		++v->i;
	}
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	t_var	*v;

	if (!(v = (t_var *)malloc(sizeof(t_var))))
		return (-1);
	ft_bzero(v, sizeof(t_var));
	va_start(ap, str);
	check(str, ap, v);
	va_end(ap);
	free(v);
	return (0);
}

int		main(void)
{
	char			*s;
	double i;
	i = 10000000000;
	s = ft_strdup("salut la mifa slt ca va ou quoi les bros");
	printf("Le vrai PRINTF : Le pourcentage b = %g\n", i);
	ft_printf("Mon PRINTF :     Le pourcentage d = %d\n");
	free(s);
	return (0);
}
