/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_neg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:50:57 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/03 18:41:36 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_neg(const char *str, t_var *v)
{
	ft_putstr("Si je rentre pas la je sais pas coder\n");
	if (str[v->i + 1] == '-')
		v->neg = 2;
	if (str[v->i + 1] == '+')
		v->plus = 1;
}
