/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:56:21 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/06 16:41:40 by kemethen         ###   ########.fr       */
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
	--v->i;
	free(v->length);
}
