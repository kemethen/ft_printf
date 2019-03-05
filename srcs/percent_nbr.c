/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:56:21 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/05 18:55:27 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_nbr(const char *str, t_var *v)
{
	if (ft_isdigit(str[v->i + 1]))
	{
		printf("v->width = %d\nstr est sur %c\n", v->width, str[v->i - 1]);
		++v->i;
		v->j = v->i;
		printf("v->i avant %zu\n", v->i);
		while (ft_isdigit(str[v->i]))
			++v->i;
		printf("v->i apres %zu\n", v->i);
		v->length = ft_strsub(str, v->j, v->i - v->j);
		v->width = ft_atoi(v->length);
		free(v->length);
	}
}
