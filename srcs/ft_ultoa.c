/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:01:44 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/15 15:00:32 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len(unsigned long n)
{
	unsigned long	nbr;
	int				i;

	nbr = n;
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		++i;
		nbr = nbr / 10;
	}
	return (i);
}

char			*nzeroul(char *str)
{
	str[0] = '0';
	return (str);
}

char			*ft_ultoa(unsigned long n)
{
	unsigned long	nbr;
	int				i;
	char			*result;

	nbr = n;
	i = 0;
	result = ft_strnew(ft_len(n));
	if (n == 0)
		return (nzeroul(result));
	while (i < ft_len(n))
	{
		result[ft_len(n) - i - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		++i;
	}
	return (result);
}
