/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:52:55 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/15 14:49:49 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len(long long n)
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

char			*nzero_ll(char *str, long long n)
{
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	else
	{
		free(str);
		str = ft_strdup("-9223372036854775808");
		return (str);
	}
}

char			*ft_lltoa(long long n)
{
	long long	nbr;
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
	if (n == 0 || n == -9223372036854775807 - 1)
		return (nzero_ll(result, n));
	while (nbr != 0)
	{
		result[ft_len(n) - i + neg - 1] = (nbr % 10) + '0';
		nbr /= 10;
		++i;
	}
	return (result);
}
