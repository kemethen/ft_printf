/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:41:41 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/16 16:50:29 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_u(va_list ap)
{
	unsigned int	tmp;

	tmp = va_arg(ap, int);
	ft_putnbr((int)tmp);
}
