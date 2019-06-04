/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maincsp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/05/29 18:35:38 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "srcs/ft_printf.h"

int		main(void)
{
	int		*tab = malloc(sizeof(int) * 10);
	int		*tab2 = malloc(0);

	ft_printf("--------------------%%c--------------------\n");
	printf("01) Vrai PRINTF : |%c|\n", 'a');
	ft_printf("01) Mon PRINTF  : |%c|\n", 'a');
	printf("02) Vrai PRINTF : |%-c|\n", 'z');
	ft_printf("02) Mon PRINTF  : |%-c|\n", 'z');
	printf("03) Vrai PRINTF : |%-----c|\n", '!');
	ft_printf("03) Mon PRINTF  : |%-----c|\n", '!');
	printf("04) Vrai PRINTF : |%5c|\n", 'R');
	ft_printf("04) Mon PRINTF  : |%5c|\n", 'R');
	printf("05) Vrai PRINTF : |%-5c|\n", 'R');
	ft_printf("05) Mon PRINTF  : |%-5c|\n", 'R');
	printf("06) Vrai PRINTF : |%1c|\n", '3');
	ft_printf("06) Mon PRINTF  : |%1c|\n", '3');
	printf("07) Vrai PRINTF : |%c|\n", '\0');
	ft_printf("07) Mon PRINTF  : |%c|\n", '\0');
	printf("08) Vrai PRINTF : |%5c|\n", '\0');
	ft_printf("08) Mon PRINTF  : |%5c|\n", '\0');
	printf("08.1) Vrai PRINTF : |%10c|\n", '\0');
	ft_printf("08.1) Mon PRINTF  : |%10c|\n", '\0');
	printf("08.2) Vrai PRINTF : |%15c|\n", '\0');
	ft_printf("08.2) Mon PRINTF  : |%15c|\n", '\0');
	printf("08.3) Vrai PRINTF : |%2c|\n", '\0');
	ft_printf("08.3) Mon PRINTF  : |%2c|\n", '\0');
	printf("09) Vrai PRINTF : |%-5c|\n", '\0');
	ft_printf("09) Mon PRINTF  : |%-5c|\n", '\0');
	printf("09.1) Vrai PRINTF : |%-10c|\n", '\0');
	ft_printf("09.1) Mon PRINTF  : |%-10c|\n", '\0');
	printf("09.2) Vrai PRINTF : |%-15c|\n", '\0');
	ft_printf("09.2) Mon PRINTF  : |%-15c|\n", '\0');
	printf("09.3) Vrai PRINTF : |%-2c|\n", '\0');
	ft_printf("09.3) Mon PRINTF  : |%-2c|\n", '\0');
	printf("10) Vrai PRINTF : |%1c|\n", '\0');
	ft_printf("10) Mon PRINTF  : |%1c|\n", '\0');
	printf("11) Vrai PRINTF : |%c| |%c| |%c|\n", '\0', '\0', '\0');
	ft_printf("11) Mon PRINTF  : |%c| |%c| |%c|\n", '\0', '\0', '\0');
	printf("12) Vrai PRINTF : |%2c| |%4c| |%5c|\n", '\0', '\0', '\0');
	ft_printf("12) Mon PRINTF  : |%2c| |%4c| |%5c|\n", '\0', '\0', '\0');
	ft_printf("--------------------%%s--------------------\n");
	printf("01) Vrai PRINTF : |%s|\n", "salut");
	ft_printf("01) Mon PRINTF  : |%s|\n", "salut");
	printf("02) Vrai PRINTF : |%-s|\n", "test");
	ft_printf("02) Mon PRINTF  : |%-s|\n", "test");
	printf("03) Vrai PRINTF : |%---------s|\n", "test2");
	ft_printf("03) Mon PRINTF  : |%----------s|\n", "test2");
	printf("04) Vrai PRINTF : |%10s|\n", "42");
	ft_printf("04) Mon PRINTF  : |%10s|\n", "42");
	printf("05) Vrai PRINTF : |%-10s|\n", "42");
	ft_printf("05) Mon PRINTF  : |%-10s|\n", "42");
	printf("06) Vrai PRINTF : |%2s|\n", "string");
	ft_printf("06) Mon PRINTF  : |%2s|\n", "string");
	printf("07) Vrai PRINTF : |%-2s|\n", "string");
	ft_printf("07) Mon PRINTF  : |%-2s|\n", "string");
	printf("08) Vrai PRINTF : |%.15s|\n", "precision");
	ft_printf("08) Mon PRINTF  : |%.15s|\n", "precision");
	printf("09) Vrai PRINTF : |%.4s|\n", "precision");
	ft_printf("09) Mon PRINTF  : |%.4s|\n", "precision");
	printf("10) Vrai PRINTF : |%.0s|\n", "precision");
	ft_printf("10) Mon PRINTF  : |%.0s|\n", "precision");
	printf("11) Vrai PRINTF : |%s|\n", "\0\0\0\0\0");
	ft_printf("11) Mon PRINTF  : |%s|\n", "\0\0\0\0\0");
	printf("12) Vrai PRINTF : |%10s|\n", "\0\0\0\0\0");
	ft_printf("12) Mon PRINTF  : |%10s|\n", "\0\0\0\0\0");
	printf("13) Vrai PRINTF : |%s|\n", "");
	ft_printf("13) Mon PRINTF  : |%s|\n", "");
	printf("14) Vrai PRINTF : |%-.2s|\n", "boom");
	ft_printf("14) Mon PRINTF  : |%-.2s|\n", "boom");
	printf("15) Vrai PRINTF : |%10.8s|\n", "google");
	ft_printf("15) Mon PRINTF  : |%10.8s|\n", "google");
	printf("16) Vrai PRINTF : |%10.2s|\n", "twitter");
	ft_printf("16) Mon PRINTF  : |%10.2s|\n", "twitter");
	printf("17) Vrai PRINTF : |%2.10s|\n", "samsung");
	ft_printf("17) Mon PRINTF  : |%2.10s|\n", "samsung");
	printf("18) Vrai PRINTF : |%2.5s|\n", "printf");
	ft_printf("18) Mon PRINTF  : |%2.5s|\n", "printf");
	printf("19) Vrai PRINTF : |%-10.2s|\n", "424242424242");
	ft_printf("19) Mon PRINTF  : |%-10.2s|\n", "424242424242");
	printf("20) Vrai PRINTF : |%1.0s|\n", "123456789");
	ft_printf("20) Mon PRINTF  : |%1.0s|\n", "123456789");
	printf("20) Vrai PRINTF : |%-1.0s|\n", "123456789");
	ft_printf("20) Mon PRINTF  : |%-1.0s|\n", "123456789");
	printf("21) Vrai PRINTF : |%s|\n", NULL);
	ft_printf("21) Mon PRINTF  : |%s|\n", NULL);
	printf("22) Vrai PRINTF : |%10s|\n", NULL);
	ft_printf("22) Mon PRINTF  : |%10s|\n", NULL);
	printf("23) Vrai PRINTF : |%-10s|\n", NULL);
	ft_printf("23) Mon PRINTF  : |%-10s|\n", NULL);
	printf("24) Vrai PRINTF : |%.2s|\n", NULL);
	ft_printf("24) Mon PRINTF  : |%.2s|\n", NULL);
	printf("25) Vrai PRINTF : |%10.8s|\n", NULL);
	ft_printf("25) Mon PRINTF  : |%10.8s|\n", NULL);
	printf("26) Vrai PRINTF : |%10.2s|\n", NULL);
	ft_printf("26) Mon PRINTF  : |%10.2s|\n", NULL);
	printf("27) Vrai PRINTF : |%2.10s|\n", NULL);
	ft_printf("27) Mon PRINTF  : |%2.10s|\n", NULL);
	printf("28) Vrai PRINTF : |%2.5s|\n", NULL);
	ft_printf("28) Mon PRINTF  : |%2.5s|\n", NULL);
	printf("29) Vrai PRINTF : |%-10.2s|\n", NULL);
	ft_printf("29) Mon PRINTF  : |%-10.2s|\n", NULL);
	printf("30) Vrai PRINTF : |%1.0s|\n", NULL);
	ft_printf("30) Mon PRINTF  : |%1.0s|\n", NULL);
	printf("31) Vrai PRINTF : |%-1.0s|\n", NULL);
	ft_printf("31) Mon PRINTF  : |%-1.0s|\n", NULL);
	printf("32) Vrai PRINTF : |%s| |%s| |%s| |%s| |%s|\n", "Bonjour", "ceci", "est", "un", "test");
	ft_printf("32) Mon PRINTF  : |%s| |%s| |%s| |%s| |%s|\n", "Bonjour", "ceci", "est", "un", "test");
	printf("33) Vrai PRINTF : |%s| |%10s| |%.3s| |%-10s| |%-.5s|\n", "Bonjour", "ceci", "estttttt", "un", "test");
	ft_printf("33) Mon PRINTF  : |%s| |%10s| |%.3s| |%-10s| |%-.5s|\n", "Bonjour", "ceci", "estttttt", "un", "test");
	printf("34) Vrai PRINTF : |%s| |%s| |%s| |%-s| |%s|\n", NULL, NULL, NULL, NULL, NULL);
	ft_printf("35) Mon PRINTF  : |%s| |%s| |%s| |%s| |%s|\n", NULL, NULL, NULL, NULL, NULL);
	printf("35) Vrai PRINTF : |%s| |%10s| |%.3s| |%-10s| |%-.5s|\n", NULL, NULL, NULL, NULL, NULL);
	ft_printf("35) Mon PRINTF  : |%s| |%10s| |%.3s| |%-10s| |%-.5s|\n", NULL, NULL, NULL, NULL, NULL);
	ft_printf("--------------------%%p--------------------\n");
	printf("01) Vrai PRINTF : |%p|\n", "salut");
	ft_printf("01) Mon PRINTF  : |%p|\n", "salut");
	printf("02) Vrai PRINTF : |%-p|\n", tab2);
	ft_printf("02) Mon PRINTF  : |%-p|\n", tab2);
	printf("03) Vrai PRINTF : |%---------p|\n", "test2");
	ft_printf("03) Mon PRINTF  : |%----------p|\n", "test2");
	printf("04) Vrai PRINTF : |%10p|\n", "42");
	ft_printf("04) Mon PRINTF  : |%10p|\n", "42");
	printf("05) Vrai PRINTF : |%-10p|\n", "42");
	ft_printf("05) Mon PRINTF  : |%-10p|\n", "42");
	printf("06) Vrai PRINTF : |%2p|\n", tab);
	ft_printf("06) Mon PRINTF  : |%2p|\n", tab);
	printf("07) Vrai PRINTF : |%-2p|\n", tab);
	ft_printf("07) Mon PRINTF  : |%-2p|\n", tab);
	printf("11) Vrai PRINTF : |%p|\n", "\0\0\0\0\0");
	ft_printf("11) Mon PRINTF  : |%p|\n", "\0\0\0\0\0");
	printf("12) Vrai PRINTF : |%20p|\n", "\0\0\0\0\0");
	ft_printf("12) Mon PRINTF  : |%20p|\n", "\0\0\0\0\0");
	printf("13) Vrai PRINTF : |%p|\n", "");
	ft_printf("13) Mon PRINTF  : |%p|\n", "");
	printf("14) Vrai PRINTF : |%p|\n", NULL);
	ft_printf("14) Mon PRINTF  : |%p|\n", NULL);
	printf("15) Vrai PRINTF : |%10p|\n", NULL);
	ft_printf("15) Mon PRINTF  : |%10p|\n", NULL);
	printf("16) Vrai PRINTF : |%-10p|\n", NULL);
	ft_printf("16) Mon PRINTF  : |%-10p|\n", NULL);
	printf("17) Vrai PRINTF : |%p| |%p| |%p| |%p| |%p|\n", "Bonjour", "ceci", "est", "un", "test");
	ft_printf("17) Mon PRINTF  : |%p| |%p| |%p| |%p| |%p|\n", "Bonjour", "ceci", "est", "un", "test");
	printf("18) Vrai PRINTF : |%p| |%10p| |%p| |%-10p| |%-p|\n", "Bonjour", "ceci", "estttttt", "un", "test");
	ft_printf("18) Mon PRINTF  : |%p| |%10p| |%p| |%-10p| |%-p|\n", "Bonjour", "ceci", "estttttt", "un", "test");
	printf("19) Vrai PRINTF : |%p| |%p| |%p| |%-p| |%p|\n", NULL, NULL, NULL, NULL, NULL);
	ft_printf("19) Mon PRINTF  : |%p| |%p| |%p| |%p| |%p|\n", NULL, NULL, NULL, NULL, NULL);
	printf("20) Vrai PRINTF : |%p| |%10p| |%p| |%-10p| |%-p|\n", NULL, NULL, NULL, NULL, NULL);
	ft_printf("20) Mon PRINTF  : |%p| |%10p| |%p| |%-10p| |%-p|\n", NULL, NULL, NULL, NULL, NULL);
	free(tab);
	free(tab2);
	return (0);
	
}
