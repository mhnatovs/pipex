# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 09:22:52 by mhnatovs          #+#    #+#              #
#    Updated: 2025/07/31 15:40:02 by mhnatovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRC				= ft_putchar.c \
				ft_putnbr.c \
				ft_strlen.c \
				ft_putstr.c

OBJ				= $(SRC:.c=.o)

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

$(NAME):		$(OBJ)
		ar rcs $(NAME) $(OBJ)

all:			$(NAME)

clean:
		rm -f $(OBJ)

fclean:			clean
		rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
