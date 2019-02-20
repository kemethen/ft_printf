   /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:05:04 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/14 16:06:01 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT__PRINTF__H
# define FT__PRINTF__H

# include <stdarg.h>
# include "./libft/libft.h"

typedef struct	s_var
{
	size_t	i;
	size_t	j;
	char	*str;
}				t_var;

int			ft_printf(const char *str, ...);
void		percent_p(va_list ap);
void		percent_o(va_list ap);
void		percent_u(va_list ap);
void		hexa_pointer(unsigned long value);
void		hexa_up(unsigned int value);
void		hexa_low(unsigned int value);
size_t	percent_h(const char *str, va_list ap, size_t i, size_t j);
void		hexa_low_us(unsigned short value);
void		hexa_up_us(unsigned short value);
void 		percent_hho(va_list ap);
void		hexa_low_uc(unsigned char value);
void		hexa_up_uc(unsigned char value);
size_t  percent_l(char const *str, va_list ap, size_t i, size_t j);
void		hexa_low_ul(unsigned long value);
void		hexa_up_ul(unsigned long value);

#endif
