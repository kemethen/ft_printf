/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:16:52 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/27 18:56:46 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char	*s;
	int		i;
	char	a;
	i = 545513525;
	s = ft_strdup("Ceci est un test du pourcentage s");
	a = 'a';
	printf("Le vrai PRINTF : Le pourcentage c = %c le pourcentage s = %s le pourcentage p = %p le pourcentage d = %d le pourcentage o = %o\n", a, s, s, i, i);
	ft_printf("Mon PRINTF     : Le pourcentage c = %c le pourcentage s = %s le pourcentage p = %p le pourcentage d = %d le pourcentage o = %o\n", a, s, s, i, i);
	free(s);
	return (0);
}

