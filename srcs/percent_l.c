/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:50:55 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/21 10:36:08 by kemethen         ###   ########.fr       */
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

size_t	percent_l(char const *str, va_list ap, size_t i, size_t j)
{
	if (str[i + 1] == 'l')
	{
		if (str[i + 2] == 'l')
			++i;
		if (str[i + 2] == 'd' || str[i + 2] == 'i')
		{
			ft_putnbrl(va_arg(ap, long int));
			j = i + 3;
		}
		if (str[i + 2] == 'o')
		{
			percent_o(va_arg(ap, unsigned long));
			j = i + 3;
		}
		if (str[i + 2] == 'u')
		{
			ft_putnbrul(va_arg(ap, unsigned long));
			j = i + 3;
		}
		j = percent_lx(str, ap, i, j);
	}
	return (j);
}
