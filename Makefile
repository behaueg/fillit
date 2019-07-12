# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/28 10:34:24 by behaudeg          #+#    #+#              #
#    Updated: 2019/06/28 10:34:26 by behaudeg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRC		=	src/checker.c \
			src/main.c \
			src/tetriminos.c \
			src/get_next_line.c


OBJ		= $(patsubst src/%.c,./%.o,$(SRC))

INCLUDE	= includes/fillit.h \
		  includes/libft.h \
		  includes/get_next_line.h

.SILENT:

$(NAME): $(OBJ)
	gcc -Wall -Werror -Wextra $(OBJ) -L libft/ -o $(NAME)
	printf '\033[4m'
	printf '\033[32m[ ✔ ] %s\n\033[0m' "fillit is done !"
./%.o: src/%.c
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf *.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all