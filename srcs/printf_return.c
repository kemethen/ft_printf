/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:21:55 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/27 16:25:31 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	len_buff(t_var *v)
{
	ft_putstr(v->buff);
	free(v->buff);
	return (ft_strlen(v->buff));
}

size_t	len_str(t_var *v)
{
	ft_putstr(v->str);
	free(v->str);
	return (ft_strlen(v->str));
}