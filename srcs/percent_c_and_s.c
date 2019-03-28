/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_c_and_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:40:35 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/28 18:01:10 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	percent_s(t_var *v, char *str, size_t i, size_t j)
{
	if (str == NULL)
	{
		j = i + 2;
		return (j);
	}	
	if (v->prc != 0)
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
	if (c == '\0')
		v->str[0] = '\0';
	else
		v->str[0] = c;
	pr_or_wd_ltr(v);
	j = i + 2;
	return (j);
}
