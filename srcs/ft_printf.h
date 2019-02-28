/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:05:04 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/27 18:21:13 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_var
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*tmp;
	char	*buff;
}				t_var;

int				main(void);
int				ft_printf(const char *str, ...);
char			*fillbuff(t_var *v);
size_t			percent_c(t_var *v, char c, size_t i, size_t j);
size_t			percent_s(t_var *v, char *str, size_t i, size_t j);
void			percent_p(va_list ap, t_var *v);
void			percent_d_and_i(int nb, t_var *v);
void			percent_o(unsigned int value, t_var *v);
void			percent_u(unsigned int nb, t_var *v);
char			*hexa_pointer(unsigned long value);
void			hexa_up(unsigned int value);
void			hexa_low(unsigned int value);
size_t			percent_h(const char *str, va_list ap, size_t i, size_t j);
void			hexa_low_us(unsigned short value);
void			hexa_up_us(unsigned short value);
void			percent_hho(unsigned char value);
void			hexa_low_uc(unsigned char value);
void			hexa_up_uc(unsigned char value);
size_t			percent_l(char const *str, va_list ap, t_var *v);
void			hexa_low_ul(unsigned long value);
void			hexa_up_ul(unsigned long value);
size_t			len_buff(t_var *v);
size_t			len_str(t_var *v);

#endif
