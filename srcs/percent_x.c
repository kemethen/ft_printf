/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:05:46 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/18 17:29:50 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		msize_hexa_int(unsigned int n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		++i;
	}
	return (i);
}

void	hexa_up(unsigned int value)
{
	char	*str;
	int		i;
	int		tmp;

	if (value == 0)
	{
		ft_putnbr(0);
		return ;
	}
	str = ft_strnew(msize_hexa_int(value) + 1);
	i = 0;
	while (value != 0)
	{
		tmp = value % 16;
		if (tmp < 10)
			str[i] = tmp + 48;
		else
			str[i] = tmp + 55;
		++i;
		value /= 16;
	}
	ft_putstr(ft_strrev(str));
	free(str);
}

void	hexa_low(unsigned int value)
{
	char	*str;
	int		i;
	int		tmp;

	if (value == 0)
	{
		ft_putnbr(0);
		return ;
	}
	str = ft_strnew(msize_hexa_int(value) + 1);
	i = 0;
	while (value != 0)
	{
		tmp = value % 16;
		if (tmp < 10)
			str[i] = tmp + 48;
		else
			str[i] = tmp + 87;
		++i;
		value /= 16;
	}
	ft_putstr(ft_strrev(str));
	free(str);
}
