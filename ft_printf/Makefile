# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 12:36:11 by rrabeari          #+#    #+#              #
#    Updated: 2024/07/30 13:39:26 by rrabeari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_printf.c \
		ft_putchar_printf.c \
		ft_putnbr_printf.c \
		ft_putstr_printf.c \
		ft_strchr_printf.c \
		ft_strlen_printf.c \
		ft_puthexa.c \
		ft_write.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(SRC)
	cc -c -Wall -Werror -Wextra $(SRC)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
