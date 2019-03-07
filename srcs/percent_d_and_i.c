/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_d_and_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:29:32 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/07 16:32:38 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_d_and_i(int nb, t_var *v)
{
	v->str = ft_itoa(nb);
	pr_or_wd(v);
	v->j = v->i + 2;
}
