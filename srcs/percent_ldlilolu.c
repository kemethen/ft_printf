/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_ldlilolu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:57:51 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/15 19:22:03 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_lu(unsigned long value, t_var *v, const char *str)
{
	if (str[v->i + 1] == 'z' && str[v->i + 2] == 'd' && value + 1 == 0)
		v->str = ft_itoa(-1);
	else
		v->str = ft_ultoa(value);
	pr_or_wd(v);
	v->j = v->i + 3;
}

size_t	mbase_eight_ll(unsigned long n)
{
	int		j;

	j = 0;
	while (n != 0)
	{
		n = n / 8;
		++j;
	}
	return (j);
}

void	percent_lo(unsigned long value, t_var *v)
{
	char		*str;
	long long	i;
	long long	tmp;

	str = ft_strnew(mbase_eight_ll(value) + 1);
	if (value == 0)
		str[0] = '0';
	tmp = 0;
	i = 0;
	while (value != 0)
	{
		tmp = value % 8;
		if (tmp < 10)
			str[i] = tmp + 48;
		else
			str[i] = tmp + 87;
		i++;
		value /= 8;
	}
	v->str = ft_strrev(str);
	pr_or_wd(v);
}

void	percent_ld_and_li(long long nb, t_var *v)
{
	v->str = ft_lltoa(nb);
	pr_or_wd(v);
	v->j = v->i + 3;
}

void	percent_dot(const char *str, t_var *v)
{
	if (str[v->i + 1] == '.')
	{
		v->dot = 1;
		v->i += 2;
		v->j = v->i;
		if (v->prc == 0)
		{
			while (str[v->i] >= 48 && str[v->i] <= 57)
				++v->i;
			v->length = ft_strsub(str, v->j, v->i - v->j);
			if (v->length[0] != 0)
				v->prc = ft_atoi(v->length);
			ft_memdel((void **)&v->length);
		}
		--v->i;
	}
}
