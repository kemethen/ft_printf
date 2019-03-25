/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:16:52 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/25 16:56:47 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char	*s;
	int		*tab;
	int i;
	char	a;
	i = 42;
	s = ft_strdup("coucou\n");
	a = '!';
	tab = malloc(sizeof(int) * 15000);
	printf("Le vrai PRINTF : Le %%#x = %#x\n", 0);
	ft_printf("%#08x\n", 0);
	free(s);
	free(tab);
	return (0);
}
