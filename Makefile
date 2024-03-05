# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 18:53:11 by albartol          #+#    #+#              #
#    Updated: 2024/03/05 19:35:19 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

CFLAGS:=-Wall -Wextra -Werror -O3

SRC=src/minishell.c

OBJ=$(SRC:%.c=%.o)

NAME=minishell

LIBFT=lib/libft/libft.a

all: $(NAME)

$(NAME): include/minishell.h $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -Llib/libft -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C lib/libft

clean:
	$(MAKE) clean -C lib/libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C lib/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
# .SILENT: all fclean clean re $(NAME)