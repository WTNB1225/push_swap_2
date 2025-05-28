# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/25 00:26:00 by wyuki             #+#    #+#              #
#    Updated: 2025/05/29 02:55:05 by wyuki            ###   ########.fr        #
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
	utils.c \
	push_swap.c \

BONUS_SRC = error.c \
	init.c \
	sort.c \
	sort_utils.c \
	sort_under_five.c \
	stack.c \
	stack_utils.c \
	utils.c \
	validate_args.c \

SRCS = $(addprefix $(SRC_PATH), $(SRC))

BONUS_SRCS = $(addprefix $(SRC_PATH), $(BONUS_SRC))

BONUS_SRCS += bonus/checker.c bonus/utils.c bonus/swap.c \
			  bonus/rotate.c bonus/reverse_rotate.c \
			  bonus/push.c

.PHONY: all clean fclean re bonus

$(NAME): $(SRCS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(INCS) -L libft -lft

all: $(NAME)

clean:
	make -C ./libft clean

fclean: clean
	make -C ./libft fclean
	rm -r $(NAME) checker

bonus: $(BONUS_SRCS)
	make -C ./libft
	$(CC) $(CFLAGS) -o checker $(BONUS_SRCS) $(INCS) -L libft -lft

re: fclean all
