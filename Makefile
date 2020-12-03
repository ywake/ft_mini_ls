# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/03 01:33:12 by ywake             #+#    #+#              #
#    Updated: 2020/12/04 02:48:40 by ywake            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= ft_mini_ls
CC		:= gcc
INCLUDES:= -I./Libft
CFLAGS	:= -Wall -Werror -Wextra $(INCLUDES)
SRCS 	:= ft_mini_ls.c
OBJS 	:= $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C Libft
	$(CC) $(OBJS) -o $(NAME) Libft/libft.a

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
