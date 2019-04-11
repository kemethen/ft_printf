/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:05:46 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/05 13:59:51 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		msize_hexa_int(unsigned int n)
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

void	hexa_up(unsigned int value, t_var *v)
{
	char	*str;
	int		i;
	int		tmp;

	str = ft_strnew(msize_hexa_int(value) + 1);
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
	v->j = v->i + 2;
	v->str = ft_strrev(str);
	pr_or_wd(v);
}

void	hexa_low(unsigned int value, t_var *v)
{
	char	*str;
	int		i;
	int		tmp;

	str = ft_strnew(msize_hexa_int(value) + 1);
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
	v->j = v->i + 2;
	v->str = ft_strrev(str);
	pr_or_wd(v);
}
