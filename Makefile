# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 13:25:51 by mhnatovs          #+#    #+#              #
#    Updated: 2025/10/12 18:49:59 by mhnatovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I./libft/

SRC				= main.c utils.c split.c errors.c
OBJ				= $(SRC:.c=.o)

LIBFT_DR		= ./libft
LIBFT			= $(LIBFT_DR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DR)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DR)

re:		fclean all

.PHONY:	all clean fclean re