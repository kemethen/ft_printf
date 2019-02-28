/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:41:41 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/27 18:19:06 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_u(unsigned int nb, t_var *v)
{
	v->str = ft_uitoa(nb);
	v->buff = fillbuff(v);
}
