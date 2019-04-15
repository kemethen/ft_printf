/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:40:42 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/15 17:35:27 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	mbase_eight_us(unsigned short n)
{
	size_t	j;

	j = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 8;
		++j;
	}
	return (j);
}

void	percent_ho(va_list ap, t_var *v)
{
	char			*str;
	int				i;
	unsigned short	tmp1;
	int				tmp2;

	tmp1 = (unsigned short)va_arg(ap, int);
	tmp2 = 0;
	i = 0;
	str = ft_strnew(mbase_eight_us(tmp1));
	if (tmp1 == 0)
		str[0] = '0';
	while (tmp1 != 0)
	{
		tmp2 = tmp1 % 8;
		if (tmp2 < 10)
			str[i] = tmp2 + 48;
		else
			str[i] = tmp2 + 87;
		++i;
		tmp1 /= 8;
	}
	v->str = ft_strrev(str);
	pr_or_wd(v);
}

size_t	percent_hh(const char *str, va_list ap, t_var *v)
{
	if (str[v->i + 3] == 'd' || str[v->i + 3] == 'i')
	{
		percent_d_and_i((char)va_arg(ap, int), v);
		v->j = v->i + 4;
	}
	if (str[v->i + 3] == 'o')
	{
		percent_o((unsigned char)va_arg(ap, int), v);
		v->j = v->i + 4;
	}
	if (str[v->i + 3] == 'x')
	{
		hexa_low((unsigned char)va_arg(ap, int), v);
		v->j = v->i + 4;
	}
	if (str[v->i + 3] == 'X')
	{
		hexa_up((unsigned char)va_arg(ap, int), v);
		v->j = v->i + 4;
	}
	return (v->j);
}

size_t	percent_hx(const char *str, va_list ap, t_var *v)
{
	if (str[v->i + 2] == 'X')
	{
		hexa_up((unsigned short)va_arg(ap, int), v);
		v->j = v->i + 3;
	}
	if (str[v->i + 2] == 'h')
	{
		if (str[v->i + 3] == 'u')
		{
			percent_d_and_i((unsigned char)va_arg(ap, int), v);
			v->j = v->i + 4;
		}
		v->j = percent_hh(str, ap, v);
	}
	return (v->j);
}

size_t	percent_h(const char *str, va_list ap, t_var *v)
{
	if (str[v->i + 2] == 'd' || str[v->i + 2] == 'i')
	{
		percent_d_and_i((short)va_arg(ap, int), v);
		v->j = v->i + 3;
	}
	if (str[v->i + 2] == 'o')
	{
		percent_o((unsigned short)va_arg(ap, int), v);
		v->j = v->i + 3;
	}
	if (str[v->i + 2] == 'u')
	{
		percent_d_and_i((unsigned short)va_arg(ap, int), v);
		v->j = v->i + 3;
	}
	if (str[v->i + 2] == 'x')
	{
		hexa_low((unsigned short)va_arg(ap, int), v);
		v->j = v->i + 3;
	}
	if (str[v->i + 2] == 'U')
		percent_lu(va_arg(ap, unsigned long), v, str);
	v->j = percent_hx(str, ap, v);
	return (v->j);
}
