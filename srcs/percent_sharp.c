/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_sharp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:57:50 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/18 14:32:17 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	percent_sharp_hh(const char *str, va_list ap, t_var *v)
{
	if (str[v->i + 3] == 'o')
	{
		percent_sharp_o((unsigned char)va_arg(ap, unsigned int), v);
		v->j = v->i + 4;
	}
	if (str[v->i + 3] == 'x')
	{
		hexa_low_sharp((unsigned char)va_arg(ap, unsigned int), v);
		v->j = v->i + 4;
	}
	if (str[v->i + 3] == 'X')
	{
		hexa_up_sharp((unsigned char)va_arg(ap, unsigned int), v);
		v->j = v->i + 4;
	}
	return (v->j);
}

size_t	percent_sharp_h(const char *str, va_list ap, t_var *v)
{
	if (str[v->i + 2] == 'o')
	{
		percent_sharp_o((unsigned short)va_arg(ap, unsigned int), v);
		v->j = v->i + 3;
	}
	if (str[v->i + 2] == 'x')
	{
		hexa_low_sharp((unsigned short)va_arg(ap, unsigned int), v);
		v->j = v->i + 3;
	}
	if (str[v->i + 2] == 'X')
	{
		hexa_up_sharp((unsigned short)va_arg(ap, unsigned int), v);
		v->j = v->i + 3;
	}
	if (str[v->i + 2] == 'h')
		v->j = percent_sharp_hh(str, ap, v);
	return (v->j);
}

size_t	percent_sharp_l(const char *str, va_list ap, t_var *v)
{
	if (str[v->i + 2] == 'x')
	{
		hexa_low_lsharp(va_arg(ap, unsigned long), v);
		v->j = v->i + 3;
	}
	if (str[v->i + 2] == 'X')
		hexa_up_lsharp(va_arg(ap, unsigned long), v);
	return (v->i + 3);
}

size_t	percent_sharp2(const char *str, va_list ap, t_var *v)
{
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
	if (str[v->i + 1] == 'l')
	{
		if (str[v->i + 2] == 'l')
			++v->i;
		if (str[v->i + 2] == 'o')
		{
			percent_sharp_lo(va_arg(ap, unsigned long), v);
			v->j = v->i + 3;
		}
		v->j = percent_sharp_l(str, ap, v);
	}
	if (str[v->i + 1] == 'h')
		v->j = percent_sharp_h(str, ap, v);
	return (v->j);
}

size_t	percent_sharp(const char *str, va_list ap, t_var *v)
{
	if (str[v->i + 1] == '#')
	{
		while (str[v->i + 1] == '#')
			++v->i;
		if (str[v->i + 1] == '-' || str[v->i + 1] == '+')
			percent_sign(str, v);
		if (str[v->i + 1] >= 48 && str[v->i + 1] <= 57 && str[v->i] != '\0')
			percent_nbr(str, v);
		if (str[v->i + 1] == '.')
			percent_dot(str, v);
		if (str[v->i + 1] == 'o')
		{
			percent_sharp_o(va_arg(ap, unsigned int), v);
			v->j = v->i + 2;
		}
		v->j = percent_sharp2(str, ap, v);
	}
	return (v->j);
}
