# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xeniaherzi <xeniaherzi@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 08:30:21 by xeniaherzi        #+#    #+#              #
#    Updated: 2023/09/20 08:34:28 by xeniaherzi       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
DIR		= srcs/
CC		= gcc
FLAGS	= -Wall -Wextra -Werror

SRCS = $(DIR)checks.c \
	$(DIR)logic.c \
	$(DIR)main.c \
	$(DIR)min_max.c \
	$(DIR)move.c \
	$(DIR)node.c \
	$(DIR)push_split.c \
	$(DIR)rotations.c \
	$(DIR)sort.c \
	$(DIR)swap.c \
	$(DIR)useful_libft.c \
	$(DIR)useful.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

norm:
	norminette -R CheckDefine

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re norm