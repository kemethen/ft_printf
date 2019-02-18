/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:40:42 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/18 19:30:26 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	mbase_eight_us(unsigned short n)
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

void	percent_ho(va_list ap)
{
	char	*str;
	int		i;
	unsigned short	tmp1;
	int		tmp2;

	tmp1 = (unsigned short)va_arg(ap, int);
	tmp2 = 0;
	i = 0;
	str = ft_strnew(mbase_eight_us(tmp1) + i);
	while (tmp1 != 0)
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
	free(str);
}

size_t		percent_hh(const char *str, va_list ap, size_t i, size_t j)
{
	if (str[i + 2] == 'X')
	{
		hexa_up_us((unsigned short)va_arg(ap, int));
		j = i + 3;
	}
	return (j);
}

size_t		percent_h(const char *str, va_list ap, size_t i, size_t j)
{
	if (str[i + 2] == 'd' || str[i + 2] == 'i')
	{
		ft_putnbrs((short)va_arg(ap, int));
		j = i + 3;
	}
	if (str[i + 2] == 'o')
	{
		percent_ho(ap);
		j = i + 3;
	}
	if (str[i + 2] == 'u')
	{
		ft_putnbrus((unsigned short)va_arg(ap, int));
		j = i + 3;
	}
	if (str[i + 2] == 'x')
	{
		hexa_low_us((unsigned short)va_arg(ap, int));
		j = i + 3;
	}
	j = percent_hh(str, ap, i, j);
	return (j);
}
