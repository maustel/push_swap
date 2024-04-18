# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 12:44:05 by maustel           #+#    #+#              #
#    Updated: 2024/02/14 12:44:05 by maustel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
TEST = test
FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

LIB_PATH = -C ./libft

SRCS =	main.c \
		node_utils.c \
		operator.c \
		radix_sort.c \
		parsing.c \
		helper.c \
		little_sort.c \
		cont_relative.c

all:	$(NAME)

$(LIBFT):
	$(MAKE) $(LIB_PATH)

$(NAME): $(LIBFT) ./push_swap.h $(SRCS)
		cc $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)

fclean:
	rm -f $(NAME)
	$(MAKE) $(LIB_PATH) fclean

clean:
	$(MAKE) $(LIB_PATH) clean

re:	fclean all

.PHONY: all fclean clean re
