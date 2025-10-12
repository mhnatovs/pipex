# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 10:46:26 by mhnatovs          #+#    #+#              #
#    Updated: 2025/07/31 17:05:36 by mhnatovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRC			= ft_printf.c \
			ft_utils.c

OBJ			= $(SRC:.c=.o)

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= cc

FLAGS		= -Wall -Wextra -Werror -I./libft/

all:		$(NAME)


$(NAME):	$(OBJ)
		$(MAKE) -C $(LIBFT_DIR)
		cp $(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJ)

clean:
		$(MAKE) -C $(LIBFT_DIR) clean
		rm -f $(OBJ)
		
fclean:	clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re