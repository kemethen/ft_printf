/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_sharp_lo_and_lx.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:33:50 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/11 16:05:43 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_sharp_lo(long long value, t_var *v)
{
	int		i;
	int		tmp;

	v->tmp = ft_strnew(mbase_eight(value));
	if (value == 0)
	{
		v->tmp[0] = '0';
		v->str = v->tmp;
		pr_or_wd(v);
		return ;
	}
	i = 0;
	while (value != 0)
	{
		tmp = value % 8;
		if (tmp < 10)
			v->tmp[i] = tmp + 48;
		else
			v->tmp[i] = tmp + 87;
		i++;
		value /= 8;
	}
	v->str = ft_strjoin("0", ft_strrev(v->tmp));
	ft_memdel((void **)&v->tmp);
	pr_or_wd(v);
}

void	hexa_up_lsharp(long long value, t_var *v)
{
	int		i;
	int		tmp;

	v->tmp = ft_strnew(msize_hexa_int(value));
	if (value == 0)
	{
		v->tmp[0] = '0';
		v->str = v->tmp;
		pr_or_wd_sharp(v, 'X');
		return ;
	}
	i = 0;
	while (value != 0)
	{
		tmp = value % 16;
		if (tmp < 10)
			v->tmp[i] = tmp + 48;
		else
			v->tmp[i] = tmp + 55;
		++i;
		value /= 16;
	}
	v->str = ft_strdup(ft_strrev(v->tmp));
	ft_memdel((void **)&v->tmp);
	pr_or_wd_sharp(v, 'X');
}

void	hexa_low_lsharp(long long value, t_var *v)
{
	int		i;
	int		tmp;

	v->tmp = ft_strnew(msize_hexa_int(value));
	if (value == 0)
	{
		v->tmp[0] = '0';
		v->str = v->tmp;
		pr_or_wd_sharp(v, 'x');
		return ;
	}
	i = 0;
	while (value != 0)
	{
		tmp = value % 16;
		if (tmp < 10)
			v->tmp[i] = tmp + 48;
		else
			v->tmp[i] = tmp + 87;
		++i;
		value /= 16;
	}
	v->str = ft_strdup(ft_strrev(v->tmp));
	ft_memdel((void **)&v->tmp);
	pr_or_wd_sharp(v, 'x');
}
