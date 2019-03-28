/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:25:27 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/28 14:55:59 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_u(unsigned int value, t_var *v)
{
	v->str = ft_uitoa(value);
	pr_or_wd(v);
	v->j = v->i + 2;
}
