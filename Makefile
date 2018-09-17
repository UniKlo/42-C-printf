#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 18:08:35 by khou              #+#    #+#              #
#    Updated: 2018/09/16 20:23:54 by khou             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O2

DIR_S = srcs

DIR_O = obj

HEADER = include

SOURCES = ft_printf.c \
			parse.c \
			grab_flag.c\
			p_diuoxX.c\

SRCS = $(addprefix $(DIR_S)/, $(SOURCES))

OBJS = $(addprefix $(DIR_O)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

test: $(SRCS)
	@make -C libft
	@$(CC) libft/libft.a -I $(HEADER) -g $(SRCS) srcs/main.c

test01: $(SRCS)
	@make -C libft
	@$(CC) libft/libft.a -I $(HEADER) -g $(SRCS) srcs/main01.c

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C libft
	@echo "cleaned up objects"

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f \#*\#
	@rm -f srcs/*~
	@rm -f srcs/\#*\#
	@rm -f a.out
	@rm -rf *dSYM
	@make fclean -C libft
	@echo "reset"

re: fclean all

.PHONY: fclean re norme all clean
