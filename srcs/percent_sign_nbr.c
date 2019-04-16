/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_sign_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:06:01 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/16 17:43:14 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_percent(t_var *v)
{
	v->percent = 1;
	v->plus = 0;
	v->str = ft_strnew(1);
	v->str[0] = '%';
	pr_or_wd_ltr(v);
	v->j = v->i + 2;
}

void	percent_nbr(const char *str, t_var *v)
{
	++v->i;
	v->j = v->i;
	while (str[v->i] >= 48 && str[v->i] <= 57)
		++v->i;
	v->length = ft_strsub(str, v->j, v->i - v->j);
	v->width = ft_atoi(v->length);
	ft_memdel((void**)&v->length);
	if ((str[v->j] == '0' && v->mns == 0 && str[v->i] != '.') || v->zero != 0)
	{
		v->zero = 2;
		v->prc = v->width - v->neg;
		v->width = 0;
	}
	--v->i;
	if (str[v->i + 1] == '-' || str[v->i + 1] == '+')
		percent_sign(str, v);
}

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
	if (str[v->i + 1] == '-')
	{
		while (str[v->i + 1] == '-' && str[v->i] != '\0')
			++v->i;
		v->mns = 2;
	}
	if (str[v->i + 1] == ' ')
		percent_space(str, v);
	if (str[v->i + 1] >= 48 && str[v->i + 1] <= 57 && str[v->i] != '\0')
		percent_nbr(str, v);
}

void	percent_space(const char *str, t_var *v)
{
	v->space = 1;
	while (str[v->i + 1] == ' ')
		v->i++;
}
