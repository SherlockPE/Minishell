# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 11:42:34 by albartol          #+#    #+#              #
#    Updated: 2024/03/05 19:12:06 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=gcc

CFLAGS:=-Wall -Wextra -Werror -O3

SRC=ft_atoi.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strchr.c  ft_strlcpy.c \
ft_strnstr.c ft_toupper.c ft_calloc.c ft_isascii.c ft_memchr.c ft_memmove.c \
ft_strdup.c ft_strlen.c ft_strrchr.c ft_bzero.c ft_isalnum.c ft_isdigit.c \
ft_memcmp.c ft_memset.c ft_strlcat.c ft_strncmp.c ft_tolower.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c ft_tolower.c ft_striteri.c \
\
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
\
get_next_line.c \
\
ft_printf.c ft_putstr_n.c ft_putchar_n.c ft_putnbr_n.c ft_putnbr_base_n.c \
ft_putptr_n.c \
\
ft_merge_sort.c ft_quick_sort.c\
\
ft_charjoin.c \
\
ft_atol.c ft_atoll.c

NAME=libft.a

OBJ_DIR=obj

OBJ=$(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	ar -rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# .SILENT: all clean fclean re $(NAME) $(OBJ_DIR)