/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:21:34 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/03 18:12:36 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_dot(const char *str, t_var *v)
{
	if (str[v->i + 1] == '.')
	{
		v->dot = 1;
		v->i += 2;
		v->j = v->i;
		while (ft_isdigit(str[v->i]))
			++v->i;
		v->length = ft_strsub(str, v->j, v->i - v->j);
		v->prc = ft_atoi(v->length);
		free(v->length);
		--v->i;
	}
}
