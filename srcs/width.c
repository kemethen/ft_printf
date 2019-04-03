/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:22:42 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/03 13:05:08 by kemethen         ###   ########.fr       */
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
		while (v->size2 < v->width - v->len2 - v->plus)
			v->tmp[v->size2++] = ' ';
		if (v->plus == 1)
			v->tmp[v->size2++] = '+';
		v->tmp2 = ft_strdup(v->str);
		free(v->str);
		if (v->neg == 2)
			v->str = ft_strjoin(v->tmp2, v->tmp);
		else
			v->str = ft_strjoin(v->tmp, v->tmp2);
	}
	if (v->len2 < v->width)
	{
		free(v->tmp);
		free(v->tmp2);
	}
	v->buff = fillbuff(v);
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
		free(v->str);
		v->str = ft_strjoin("0x", v->tmp2);
	}
	if (v->len < v->width)
		free(v->tmp2);
	v->tmp2 = ft_strdup(v->str);
	free(v->str);
	if (v->neg == 2)
		v->str = ft_strjoin(v->tmp2, v->tmp);
	else
		v->str = ft_strjoin(v->tmp, v->tmp2);
	free(v->tmp);
	free(v->tmp2);
	v->buff = fillbuff(v);
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
		free(v->str);
		v->str = ft_strjoin("0X", v->tmp2);
	}
	if (v->len < v->width)
		free(v->tmp2);
	v->tmp2 = ft_strdup(v->str);
	free(v->str);
	if (v->neg == 2)
		v->str = ft_strjoin(v->tmp2, v->tmp);
	else
		v->str = ft_strjoin(v->tmp, v->tmp2);
	free(v->tmp);
	free(v->tmp2);
	v->buff = fillbuff(v);
}
