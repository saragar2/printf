# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 20:32:38 by saragar2          #+#    #+#              #
#    Updated: 2023/11/30 20:32:43 by saragar2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf_pxX.c ft_printf_c.c ft_printf_s.c ft_printf_d.c ft_printf_u.c ft_printf.c ft_printf_perc.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
CC = cc

all : $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all
