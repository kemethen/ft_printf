/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:22:42 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/16 17:18:39 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width(t_var *v)
{
	v->size2 = 0;
	v->len2 = ft_strlen(v->str);
	if (v->len2 < v->width)
	{
		v->tmp = ft_strnew(v->width - v->len2 + v->plus);
		while (v->size2 < v->width - v->len2 - v->plus - (int)v->bzero)
			v->tmp[v->size2++] = ' ';
		if (v->plus == 1 && v->neg == 0)
			v->tmp2 = ft_strjoin("+", v->str);
		else
			v->tmp2 = ft_strdup(v->str);
		ft_memdel((void **)&v->str);
		if (v->mns == 2)
			v->str = joinfree(v->tmp2, v->tmp);
		else
			v->str = joinfree(v->tmp, v->tmp2);
	}
	else if (v->plus != 0)
	{
		v->tmp = ft_strdup("+");
		v->str = joinfree(v->tmp, v->str);
	}
	fillbuff(v);
}

void	width_sharp_low(t_var *v)
{
	v->size = 0;
	v->len = ft_strlen(v->str);
	if (v->len < v->width)
	{
		v->tmp = ft_strnew(v->width - v->len);
		while (v->size + 2 < v->width - v->len)
			v->tmp[v->size++] = ' ';
		v->tmp2 = ft_strdup(v->str);
		ft_memdel((void **)&v->str);
		v->str = ft_strjoin("0x", v->tmp2);
	}
	if (v->len < v->width)
		ft_memdel((void **)&v->tmp2);
	v->tmp2 = ft_strdup(v->str);
	ft_memdel((void **)&v->str);
	if (v->mns == 2)
		v->str = joinfree(v->tmp2, v->tmp);
	else
		v->str = joinfree(v->tmp, v->tmp2);
	fillbuff(v);
}

void	width_sharp_up(t_var *v)
{
	v->size = 0;
	v->len = ft_strlen(v->str);
	if (v->len < v->width)
	{
		v->tmp = ft_strnew(v->width - v->len);
		while (v->size + 2 < v->width - v->len)
			v->tmp[v->size++] = ' ';
		v->tmp2 = ft_strdup(v->str);
		ft_memdel((void **)&v->str);
		v->str = ft_strjoin("0X", v->tmp2);
	}
	if (v->len < v->width)
		ft_memdel((void **)&v->tmp2);
	v->tmp2 = ft_strdup(v->str);
	ft_memdel((void **)&v->str);
	if (v->mns == 2)
		v->str = joinfree(v->tmp2, v->tmp);
	else
		v->str = joinfree(v->tmp, v->tmp2);
	fillbuff(v);
}
