# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 13:25:51 by mhnatovs          #+#    #+#              #
#    Updated: 2025/10/12 15:48:28 by mhnatovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g -I./libft/

SRC				= main.c utils.c split.c errors.c
OBJ				= $(SRC:.c=.o)

LIBFT			= ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean:	clean
	rm -f $(NAME)
	make fclean -C libft

re:		fclean all

.PHONY:	all clean fclean re