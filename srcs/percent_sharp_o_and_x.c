/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_sharp_o_and_x.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:11:15 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/18 14:33:33 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	iszero(t_var *v, char *str, char c)
{
	if (v->dot != 0 && v->prc == 0 && c != 'x')
	{
		str[0] = '0';
		v->str = str;
		fillbuff(v);
	}
	else if (v->dot != 0 && v->prc == 0 && c == 'x')
	{
		v->str = str;
		fillbuff(v);
	}
	else
	{
		str[0] = '0';
		v->str = str;
		pr_or_wd(v);
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
		iszero(v, str, 'o');
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
	char				*str;
	int					i;
	unsigned long		tmp;

	str = ft_strnew(msize_hexa_ul(value) + 1);
	if (value == 0)
	{
		iszero(v, str, 'x');
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

void	hexa_low_sharp(unsigned long value, t_var *v)
{
	char			*str;
	int				i;
	unsigned long	tmp;

	str = ft_strnew(msize_hexa_ul(value) + 1);
	if (value == 0)
	{
		iszero(v, str, 'x');
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
