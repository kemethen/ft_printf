# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 17:52:06 by kemethen          #+#    #+#              #
#    Updated: 2019/04/15 14:46:28 by kemethen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= gcc
CFLAGS  = -Wall -Wextra -Werror -g3
AR      = ar
ARFLAGS = -rcs
SRCDIR	= srcs
OBJDIR	= obj

HEAD	= ft_printf.h

SRC		=	ft_printf.c \
			percent_csdi.c \
			percent_h.c \
			percent_l.c \
			percent_ldlilolu.c \
			percent_lxu.c \
			percent_p_and_o.c \
			percent_sharp_lo_and_lx.c \
			percent_sharp_o_and_x.c \
			percent_sharp.c \
			percent_sign_nbr.c \
			percent_x.c \
			pr_and_wd.c \
			precision.c \
			printf_return.c \
			width.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_itoa.c \
			ft_lltoa.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strcpy.c \
			ft_strlen.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strnew.c \
			ft_strrev.c \
			ft_strsub.c \
			ft_uitoa.c \
			ft_ultoa.c

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
PURPLE	= \033[1;35m
BLUE	= \033[1;36m
WHITE	= \033[1;37m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n$(YELLOW)$@ \t$(PURPLE)must be updated with $(WHITE)$(notdir $?)"
	@echo "$(PURPLE)Updating\t$(YELLOW)$@"
	@$(AR) $(ARFLAGS) $@ $?
	@echo "$@ :\t$(GREEN)Indexed / Up to date"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/$(HEAD)
	@echo "$(PURPLE)Updating\t$(WHITE)$@"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	@echo "$(GREEN)Creating\t$(WHITE)directory $(BLUE)'$@'\n"
	@mkdir $@

clean:
	@echo "$(RED)Deleting\t$(WHITE)directory $(BLUE)'$(OBJDIR)'"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Deleting\t$(YELLOW)$(NAME)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
