/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:21:34 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/11 16:23:44 by kemethen         ###   ########.fr       */
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
		if (v->prc == 0)
		{
			while (ft_isdigit(str[v->i]))
				++v->i;
			v->length = ft_strsub(str, v->j, v->i - v->j);
			if (v->length[0] != 0)
				v->prc = ft_atoi(v->length);
			ft_memdel((void **)&v->length);
		}
		--v->i;
	}
}
