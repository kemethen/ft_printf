/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:16:08 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/15 14:56:45 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strndup(char *s1, int n)
{
	char	*s2;

	s2 = ft_strnew((size_t)n);
	return (s2 = ft_strncpy(s2, (const char *)s1, n));
}
