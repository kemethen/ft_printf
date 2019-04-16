/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:43:59 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/16 19:35:20 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr_or_wd_sharp(t_var *v, char c)
{
	char	*tmp3;

	if (c == 'x')
		tmp3 = ft_strdup("0x");
	else
		tmp3 = ft_strdup("0X");
	if (v->prc != 0 && v->width != 0)
		pr_and_wd_sharp(v, c);
	else if (v->prc != 0 && c == 'x')
		precision_sharp_low(v);
	else if (v->prc != 0 && c == 'X')
		precision_sharp_up(v);
	else if (v->width != 0 && c == 'x')
		width_sharp_low(v);
	else if (v->width != 0 && c == 'X')
		width_sharp_up(v);
	else
	{
		v->tmp = ft_strdup(v->str);
		ft_memdel((void **)&v->str);
		v->str = ft_strjoin(tmp3, v->tmp);
		ft_memdel((void **)&v->tmp);
		fillbuff(v);
	}
	ft_memdel((void **)&tmp3);
}

void	pr_or_wd(t_var *v)
{
	if (v->dot == 1 && v->prc == 0 && v->str[0] == '0' && v->str[1] == '\0')
	{
		ft_bzero(v->str, ft_strlen(v->str));
		if (v->width != 0)
			width(v);
		else
			ft_memdel((void **)&v->str);
	}
	else if (v->prc != 0 && v->width != 0)
		pr_and_wd(v);
	else if (v->prc != 0)
		precision(v);
	else if (v->width != 0)
		width(v);
	else
		fillbuff(v);
}

void	precision(t_var *v)
{
	v->size = 0;
	v->len = ft_strlen(v->str);
	if (v->len <= v->prc)
	{
		v->tmp = ft_strnew(v->prc - v->len + v->plus + v->neg - v->nbr);
		if (v->plus == 1 && v->neg == 0)
		{
			v->tmp[v->size++] = '+';
			v->plus = (v->zero != 0) ? 0 : 1;
		}
		while (v->size < v->prc - v->len + v->plus + v->neg - v->nbr)
			v->tmp[v->size++] = '0';
		v->tmp2 = ft_strdup(v->str);
		if (v->neg != 0)
		{
			v->tmp[0] = '-';
			ft_memdel((void **)&v->tmp2);
			v->tmp2 = ft_itoa(-ft_atoi(v->str));
		}
		ft_memdel((void **)&v->str);
		v->str = joinfree(v->tmp, v->tmp2);
	}
	else if (v->plus != 0)
		vplus(v);
	fillbuff(v);
}

void	precision_sharp_low(t_var *v)
{
	v->size = 0;
	v->len = ft_strlen(v->str);
	if (v->len < v->prc)
	{
		v->tmp = ft_strnew(v->prc - v->len);
		while (v->size < v->prc - v->len - v->zero)
			v->tmp[v->size++] = '0';
		v->tmp2 = ft_strdup(v->str);
		ft_memdel((void **)&v->str);
		v->str = joinfree(v->tmp, v->tmp2);
	}
	v->tmp = ft_strdup(v->str);
	ft_memdel((void **)&v->str);
	v->str = ft_strjoin("0x", v->tmp);
	ft_memdel((void **)&v->tmp);
	fillbuff(v);
}

void	precision_sharp_up(t_var *v)
{
	v->size = 0;
	v->len = ft_strlen(v->str);
	if (v->len < v->prc)
	{
		v->tmp = ft_strnew(v->prc - v->len);
		while (v->size < v->prc - v->len - v->zero)
			v->tmp[v->size++] = '0';
		v->tmp2 = ft_strdup(v->str);
		ft_memdel((void **)&v->str);
		v->str = joinfree(v->tmp, v->tmp2);
	}
	v->tmp = ft_strdup(v->str);
	ft_memdel((void **)&v->str);
	v->str = ft_strjoin("0X", v->tmp);
	ft_memdel((void **)&v->tmp);
	fillbuff(v);
}
