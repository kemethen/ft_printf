/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:21:55 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/12 11:28:34 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	printf_return(t_var *v)
{
	if (v->buff)
		return (len_buff(v));
	else
		return (len_str(v));
}

size_t	len_buff(t_var *v)
{
	ft_putstr(v->buff);
	free(v->buff);
	return (ft_strlen(v->buff));
}

size_t	len_str(t_var *v)
{
	if (v->i == 0)
		return (0);
	ft_putstr(v->str);
	free(v->str);
	return (ft_strlen(v->str));
}
