/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_sharp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:57:50 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/05 14:25:39 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	percent_sharp(const char *str, va_list ap, t_var *v)
{
	if (str[v->i + 1] == '#')
	{
		while (str[v->i + 1] == '#')
			++v->i;
		if (str[v->i + 1] == '.')
			percent_dot(str, v);
		if (str[v->i + 1] == 'o')
		{
			percent_sharp_o(va_arg(ap, unsigned int), v);
			v->j = v->i + 2;
		}
		if (str[v->i + 1] == 'x')
		{
			hexa_low_sharp(va_arg(ap, unsigned int), v);
			v->j = v->i + 2;
		}
		if (str[v->i + 1] == 'X')
		{
			hexa_up_sharp(va_arg(ap, unsigned int), v);
			v->j = v->i + 2;
		}
	}
	return (v->j);
}
