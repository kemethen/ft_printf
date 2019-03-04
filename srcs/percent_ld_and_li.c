/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_ld_and_li.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:51:08 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/04 16:34:50 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_ld_and_li(long long nb, t_var *v)
{
	v->str = ft_lltoa(nb);
	v->buff = fillbuff(v);
}
