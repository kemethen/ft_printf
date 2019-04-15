/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:32:20 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/15 14:49:38 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len(int long n)
{
	int			i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		++i;
		n /= 10;
	}
	return (i);
}

char			*nzero(char *str)
{
	str[0] = '0';
	return (str);
}

char			*ft_itoa(int n)
{
	long int	nbr;
	int			neg;
	int			i;
	char		*result;

	nbr = n;
	i = 0;
	neg = (nbr < 0) ? 1 : 0;
	result = ft_strnew((size_t)ft_len(nbr) + neg);
	if (nbr < 0)
	{
		nbr = -nbr;
		result[0] = '-';
	}
	if (n == 0)
		return (nzero(result));
	while (nbr != 0)
	{
		result[ft_len(n) - i + neg - 1] = (nbr % 10) + '0';
		nbr /= 10;
		++i;
	}
	return (result);
}
