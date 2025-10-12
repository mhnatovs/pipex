# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 13:25:51 by mhnatovs          #+#    #+#              #
#    Updated: 2025/10/12 15:27:06 by mhnatovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g -I./libft/
SRC				= main.c utils.c split.c errors.c
OBJ				= $(SRC:.c=.o)
LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:		fclean all

.PHONY:	all clean fclean re