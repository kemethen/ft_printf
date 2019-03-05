/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:43:59 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/05 18:34:37 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr_or_wd(t_var *v)
{
//	if (v->width != 0 && v->prc != 0)
//		pr_and_wd(v);
	if (v->prc != 0)
		precision(v);
	if (v->width != 0)
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
		v->tmp = ft_strnew(v->prc - v->len);
		while (v->size < v->prc - v->len)
			v->tmp[v->size++] = '0';
		v->tmp2 = ft_strdup(v->str);
		free(v->str);
		v->str = ft_strjoin(v->tmp, v->tmp2);
	}
	if (v->prc > 0)
	{
		free(v->tmp);
		free(v->tmp2);
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
		while (v->size < v->prc - v->len)
			v->tmp[v->size++] = '0';
		v->tmp2 = ft_strdup(v->str);
		free(v->str);
		v->str = ft_strjoin(v->tmp, v->tmp2);
	}
	if (v->prc > 0)
	{
		free(v->tmp);
		free(v->tmp2);
	}
	v->tmp = ft_strdup(v->str);
	free(v->str);
	v->str = ft_strjoin("0x", v->tmp);
	free(v->tmp);
	v->buff = fillbuff(v);
}

void	precision_sharp_up(t_var *v)
{
	v->size = 0;
	v->len = ft_strlen(v->str);
	if (v->len < v->prc)
	{
		v->tmp = ft_strnew(v->prc - v->len);
		while (v->size < v->prc - v->len)
			v->tmp[v->size++] = '0';
		v->tmp2 = ft_strdup(v->str);
		free(v->str);
		v->str = ft_strjoin(v->tmp, v->tmp2);
	}
	if (v->prc > 0)
	{
		free(v->tmp);
		free(v->tmp2);
	}
	v->tmp = ft_strdup(v->str);
	free(v->str);
	v->str = ft_strjoin("0X", v->tmp);
	free(v->tmp);
	v->buff = fillbuff(v);
}
