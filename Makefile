# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 17:52:06 by kemethen          #+#    #+#              #
#    Updated: 2019/03/02 18:36:01 by kemethen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= gcc
CFLAGS += -Wall -Wextra -Werror
AR      = ar
ARFLAGS = rcs
SRCDIR	= srcs
OBJDIR	= obj
LIBDIR	= libft
INCDIR	= $(LIBDIR)

HEAD	= ft_printf.h

SRC		=	ft_printf.c \
			percent_c_and_s.c \
			percent_d_and_i.c \
			percent_h.c \
			percent_l.c \
			percent_ld_and_li.c \
			percent_lo.c \
			percent_p_and_o.c \
			percent_percent.c \
			percent_x.c \
			printf_return.c

CFLAGS += -I$(INCDIR)
OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
LIB		= $(LIBDIR)/libft.a

RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
PURPLE	= \033[1;35m
BLUE	= \033[1;36m
WHITE	= \033[1;37m

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@echo "\n$(YELLOW)$@ \t$(PURPLE)must be updated with $(WHITE)$(notdir $?)"
	@echo "$(PURPLE)Updating\t$(YELLOW)$@"
	@$(AR) $(ARFLAGS) $@ libft/libft.a $?
	@echo "$@ :\t$(GREEN)Indexed / Up to date"

$(LIB):
	@make -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/$(HEAD)
	@echo "$(PURPLE)Updating\t$(WHITE)$@"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	@echo "$(GREEN)Creating\t$(WHITE)directory $(BLUE)'$@'\n"
	@mkdir $@

clean:
	@make -C $(LIBDIR) clean
	@echo "$(RED)Deleting\t$(WHITE)directory $(BLUE)'$(OBJDIR)'"
	@rm -rf $(OBJDIR)

fclean: clean
	@make -C $(LIBDIR) fclean
	@echo "$(RED)Deleting\t$(YELLOW)$(NAME)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(LIB)
