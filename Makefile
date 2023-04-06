# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atucci <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 09:57:17 by atucci            #+#    #+#              #
#    Updated: 2023/04/06 15:03:22 by atucci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client
NAME2 = server

SRCS1 = client.c
SRCS2 = server.c

LIBFT = libft/libft.a
LIBFT_DIR = libft

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME1) $(NAME2)

$(NAME1): $(SRCS1) $(LIBFT)
	$(CC) $(CFLAGS) -L $(LIBFT_DIR) -lft $(SRCS1) -o $(NAME1)

$(NAME2): $(SRCS2) $(LIBFT)
	$(CC) $(CFLAGS) -L $(LIBFT_DIR) -lft $(SRCS2) -o $(NAME2)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	${RM} ${NAME1} ${NAME2}
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)
	make -C $(LIBFT_DIR) fclean

re: fclean all

