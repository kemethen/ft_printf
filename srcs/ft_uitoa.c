/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:19:39 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/15 14:58:48 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len(unsigned int n)
{
	unsigned int	nbr;
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

char			*nzeroui(char *str)
{
	str[0] = '0';
	return (str);
}

char			*ft_uitoa(unsigned int n)
{
	unsigned int	nbr;
	int				i;
	char			*result;

	nbr = n;
	i = 0;
	result = ft_strnew(ft_len(n));
	if (n == 0)
		return (nzeroui(result));
	while (i < ft_len(n))
	{
		result[ft_len(n) - i - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		++i;
	}
	return (result);
}
