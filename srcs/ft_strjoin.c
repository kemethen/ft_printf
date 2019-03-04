/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:48:56 by kemethen          #+#    #+#             */
/*   Updated: 2018/11/15 15:43:45 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	int		len1;
	int		len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(s3 = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (s1[len1] != '\0')
	{
		s3[len1] = s1[len1];
		len1++;
	}
	while (s2[len2] != '\0')
	{
		s3[len1 + len2] = s2[len2];
		len2++;
	}
	s3[len1 + len2] = '\0';
	return (s3);
}
