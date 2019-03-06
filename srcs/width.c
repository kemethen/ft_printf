/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:22:42 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/06 16:24:03 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width(t_var *v)
{
	v->size2 = 0;
	v->len2 = ft_strlen(v->str);
	if (v->len2 < v->width)
	{
		v->tmp = ft_strnew(v->width - v->len2);
		while (v->size2 < v->width - v->len2)
			v->tmp[v->size2++] = ' ';
		v->tmp2 = ft_strdup(v->str);
		free(v->str);
		v->str = ft_strjoin(v->tmp, v->tmp2);
	}
	if (v->width > 0)
	{
		free(v->tmp);
		free(v->tmp2);
	}
	v->buff = fillbuff(v);
}
