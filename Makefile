# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/03 01:33:12 by ywake             #+#    #+#              #
#    Updated: 2020/12/04 03:58:00 by ywake            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= ft_mini_ls
CC		:= gcc
INCLUDES:= -I./Libft
CFLAGS	:= -Wall -Werror -Wextra $(INCLUDES)
SRCS 	:= ft_mini_ls.c
OBJS 	:= $(SRCS:.c=.o)

.PHONY: all clean fclean re test

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C Libft bonus
	$(CC) -o $(NAME) $(OBJS) Libft/libft.a

clean:
	$(MAKE) -C Libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C Libft fclean
	rm -f $(NAME)

re: fclean all

test:
	$(CC) $(INCLUDES) $(SRCS) test.c Libft/libft.a -D TEST -o test_ft_mini_ls
	bash leaks.sh
