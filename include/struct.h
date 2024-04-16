/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:55:30 by albartol          #+#    #+#             */
/*   Updated: 2024/04/15 14:46:22 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../lib/libft/libft.h"
# include <term.h>

// colors for printing text in the terminal
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[1;97m"
# define RESET "\033[0m"
# define ORANGE "\033[38;5;208m"

# define PROMPT "\033[1;31mminishell\033[1;97m:\033[1;34m"
# define DELIMITATOR "\033[1;97m$ \033[0m"

# define STDIN STDIN_FILENO
# define STDOUT STDOUT_FILENO
# define STDERR STDERR_FILENO

# define FILE_PERM 0644
# define TRUNC 1
# define APPEND 2
# define INPUT 3
# define HERE_DOC 4
# define HERE_DOC_PATH "/tmp/."

# define EXIT_PROGRAM 42

typedef unsigned char	t_exit;
typedef struct termios	t_conf;
typedef struct s_shell	t_shell;
typedef struct s_pipe	t_pipe;
typedef struct s_redir	t_redir;

struct s_redir
{
	char	*com;
	char	*file_name;
	int		type;
	int		success;
};

struct s_pipe
{
	char	*com;
	char	**argv;
	t_redir	input;
	t_redir	output;
	int		fd[2];
	pid_t	pid;
};

struct s_shell
{
	t_list	*env;
	char	*input;
	t_pipe	*com;
	int		com_len;
	int		child;
	t_conf	conf;
	t_exit	exit_code;
};

#endif
