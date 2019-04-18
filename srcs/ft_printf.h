/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:05:04 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/18 19:10:16 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef struct	s_var
{
	size_t	i;
	size_t	j;
	size_t	bzero;
	size_t	bzerocheck;
	size_t	percent;
	int		width;
	int		prc;
	int		len;
	int		len2;
	int		size;
	int		size2;
	int		dot;
	int		neg;
	int		mns;
	int		plus;
	int		space;
	int		nbr;
	int		zero;
	int		d;
	char	*str;
	char	*length;
	char	*tmp;
	char	*tmp2;
	char	*prwd;
	char	*buff;
}				t_var;

int				ft_printf(const char *str, ...);
int				main(void);
void			fillbuff(t_var *v);
void			reset_v(t_var *v);
char			*joinfree(char *s1, char *s2);
void			iszero(t_var *v, char *str, char c);
size_t			percent_c(t_var *v, char c, size_t i, size_t j);
size_t			percent_s(t_var *v, char *str, size_t i, size_t j);
void			percent_p(va_list ap, t_var *v);
void			percent_space(const char *str, t_var *v);
void			percent_sign(const char *str, t_var *v);
void			percent_dot(const char *str, t_var *v);
void			precision(t_var *v);
void			vplus(t_var *v);
void			percent_nbr(const char *str, t_var *v);
void			width(t_var *v);
void			pr_or_wd(t_var *v);
void			pr_or_wd_ltr(t_var *v);
void			pr_and_wd(t_var *v);
void			pr_and_wd_neg(t_var *v);
void			pr_or_wd_sharp(t_var *v, char c);
void			pr_and_wd_sharp(t_var *v, char c);
void			wd_prc_neg(t_var *v);
void			percent_d_and_i(int nb, t_var *v);
void			percent_ld_and_li(long long nb, t_var *v);
void			percent_u(unsigned int value, t_var *v);
void			percent_lu(unsigned long value, t_var *v, const char *str);
void			percent_o(unsigned int value, t_var *v);
void			percent_lo(unsigned long value, t_var *v);
size_t			percent_sharp(const char *str, va_list ap, t_var *v);
void			percent_sharp_o(unsigned int value, t_var *v);
void			percent_sharp_lo(unsigned long long value, t_var *v);
size_t			mbase_eight(unsigned int n);
size_t			mbase_eight_ll(unsigned long n);
int				msize_hexa_int(unsigned int n);
size_t			msize_hexa_ul(unsigned long n);
char			*hexa_pointer(unsigned long value);
void			hexa_up(unsigned int value, t_var *v);
void			hexa_up_sharp(unsigned int value, t_var *v);
void			hexa_up_lsharp(unsigned long value, t_var *v);
void			precision_sharp_up(t_var *v);
void			width_sharp_up(t_var *v);
void			hexa_low(unsigned int value, t_var *v);
void			hexa_low_sharp(unsigned long value, t_var *v);
void			hexa_low_lsharp(unsigned long value, t_var *v);
void			precision_sharp_low(t_var *v);
void			width_sharp_low(t_var *v);
void			percent_f(const char *str, va_list ap, t_var *v);
size_t			msize_float(float n);
void			percent_percent(t_var *v);
size_t			percent_h(const char *str, va_list ap, t_var *v);
size_t			percent_l(char const *str, va_list ap, t_var *v);
void			hexa_low_ul(unsigned long value, t_var *v);
void			hexa_up_ul(unsigned long value, t_var *v);
size_t			printf_return(t_var *v);
size_t			len_buff(t_var *v);
size_t			len_str(t_var *v);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
char			*ft_itoa(int n);
char			*ft_lltoa(long long n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
char			*ft_strcpy(char	*dest, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strndup(char *s1, int n);
char			*ft_strnew(size_t size);
char			*ft_strrev(char *str);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_uitoa(unsigned int n);
char			*ft_ultoa(unsigned long n);

#endif
