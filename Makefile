# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 15:14:20 by smdyan            #+#    #+#              #
#    Updated: 2021/12/29 01:25:16 by smdyan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

NAME_LIBFT = libft.a

LIBFT = ./libft

SRC = ft_printf.c utils.c print_char.c print_nbr.c print_str.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(LIBFT) -MD

include $(wildcard *.d)

$(NAME): $(OBJ) 
	make all -C $(LIBFT)
	cp $(LIBFT)/$(NAME_LIBFT) $(NAME)
	ar rc $(NAME) $?
	ranlib $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(wildcard *.d)
	make clean -C $(LIBFT)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

bonus:	re

.PHONY: all clean fclean re bonus
