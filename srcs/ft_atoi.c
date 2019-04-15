/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:31:25 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/15 14:49:22 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int		i;
	size_t	nbr;
	int		negatif;

	i = 0;
	nbr = 0;
	negatif = 0;
	while ((str[i] == ' ') || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	if (str[i] == 45)
		negatif = 1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		nbr = nbr * 10 + str[i] - 48;
		if (negatif == 0 && nbr > __INT64_MAX__)
			return (-1);
		if (negatif == 1 && nbr > (size_t)(__INT64_MAX__) + 1)
			return (0);
		i++;
	}
	if (negatif == 1)
		return (-nbr);
	return (nbr);
}
