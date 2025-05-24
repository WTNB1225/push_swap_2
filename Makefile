# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/25 00:26:00 by wyuki             #+#    #+#              #
#    Updated: 2025/05/25 00:26:01 by wyuki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC_PATH = src/
INCS = -I ./includes/

SRC = push_swap.c \
	error.c \
	validate_args.c \
	init.c \
	sort_utils.c \
	stack_utils.c \
	stack.c \
	sort.c \
	reverse_rotate.c \
	rotate.c \
	push.c \
	swap.c \


SRCS = $(addprefix $(SRC_PATH), $(SRC))


.PHONY: all clean fclean re

$(NAME):
	make -C ./libft re
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(INCS) -L ./libft -lft

all: $(NAME)

clean:
	make -C ./libft clean

fclean: clean
	make -C ./libft fclean
	rm -r $(NAME)

re: fclean all
