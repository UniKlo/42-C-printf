#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/22 00:09:34 by khou              #+#    #+#              #
#    Updated: 2018/09/22 00:09:43 by khou             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
CFLAG = -g -Wall -Werror -Wextra -c
SRC = $(wildcard *.c)
OFILES = *.o

all: $(NAME)

$(NAME): $(SRC)
		@gcc $(CFLAG) $(SRC)
		@ar rc $(NAME) $(OFILES)

clean:
		@/bin/rm -f $(OFILES)

fclean: clean
		@/bin/rm -f $(NAME)
		@/bin/rm -f *~
		@/bin/rm -f \#*\#

re: fclean all

.PHONY: clean fclean all re
