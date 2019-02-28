/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:50:55 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/27 18:07:14 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	percent_lx(char const *str, va_list ap, size_t i, size_t j)
{
	if (str[i + 2] == 'x')
	{
		hexa_low_ul(va_arg(ap, unsigned long));
		j = i + 3;
	}
	if (str[i + 2] == 'X')
	{
		hexa_up_ul(va_arg(ap, unsigned long));
		j = i + 3;
	}
	return (j);
}

size_t	percent_l(char const *str, va_list ap, t_var *v)
{
	if (str[v->i + 1] == 'l')
	{
		if (str[v->i + 2] == 'l')
			++v->i;
		if (str[v->i + 2] == 'd' || str[v->i + 2] == 'i')
		{
			ft_putnbrl(va_arg(ap, long int));
			v->j = v->i + 3;
		}
		if (str[v->i + 2] == 'o')
		{
			percent_o(va_arg(ap, unsigned long), v);
			v->j = v->i + 3;
		}
		if (str[v->i + 2] == 'u')
		{
			ft_putnbrul(va_arg(ap, unsigned long));
			v->j = v->i + 3;
		}
		v->j = percent_lx(str, ap, v->i, v->j);
	}
	return (v->j);
}
