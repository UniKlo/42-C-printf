#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 18:08:35 by khou              #+#    #+#              #
#    Updated: 2018/09/21 01:03:51 by khou             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

DIR_S = srcs

DIR_O = obj

HEADER = includes

SOURCES = $(wildcard srcs/*.c)

all: $(NAME)

$(NAME): $(SRCS)
#	@make -C libft
#	@cp libft/libft.a ./$(NAME)
#	@cp libft/libft.a ./
#	@$(CC) $(FLAGS) -I $(HEADER) -c $(DIR_S)/*.c
	@$(CC) $(FLAGS) -I $(HEADER) -c $(SOURCES)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean re norme all clean
