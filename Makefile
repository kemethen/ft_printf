# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 17:52:06 by kemethen          #+#    #+#              #
#    Updated: 2019/02/21 18:27:48 by kemethen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= gcc
CFLAGS += -Wall -Wextra -Werror
AR      = ar
ARFLAGS = -rcs
SRCDIR	= srcs
OBJDIR	= obj
LIBDIR	= libft
INCDIR	= $(LIBDIR)

HEAD	= $(SRCDIR)/fillit.h

SRC		= *.c

CFLAGS += -I$(INCDIR)
OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
LIB		= $(LIBDIR)/libft.a

GREEN	= \033[1;32m
PURPLE	= \033[1;35m
RED		= \033[1;31m
YELLOW	= \033[1;33m
BLUE	= \033[1;36m
WHITE	= \033[1;37m

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@echo "\n$(YELLOW)$@ \t$(PURPLE)must be updated with $(WHITE)$(notdir $?)"
	@echo "$(PURPLE)Updating\t$(YELLOW)$@"
	@$(AR) $(ARFLAGS) $@ $?
	@echo "$@ :\t$(GREEN)Indexed / Up to date"

$(LIB):
	@make -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEAD)
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
