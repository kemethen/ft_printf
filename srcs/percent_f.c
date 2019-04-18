/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:52:14 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/18 19:16:57 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_float(float	n, t_var *v)
{
	float	test;

	test = 0;
	v->tmp = ft_strnew(msize_float(n)) + 1;
	test = (int)n % 10;
	return ;
}

void	percent_f(const char *str, va_list ap, t_var *v)
{
	if (str[v->i + 1] == 'f')
		percent_float((float)va_arg(ap, double), v);
}
