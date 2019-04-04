/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:56:21 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/04 16:14:14 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_nbr(const char *str, t_var *v)
{
	++v->i;
	v->j = v->i;
	while (ft_isdigit(str[v->i]))
		++v->i;
	v->length = ft_strsub(str, v->j, v->i - v->j);
	v->width = ft_atoi(v->length);
	free(v->length);
	if (str[v->j] == '0' && v->mns == 0 && str[v->i] != '.')
	{
		v->zero = 2;
		v->prc = v->width;
		v->width = 0;
	}
	--v->i;
	if (str[v->i + 1] == '-' || str[v->i + 1] == '+')
		percent_sign(str, v);
}
