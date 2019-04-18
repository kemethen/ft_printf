/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:03:20 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/18 18:51:14 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fillbuff(t_var *v)
{
	v->tmp = ft_strdup(v->buff);
	ft_memdel((void **)&v->buff);
	if (v->space == 1 && v->plus == 0 && v->neg == 0
		&& v->d == 1 && v->width == 0)
	{
		v->tmp2 = ft_strdup(v->str);
		ft_memdel((void **)&v->str);
		v->str = ft_strjoin(" ", v->tmp2);
		ft_memdel((void **)&v->tmp2);
	}
	v->buff = ft_strjoin(v->tmp, v->str);
	ft_memdel((void **)&v->tmp);
	reset_v(v);
	ft_memdel((void **)&v->str);
}

void	check3(const char *str, va_list ap, t_var *v)
{
	if (str[v->i + 1] == 'x')
		hexa_low(va_arg(ap, unsigned int), v);
	if (str[v->i + 1] == 'X')
		hexa_up(va_arg(ap, unsigned int), v);
	if (str[v->i + 1] == 'h')
		v->j = percent_h(str, ap, v);
	if (str[v->i + 1] == '%')
		percent_percent(v);
	if (str[v->i + 1] == 'l')
		v->j = percent_l(str, ap, v);
	if (str[v->i + 1] == '#')
		v->j = percent_sharp(str, ap, v);
	if (str[v->i + 1] == 'j' && str[v->i + 2] == 'x')
	{
		hexa_low_ul(va_arg(ap, unsigned long), v);
		v->j = v->i + 3;
	}
	if (str[v->i + 1] == 'j' && str[v->i + 2] == 'd')
		percent_ld_and_li(va_arg(ap, long int), v);
	if ((str[v->i + 1] == 'z' && str[v->i + 2] == 'd')
		|| (str[v->i + 1] == 'j' && str[v->i + 2] == 'u'))
		percent_lu(va_arg(ap, unsigned long), v, str);
	else
		v->i++;
}

void	check2(const char *str, va_list ap, t_var *v)
{
	if (str[v->i + 1] == '.' && str[v->i] != 0)
		percent_dot(str, v);
	if (str[v->i + 1] == 'c' && str[v->i] != 0)
		v->j = percent_c(v, (char)va_arg(ap, int), v->i, v->j);
	if (str[v->i + 1] == 's' && str[v->i] != 0)
		v->j = percent_s(v, va_arg(ap, char *), v->i, v->j);
	if (str[v->i + 1] == 'p' && str[v->i] != 0)
		percent_p(ap, v);
	if (str[v->i + 1] == 'd' || str[v->i + 1] == 'i')
		percent_d_and_i(va_arg(ap, int), v);
	if (str[v->i + 1] == 'o' && str[v->i] != 0)
		percent_o(va_arg(ap, unsigned int), v);
	if (str[v->i + 1] == 'u' && str[v->i] != 0)
		percent_u(va_arg(ap, unsigned int), v);
	if (str[v->i + 1] == 'U')
	{
		percent_lu(va_arg(ap, unsigned long), v, str);
		v->j--;
	}
	percent_f(str, ap, v);
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
			v->buff = joinfree(v->tmp, v->str);
		}
		else
		{
			v->buff = ft_strdup(v->str);
			ft_memdel((void **)&v->str);
		}
		if (str[v->i + 1] == ' ' && str[v->i] != 0)
			percent_space(str, v);
		if (str[v->i + 1] == '-' || str[v->i + 1] == '+')
			percent_sign(str, v);
		if (str[v->i + 1] >= 48 && str[v->i + 1] <= 57 && str[v->i] != '\0')
			percent_nbr(str, v);
		check2(str, ap, v);
		++v->i;
	}
	return (printf_return(v));
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	t_var	*v;
	size_t	len;

	if (str == NULL)
		return (0);
	v = ft_memalloc(sizeof(t_var));
	ft_bzero(v, sizeof(t_var));
	va_start(ap, str);
	len = check(str, ap, v);
	va_end(ap);
	free(v);
	return (len);
}
