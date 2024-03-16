# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 18:53:11 by albartol          #+#    #+#              #
#    Updated: 2024/03/16 12:17:34 by flopez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

CC := gcc

# CFLAGS := -Wall -Wextra -Werror -O3
# CFLAGS := -Wall -Wextra -fsanitize=address -g3
CFLAGS := -Wall -Wextra

LIBS := -lreadline -Llib/libft -lft

INCLUDE := -I include

ifeq ($(UNAME), Darwin)
	LIBS := -Llib/libft -lft -L/Users/$(USER)/.brew/opt/readline/lib -lreadline
	INCLUDE := -I/Users/$(USER)/.brew/opt/readline/include -I include
endif

SRC_DIR		:= src
OBJ_DIR		:= obj
UTILS_DIR	:= utils

# SOURCES
SOURCES :=	minishell.c \
			ft_minishell_init.c \
			ft_minishell_loop.c \
			ft_get_command.c \
			ft_exec_command.c

# UTILS
UTILITIES :=	ft_isnotprint.c \
				ft_strlenchr.c \
				ft_update_prompt.c \

UTILS_FREE :=	free/free_input.c \
				free/free_program.c \
				free/ft_exit_program.c \
				free/ft_free_array.c \
				free/ft_free_env.c \

UTILS_ENV :=	env/ft_get_env_value.c \
				env/ft_set_env_value.c

UTILS_ARR :=	array/array_len.c \
				array/array_char_len.c \
				array/array_to_str.c

# BUILT-INS
BUILTS :=	built-ins/ft_pwd.c \
			built-ins/ft_cd.c \
			built-ins/ft_env.c \
			built-ins/ft_echo.c \
			built-ins/ft_exit.c

# PARSER
PARSER :=	parser/ft_parser.c \
			parser/ft_quotes_input.c \
			parser/ft_trim_input.c

# EXECUTOR
EXECUTOR :=	executor/ft_check_bin.c \
			executor/ft_exec_bin.c

# SIGNALS
SIGNALS :=	signals/ft_handle_signals.c

ALL_UTILS := $(UTILITIES) $(UTILS_FREE) $(UTILS_ENV) $(UTILS_ARR)

UTILS := $(addprefix $(UTILS_DIR)/, $(ALL_UTILS))

SRC := $(SOURCES) $(BUILTS) $(UTILS) $(PARSER) $(SIGNALS) $(EXECUTOR)
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
	mkdir -p $(OBJ_DIR)/$(UTILS_DIR)
	mkdir -p $(OBJ_DIR)/$(UTILS_DIR)/env
	mkdir -p $(OBJ_DIR)/$(UTILS_DIR)/free
	mkdir -p $(OBJ_DIR)/$(UTILS_DIR)/array
	mkdir -p $(OBJ_DIR)/built-ins
	mkdir -p $(OBJ_DIR)/parser
	mkdir -p $(OBJ_DIR)/signals
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
