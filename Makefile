# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/25 00:26:00 by wyuki             #+#    #+#              #
#    Updated: 2025/05/26 01:45:18 by wyuki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC_PATH = src/
INCS = -I ./includes/

SRC = error.c \
	init.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	sort.c \
	sort_utils.c \
	sort_under_five.c \
	stack.c \
	stack_utils.c \
	swap.c \
	validate_args.c \
	push_swap.c \


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
