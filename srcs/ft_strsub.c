/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:41:37 by kemethen          #+#    #+#             */
/*   Updated: 2018/12/11 18:54:55 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (s == NULL || (len + start) > ft_strlen(s))
		return (NULL);
	if (!(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = (size_t)start;
	while (len)
	{
		s2[i - start] = s[i];
		i++;
		len--;
	}
	s2[i - start] = '\0';
	return (s2);
}
