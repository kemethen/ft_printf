/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:05:04 by kemethen          #+#    #+#             */
/*   Updated: 2019/03/06 17:08:32 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_var
{
	size_t	i;
	size_t	j;
	int		width;
	int		prc;
	int		len;
	int		len2;
	int		size;
	int		size2;
	char	*str;
	char	*length;
	char	*tmp;
	char	*tmp2;
	char	*buff;
}				t_var;

int				ft_printf(const char *str, ...);
int				main(void);
char			*fillbuff(t_var *v);
size_t			percent_c(t_var *v, char c, size_t i, size_t j);
size_t			percent_s(t_var *v, char *str, size_t i, size_t j);
void			percent_p(va_list ap, t_var *v);
void			percent_dot(const char *str, t_var *v);
void			precision(t_var *v);
void			percent_nbr(const char *str, t_var *v);
void			width(t_var *v);
void			pr_or_wd(t_var *v);
void			percent_d_and_i(int nb, t_var *v);
void			percent_ld_and_li(long long nb, t_var *v);
void			percent_u(unsigned int value, t_var *v);
void			percent_o(unsigned int value, t_var *v);
void			percent_lo(long long value, t_var *v);
size_t			percent_sharp(const char *str, va_list ap, t_var *v);
void			percent_sharp_o(unsigned int value, t_var *v);
size_t			mbase_eight(unsigned long n);
int				msize_hexa_int(unsigned int n);
char			*hexa_pointer(unsigned long value);
void			hexa_up(unsigned int value, t_var *v);
void			hexa_up_sharp(unsigned int value, t_var *v);
void			precision_sharp_up(t_var *v);
void			hexa_low(unsigned int value, t_var *v);
void			hexa_low_sharp(unsigned int value, t_var *v);
void			precision_sharp_low(t_var *v);
void			percent_percent(t_var *v);
size_t			percent_h(const char *str, va_list ap, t_var *v);
size_t			percent_l(char const *str, va_list ap, t_var *v);
void			hexa_low_ul(unsigned long value, t_var *v);
void			hexa_up_ul(unsigned long value, t_var *v);
size_t			len_buff(t_var *v);
size_t			len_str(t_var *v);

#endif
