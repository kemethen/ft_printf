/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_c_and_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:40:35 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/11 15:59:04 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	percent_s(t_var *v, char *str, size_t i, size_t j)
{
	if (str == NULL)
		v->str = ft_strdup("(null)");
	else if (v->prc != 0 && v->dot == 1)
		v->str = ft_strndup(str, v->prc);
	else
		v->str = ft_strdup(str);
	pr_or_wd_ltr(v);
	j = i + 2;
	return (j);
}

size_t	percent_c(t_var *v, char c, size_t i, size_t j)
{
	v->str = ft_strnew(1);
	v->str[0] = c;
	if (c == '\0')
		v->bzero = 1;
	pr_or_wd_ltr(v);
	j = i + 2;
	return (j);
}
