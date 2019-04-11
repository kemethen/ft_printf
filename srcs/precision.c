/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:43:59 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/11 18:48:21 by kemethen         ###   ########.fr       */
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
		v->buff = fillbuff(v);
	}
	ft_memdel((void **)&tmp3);
}

void	pr_or_wd(t_var *v)
{
	if (v->dot == 1 && v->prc == 0 && v->str[0] == '0')
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
		v->buff = fillbuff(v);
}

void	precision(t_var *v)
{
	v->size = 0;
	v->len = ft_strlen(v->str);
	if (v->len < v->prc)
	{
		v->tmp = ft_strnew(v->prc - v->len + v->plus);
		if (v->plus == 1 && v->neg == 0)
			v->tmp[v->size++] = '+';
		while (v->size < v->prc - v->len + v->plus)
			v->tmp[v->size++] = '0';
		v->tmp2 = ft_strdup(v->str);
		ft_memdel((void **)&v->str);
		v->str = ft_strjoin(v->tmp, v->tmp2);
	}
	if (v->len < v->prc)
	{
		ft_memdel((void **)&v->tmp);
		ft_memdel((void **)&v->tmp2);
	}
	v->buff = fillbuff(v);
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
		v->str = ft_strjoin(v->tmp, v->tmp2);
	}
	if (v->len < v->prc)
	{
		ft_memdel((void **)&v->tmp);
		ft_memdel((void **)&v->tmp2);
	}
	v->tmp = ft_strdup(v->str);
	ft_memdel((void **)&v->str);
	v->str = ft_strjoin("0x", v->tmp);
	ft_memdel((void **)&v->tmp);
	v->buff = fillbuff(v);
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
		v->str = ft_strjoin(v->tmp, v->tmp2);
	}
	if (v->len < v->prc)
	{
		ft_memdel((void **)&v->tmp);
		ft_memdel((void **)&v->tmp2);
	}
	v->tmp = ft_strdup(v->str);
	ft_memdel((void **)&v->str);
	v->str = ft_strjoin("0X", v->tmp);
	ft_memdel((void **)&v->tmp);
	v->buff = fillbuff(v);
}
