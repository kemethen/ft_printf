/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_p_and_o.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:36:31 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/18 13:48:24 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		msize_hexa_ptr(unsigned long n)
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

size_t	mbase_eight(unsigned int n)
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

void	percent_o(unsigned int value, t_var *v)
{
	char	*str;
	int		i;
	int		tmp;

	str = ft_strnew(mbase_eight(value) + 1);
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
	v->j = v->i + 2;
	pr_or_wd(v);
}

char	*hexa_pointer(unsigned long value)
{
	char	*str;
	char	*ptr;
	int		i;
	int		tmp;

	str = ft_strnew(msize_hexa_ptr(value) + 1);
	if (value == 0)
		str[0] = '0';
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
	ptr = ft_strjoin("0x", ft_strrev(str));
	free(str);
	return (ptr);
}

void	percent_p(va_list ap, t_var *v)
{
	unsigned long	value;

	value = va_arg(ap, unsigned long);
	v->str = hexa_pointer(value);
	v->j = v->i + 2;
	pr_or_wd(v);
}
