/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_lx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:54:49 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/04 16:34:56 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		msize_hexa_ul(unsigned long n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		++i;
	}
	return (i);
}

void	hexa_up_ul(unsigned long value, t_var *v)
{
	char		*str;
	int			i;
	long long	tmp;

	str = ft_strnew(msize_hexa_ul(value) + 1);
	if (value == 0)
		str[0] = '0';
	i = 0;
	while (value != 0)
	{
		tmp = value % 16;
		if (tmp < 10)
			str[i] = tmp + 48;
		else
			str[i] = tmp + 55;
		++i;
		value /= 16;
	}
	v->str = ft_strrev(str);
	v->buff = fillbuff(v);
}

void	hexa_low_ul(unsigned long value, t_var *v)
{
	char		*str;
	int			i;
	long long	tmp;

	str = ft_strnew(msize_hexa_ul(value) + 1);
	if (value == 0)
		str[0] = '0';
	i = 0;
	while (value != 0)
	{
		tmp = value % 16;
		if (tmp < 10)
			str[i] = tmp + 48;
		else
			str[i] = tmp + 87;
		++i;
		value /= 16;
	}
	v->str = ft_strrev(str);
	v->buff = fillbuff(v);
}
