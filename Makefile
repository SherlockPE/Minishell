# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 18:53:11 by albartol          #+#    #+#              #
#    Updated: 2024/03/15 14:54:32 by flopez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

CC := gcc

# CFLAGS := -Wall -Wextra -Werror -O3
CFLAGS := -Wall -Wextra

LIBS := -lreadline -Llib/libft -lft

INCLUDE := -I include

ifeq ($(UNAME), Darwin)
	LIBS := -Llib/libft -lft -L/Users/$(USER)/.brew/opt/readline/lib -lreadline
	INCLUDE := -I/Users/$(USER)/.brew/opt/readline/include -I include
endif

SOURCES :=	minishell.c \
			ft_minishell_init.c \
			ft_minishell_loop.c \
			ft_get_command.c \
			ft_exec_command.c

UTILS :=	utils/ft_isnotprint.c \
			utils/ft_free_env.c \
			utils/ft_free_array.c \
			utils/ft_strlenchr.c \
			utils/ft_get_env_value.c \
			utils/ft_get_prompt.c \
			utils/ft_set_env_value.c


BUILTS :=	built-ins/ft_pwd.c \
			built-ins/ft_cd.c \
			built-ins/ft_env.c \
			built-ins/ft_echo.c

PARSER :=	parser/ft_parser.c

EXECUTOR :=	executor/ft_check_bin.c \
			executor/ft_exec_bin.c

SRC := $(SOURCES) $(BUILTS) $(UTILS) $(PARSER) $(EXECUTOR)

SRC_DIR := src

OBJ_DIR := obj

SRCS := $(addprefix $(SRC_DIR)/, $(SRC))

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME := minishell

LIBFT := lib/libft/libft.a

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/utils
	mkdir -p $(OBJ_DIR)/built-ins
	mkdir -p $(OBJ_DIR)/parser
	mkdir -p $(OBJ_DIR)/executor

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
