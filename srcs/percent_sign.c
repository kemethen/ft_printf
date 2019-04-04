/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:50:57 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/04 18:42:55 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_sign(const char *str, t_var *v)
{
	if (str[v->i + 1] == '-')
	{
		while (str[v->i + 1] == '-' && str[v->i] != '\0')
			++v->i;
		v->mns = 2;
	}
	if (str[v->i + 1] == '+')
	{
		while (str[v->i + 1] == '+' && str[v->i] != '\0')
			++v->i;
		v->plus = 1;
	}
	if (str[v->i + 1] == ' ')
		percent_space(str, v);
	if (ft_isdigit(str[v->i + 1]) && str[v->i] != '\0')
		percent_nbr(str, v);
}

void	percent_space(const char *str, t_var *v)
{
	v->space = 1;
	while (str[v->i + 1] == ' ')
		v->i++;
}
