/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_sharp_o_and_x.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:11:15 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/03 18:28:32 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	iszero(t_var *v, char *str, int value, char c)
{
	if (value == 0 && c == 'o')
	{
		str[0] = '0';
		v->str = str;
		v->buff = fillbuff(v);
	}
	else if (value == 0 && v->dot == 0)
	{
		str[0] = '0';
		v->str = str;
		v->buff = fillbuff(v);
	}
	else if (value == 0 && v->dot != 0)
	{
		v->str = str;
		v->buff = fillbuff(v);
	}
}

void	percent_sharp_o(unsigned int value, t_var *v)
{
	char	*str;
	int		i;
	int		tmp;

	str = ft_strnew(mbase_eight(value) + 1);
	if (value == 0)
	{
		iszero(v, str, value, 'o');
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

void	hexa_up_sharp(unsigned int value, t_var *v)
{
	char	*str;
	int		i;
	int		tmp;

	str = ft_strnew(msize_hexa_int(value) + 1);
	if (value == 0)
	{
		iszero(v, str, value, 'X');
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
	v->str = ft_strrev(str);
	pr_or_wd_sharp(v, 'X');
}

void	hexa_low_sharp(unsigned int value, t_var *v)
{
	char	*str;
	int		i;
	int		tmp;

	str = ft_strnew(msize_hexa_int(value) + 1);
	if (value == 0)
	{
		iszero(v, str, value, 'x');
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
	v->str = ft_strrev(str);
	pr_or_wd_sharp(v, 'x');
}
