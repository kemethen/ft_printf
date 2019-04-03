/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_and_wd_neg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:43:06 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/03 16:37:16 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr_and_wd_neg(t_var *v)
{
	v->prwd = ft_strjoin(v->tmp2, v->str);
	free(v->tmp2);
	free(v->str);
	v->str = ft_strjoin(v->prwd, v->tmp);
	free(v->tmp);
	free(v->prwd);
	v->buff = fillbuff(v);
}

void	pr_or_wd_ltr(t_var *v)
{
	if (v->width != 0)
		width(v);
	else
		v->buff = fillbuff(v);
}
