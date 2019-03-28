/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_sharp_lo_and_lx.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:33:50 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/28 14:55:58 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_sharp_lo(long long value, t_var *v)
{
	char	*str;
	int		i;
	int		tmp;

	str = ft_strnew(mbase_eight(value));
	if (value == 0)
	{
		str[0] = '0';
		v->str = str;
		pr_or_wd(v);
		return ;
	}
	tmp = 0;
	i = 0;
	while (value != 0)
	{
		tmp = value % 8;
		if (tmp < 10)
			str[i] = tmp + 48;
		else
			str[i] = tmp + 87;
		i++;
		value /= 8;
	}
	v->str = ft_strjoin("0", ft_strrev(str));
	free(str);
	pr_or_wd(v);
}

void	hexa_up_lsharp(long long value, t_var *v)
{
	char	*str;
	int		i;
	int		tmp;

	str = ft_strnew(msize_hexa_int(value));
	if (value == 0)
	{
		str[0] = '0';
		v->str = str;
		pr_or_wd_sharp(v, 'X');
		return ;
	}
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
	v->str = ft_strdup(ft_strrev(str));
	free(str);
	pr_or_wd_sharp(v, 'X');
}

void	hexa_low_lsharp(long long value, t_var *v)
{
	char	*str;
	int		i;
	int		tmp;

	str = ft_strnew(msize_hexa_int(value));
	if (value == 0)
	{
		str[0] = '0';
		v->str = str;
		pr_or_wd_sharp(v, 'x');
		return ;
	}
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
	v->str = ft_strdup(ft_strrev(str));
	free(str);
	pr_or_wd_sharp(v, 'x');
}
