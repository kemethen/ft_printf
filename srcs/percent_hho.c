/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_hho.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:51:14 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/21 10:27:10 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	mbase_eight_uc(unsigned char c)
{
	size_t	j;

	j = 0;
	while (c != 0)
	{
		c = c / 8;
		++j;
	}
	return (j);
}

void	percent_hho(unsigned char value)
{
	char			*str;
	int				i;
	int				tmp;

	if (value == 0)
	{
		ft_putnbr(0);
		return ;
	}
	tmp = 0;
	i = 0;
	str = ft_strnew(mbase_eight_uc(value));
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
	ft_putstr(ft_strrev(str));
	free(str);
}
