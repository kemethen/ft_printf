/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_lo_and_lu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:57:51 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/03 14:01:27 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_lu(unsigned long value, t_var *v)
{
	v->str = ft_ultoa(value);
	pr_or_wd(v);
}

size_t	mbase_eight_ll(long long n)
{
	size_t	j;

	j = 0;
	while (n != 0)
	{
		n = n / 8;
		++j;
	}
	return (j);
}

void	percent_lo(long long value, t_var *v)
{
	char	*str;
	int		i;
	int		tmp;

	str = ft_strnew(mbase_eight_ll(value));
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
