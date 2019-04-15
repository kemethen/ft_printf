/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_csdi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:40:35 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/15 19:36:19 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	percent_s(t_var *v, char *str, size_t i, size_t j)
{
	v->plus = 0;
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
	v->plus = 0;
	v->str = ft_strnew(1);
	v->str[0] = c;
	if (c == '\0')
		v->bzero = 1;
	pr_or_wd_ltr(v);
	j = i + 2;
	return (j);
}

void	pr_and_wd_neg(t_var *v)
{
	v->prwd = joinfree(v->tmp2, v->str);
	v->str = joinfree(v->prwd, v->tmp);
	fillbuff(v);
}

void	pr_or_wd_ltr(t_var *v)
{
	if (v->width != 0)
		width(v);
	else if (v->prc != 0 && (size_t)v->prc < ft_strlen(v->str))
	{
		v->tmp = ft_strndup(v->str, ft_strlen(v->str) - v->prc);
		ft_memdel((void **)&v->str);
		v->str = v->tmp;
		fillbuff(v);	
	}
	else if (v->prc == 0 && v->dot != 0 && v->percent == 0)
	{
		ft_memdel((void **)&v->str);
		v->str = ft_strnew(0);
		fillbuff(v);
	}
	else
		fillbuff(v);
}

void	percent_d_and_i(int nb, t_var *v)
{
	char	*str;

	v->d = 1;
	if (nb < 0)
		v->neg = 1;
	if (v->zero != 0 && v->prc != 0 && v->neg != 0)
		v->nbr = 1;
	if (v->prc != 0 && v->neg != 0 && v->width == 0)
		v->neg++;
	v->str = ft_itoa(nb);
	if (v->str[0] == '-')
		v->plus = 0;
	if (v->plus != 0 && v->neg == 0 && v->prc == 0 && v->width == 0)
	{
		str = ft_strdup(v->str);
		ft_memdel((void **)&v->str);
		v->str = ft_strjoin("+", str);
		free(str);
	}
	pr_or_wd(v);
	v->j = v->i + 2;
}
