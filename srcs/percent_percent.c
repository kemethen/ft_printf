/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:06:01 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/02 17:38:50 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_percent(t_var *v)
{
	char	*tmp;

	if (v->str)
	{
		tmp = ft_strdup(v->str);
		ft_putstr("Dans tmp il y a ");
		ft_putstr(tmp);
		ft_putchar('\n');
		free(v->str);
	}
	v->str = ft_strnew(1);
	v->str[0] = '%';
	v->buff = fillbuff(v);
}
