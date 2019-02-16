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

void	percent_p(va_list ap);
void	percent_o(va_list ap);
void	percent_u(va_list ap);

#endif
