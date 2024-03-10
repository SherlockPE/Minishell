# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 18:53:11 by albartol          #+#    #+#              #
#    Updated: 2024/03/09 12:38:19 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=gcc

CFLAGS:=-Wall -Wextra -Werror -O3

LIBS:=-lreadline -Llib/libft -lft

SRC:=minishell.c \
	ft_isnotprint.c \
	ft_print_error.c \
	ft_minishell_loop.c \
	ft_get_command.c \
	ft_exec_command.c \
	ft_pwd.c \
	ft_cd.c

SRC_DIR:=src

OBJ_DIR:=obj

SRCS:=$(SRC:%.c=$(SRC_DIR)/%.c)

OBJS:=$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME:=minishell

LIBFT:=lib/libft/libft.a

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C lib/libft

clean:
	$(MAKE) clean -C lib/libft
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C lib/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
# .SILENT: all fclean clean re $(NAME)
