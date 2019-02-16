/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_p_and_o.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:36:31 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/16 17:07:32 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	mbase_eight(unsigned int n)
{
	size_t	j;

	j = 0;
	if (n == 0)
		ft_putnbr(0);
	while (n != 0)
	{
		n = n / 8;
		++j;
	}
	return (j);
}

void	percent_o(va_list ap)
{
	char	*str;
	int		i;
	unsigned int	tmp1;
	int		tmp2;

	tmp1 = va_arg(ap, unsigned int);
	tmp2 = 0;
	i = 0;
	str = ft_strnew(mbase_eight(tmp1) + i);
	while (tmp1 > 0)
	{
		tmp2 = tmp1 % 8;
		if (tmp2 < 10)
			str[i] = tmp2 + 48;
		else
			str[i] = tmp2 + 87;
		i++;
		tmp1 /= 8;
	}
	ft_putstr(ft_strrev(str));
}

char	*hexa_pointer(unsigned long value)
{
	char	*str;
	int		i;
	int		tmp;

	str = ft_strnew(9);
	i = 0;
	while (value > 0)
	{
		tmp = value % 16;
		if (tmp < 10)
			str[i] = tmp + 48;
		else
			str[i] = tmp + 87;
		++i;
		value /= 16;
	}
	return (ft_strrev(str));
}

void	percent_p(va_list ap)
{
	unsigned long	value;
	char			*tmp;
	char			*str;

	value = va_arg(ap, unsigned long);
	tmp = hexa_pointer(value);
	str = ft_strjoin("0x", tmp);
	free(tmp);
	ft_putstr(str);
	free(str);
}
