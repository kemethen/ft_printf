/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:03:20 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/04 19:12:30 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fillbuff(t_var *v)
{
	v->tmp = ft_strdup(v->buff);
	free(v->buff);
	if (v->space == 1 && v->plus == 0 && v->neg == 0
		&& v->d == 1 && v->width == 0)
	{
		v->tmp2 = ft_strdup(v->str);
		free(v->str);
		v->str = ft_strjoin(" ", v->tmp2);
		free(v->tmp2);
	}
	v->buff = ft_strjoin(v->tmp, v->str);
	if (v->str[0] != '\0')
		free(v->str);
	free(v->tmp);
	v->prc = 0;
	v->width = 0;
	v->mns = 0;
	v->neg = 0;
	v->plus = 0;
	v->zero = 0;
	v->dot = 0;
	v->space = 0;
	v->d = 0;
	return (v->buff);
}

void	check3(const char *str, va_list ap, t_var *v)
{
	if (str[v->i + 1] == 'x')
	{
		hexa_low(va_arg(ap, unsigned int), v);
		v->j = v->i + 2;
	}
	if (str[v->i + 1] == 'X')
	{
		hexa_up(va_arg(ap, unsigned int), v);
		v->j = v->i + 2;
	}
	if (str[v->i + 1] == 'h')
		v->j = percent_h(str, ap, v);
	if (str[v->i + 1] == '%')
	{
		percent_percent(v);
		v->j = v->i + 2;
	}
	if (str[v->i + 1] == 'l')
		v->j = percent_l(str, ap, v);
	if (str[v->i + 1] == '#')
		v->j = percent_sharp(str, ap, v);
	else
		v->i++;
}

void	check2(const char *str, va_list ap, t_var *v)
{
	if (ft_isdigit(str[v->i + 1]) && str[v->i] != '\0')
		percent_nbr(str, v);
	if (str[v->i + 1] == '.')
		percent_dot(str, v);
	if (str[v->i + 1] == 'c')
		v->j = percent_c(v, (char)va_arg(ap, int), v->i, v->j);
	if (str[v->i + 1] == 's')
		v->j = percent_s(v, va_arg(ap, char *), v->i, v->j);
	if (str[v->i + 1] == 'p')
	{
		percent_p(ap, v);
		v->j = v->i + 2;
	}
	if (str[v->i + 1] == 'd' || str[v->i + 1] == 'i')
		percent_d_and_i(va_arg(ap, int), v);
	if (str[v->i + 1] == 'o')
	{
		percent_o(va_arg(ap, unsigned int), v);
		v->j = v->i + 2;
	}
	if (str[v->i + 1] == 'u')
		percent_u(va_arg(ap, unsigned int), v);
	check3(str, ap, v);
}

int		check(const char *str, va_list ap, t_var *v)
{
	while (v->i < ft_strlen(str))
	{
		while (str[v->i] != '%' && str[v->i] != '\0')
			++v->i;
		v->str = ft_strsub(str, v->j, v->i - v->j);
		if (v->buff)
		{
			v->tmp = v->buff;
			v->buff = ft_strjoin(v->tmp, v->str);
			free(v->tmp);
			free(v->str);
		}
		else
		{
			v->buff = ft_strdup(v->str);
			free(v->str);
		}
		if (str[v->i + 1] == ' ')
			percent_space(str, v);
		if (str[v->i + 1] == '-' || str[v->i + 1] == '+')
			percent_sign(str, v);
		check2(str, ap, v);
		++v->i;
	}
	return (printf_return(v));
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	t_var	*v;
	int		len;

	v = ft_memalloc(sizeof(t_var));
	va_start(ap, str);
	len = check(str, ap, v);
	va_end(ap);
	free(v);
	return (len);
}
