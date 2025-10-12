# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 17:00:43 by mhnatovs          #+#    #+#              #
#    Updated: 2025/07/21 10:31:34 by mhnatovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRC				= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
				ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
				ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c

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