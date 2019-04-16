/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_and_wd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 10:23:44 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/16 19:42:43 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wd_higher_prc_up(t_var *v, int prsize, int wdsize)
{
	v->len = ft_strlen(v->str);
	v->tmp = ft_strnew(v->width - v->prc);
	if (v->prc > v->len)
	{
		v->tmp2 = ft_strnew(v->prc - v->len);
		while (prsize < v->prc - v->len + v->neg - v->nbr)
			v->tmp2[prsize++] = '0';
	}
	else
	{
		width_sharp_up(v);
		return ;
	}
	while (wdsize + 2 < v->width - v->prc)
		v->tmp[wdsize++] = ' ';
	v->prwd = ft_strjoin(v->tmp, "0X");
	ft_memdel((void **)&v->tmp);
	v->tmp = ft_strdup(v->str);
	ft_memdel((void **)&v->str);
	v->str = joinfree(v->tmp2, v->tmp);
	v->tmp = ft_strdup(v->str);
	ft_memdel((void **)&v->str);
	v->str = joinfree(v->prwd, v->tmp);
	fillbuff(v);
}

void	wd_higher_prc_low(t_var *v, int prsize, int wdsize)
{
	v->len = ft_strlen(v->str);
	v->tmp = ft_strnew(v->width - v->prc);
	if (v->prc > v->len)
	{
		v->tmp2 = ft_strnew(v->prc - v->len);
		while (prsize < v->prc - v->len)
			v->tmp2[prsize++] = '0';
	}
	else
	{
		width_sharp_low(v);
		return ;
	}
	while (wdsize + 2 < v->width - v->prc)
		v->tmp[wdsize++] = ' ';
	v->prwd = ft_strjoin(v->tmp, "0x");
	ft_memdel((void **)&v->tmp);
	v->tmp = ft_strdup(v->str);
	ft_memdel((void **)&v->str);
	v->str = joinfree(v->tmp2, v->tmp);
	v->tmp = ft_strdup(v->str);
	ft_memdel((void **)&v->str);
	v->str = joinfree(v->prwd, v->tmp);
	fillbuff(v);
}

void	pr_and_wd_sharp(t_var *v, char c)
{
	int		prsize;
	int		wdsize;

	prsize = 0;
	wdsize = 0;
	if (v->width <= v->prc && c == 'x')
		precision_sharp_low(v);
	else if (v->width <= v->prc && c == 'X')
		precision_sharp_up(v);
	else if (v->width > v->prc && c == 'x')
		wd_higher_prc_low(v, prsize, wdsize);
	else if (v->width > v->prc && c == 'X')
		wd_higher_prc_up(v, prsize, wdsize);
}

void	wd_higher_prc(t_var *v, int prsize, int wdsize)
{
	v->len = ft_strlen(v->str) - v->neg;
	if (v->prc + v->neg > v->len)
	{
		v->tmp = ft_strnew(v->width - v->prc + v->plus);
		v->tmp2 = ft_strnew(v->prc - v->len + v->plus + v->neg);
		if (v->plus == 1)
			v->tmp2[prsize++] = '+';
		if (v->neg != 0)
			v->tmp2[prsize++] = '-';
		while (prsize < v->prc - v->len + v->plus + v->neg)
			v->tmp2[prsize++] = '0';
	}
	else
	{
		width(v);
		return ;
	}
	while (wdsize < v->width - v->prc - v->plus - v->neg)
		v->tmp[wdsize++] = ' ';
	if (v->mns == 2)
		pr_and_wd_neg(v);
	else
		wd_prc_neg(v);
}

void	pr_and_wd(t_var *v)
{
	int		prsize;
	int		wdsize;

	prsize = 0;
	wdsize = 0;
	if (v->width <= v->prc)
	{
		if (v->neg == 1)
			v->neg++;
		precision(v);
	}
	else
		wd_higher_prc(v, prsize, wdsize);
}
