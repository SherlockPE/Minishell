# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 18:53:11 by albartol          #+#    #+#              #
#    Updated: 2024/03/05 19:08:26 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

CFLAGS:=-Wall -Wextra -Werror -O3

SRC=src/minishell.c

OBJ=$(SRC:%.c=%.o)

NAME=minishell

LIBFT=lib/libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C lib/libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -Llib/libft -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C lib/libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C lib/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
# .SILENT: all fclean clean re $(NAME)