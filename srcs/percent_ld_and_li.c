/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_ld_and_li.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:51:08 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/11 19:24:34 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_ld_and_li(long long nb, t_var *v)
{
	v->str = ft_lltoa(nb);
	pr_or_wd(v);
	v->j = v->i + 3;
}
