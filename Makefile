# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 18:53:11 by albartol          #+#    #+#              #
#    Updated: 2024/03/11 18:43:14 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

CC:=gcc

CFLAGS:=-Wall -Wextra -Werror -O3

LIBS:=-lreadline -Llib/libft -lft

INCLUDE:=-I include

ifeq ($(UNAME), Darwin)
	LIBS:=-Llib/libft -lft -L/Users/$(USER)/.brew/opt/readline/lib -lreadline
	INCLUDE:=-I/Users/$(USER)/.brew/opt/readline/include -I include
endif

SRC:=minishell.c \
	ft_minishell_loop.c \
	ft_get_command.c \
	ft_exec_command.c \
	utils/ft_isnotprint.c \
	built-ins/ft_pwd.c \
	built-ins/ft_cd.c

SRC_DIR:=src

OBJ_DIR:=obj

SRCS:=$(SRC:%.c=$(SRC_DIR)/%.c)

OBJS:=$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME:=minishell

LIBFT:=lib/libft/libft.a

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

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
