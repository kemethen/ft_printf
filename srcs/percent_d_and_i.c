/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_d_and_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:29:32 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/11 16:03:08 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_d_and_i(int nb, t_var *v)
{
	char	*str;

	v->d = 1;
	if (nb < 0)
		v->neg = 1;
	v->str = ft_itoa(nb);
	if (v->plus != 0 && v->neg == 0)
	{
		str = ft_strdup(v->str);
		ft_memdel((void **)&v->str);
		v->str = ft_strjoin("+", str);
		free(str);
	}
	pr_or_wd(v);
	v->j = v->i + 2;
}
