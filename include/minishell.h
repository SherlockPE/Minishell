/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:58:51 by albartol          #+#    #+#             */
/*   Updated: 2024/04/02 20:17:43 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// for printf, readline, perror
# include <stdio.h>
// for strerror
# include <string.h>
// for malloc, free, exit, getenv
# include <stdlib.h>
// for write, access, close, read, getcwd, chdir,
// unlink, execve, dup, dup2, pipe, isatty, ttyname, ttyslot
# include <unistd.h>
// stat, lstat, fstat
# include <sys/stat.h>
// for read, wait3, wait4
# include <sys/types.h>
// for read
# include <sys/uio.h>
// for open
# include <fcntl.h>
// for signal, sigaction, kill
# include <signal.h>
// for fork, kill
# include <sys/types.h>
// for waitpid, wait, waitpid, wait3, wait4
# include <sys/wait.h>
// for wait3, wait4
# include <sys/time.h>
// for wait3, wait4
# include <sys/resource.h>
// for readline, rl_on_new_line, rl_redisplay, add_history
# include <readline/readline.h> /* rl_clear_history, rl_redisplay ? */
// for readline, rl_on_new_line, rl_redisplay, add_history
# include <readline/history.h> /* rl_clear_history, rl_redisplay ? */
// for opendir, readdir, closedir
# include <dirent.h>
// for ioctl
# include <sys/ioctl.h>
// for tcsetattr, tcgetattr
# include <termios.h>
// for tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <curses.h>
// for tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <term.h>
// for errno
# include <errno.h>

# include "../lib/libft/libft.h"

//      colors for printing text in the terminal
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
# define NON_PRINT " \n\t\v\f\r\b\a\e"

# define FILE_PERM 0644
# define STDERR STDERR_FILENO

typedef unsigned char	t_exit;
typedef struct s_env	t_env;
typedef struct s_shell	t_shell;
typedef struct s_com	t_com;
typedef struct s_redir	t_redir;

struct s_env
{
	char	*name;
	char	*value;
};

struct s_redir
{
	char	*com;
	char	*file_name;
	int		old_stdin;
	int		old_stdout;
	int		success;
	int		type;
};

struct s_com
{
	char	*command;
	char	**argv;
	int		fd[2];
	pid_t	pid;
};

struct s_shell
{
	t_list	*env;
	char	*prompt;
	char	*input;
	char	**pipes;
	t_com	*com;
	t_exit	exit_code;
};

/* ======== MAIN ======== */
// gets the env from where minishell is executed
void	ft_minishell_init(t_shell *data, char **env);

// loops over getting input and executing a command
void	ft_minishell_loop(t_shell *data);

// gets the input of the user with readline and removes whitespaces
void	ft_get_input(t_shell *data);

// executes a command
void	ft_exec_command(t_shell *data);

/* ======== BUILT-INS ======== */
void	ft_cd(t_shell *data);
void	ft_echo(t_shell *data);
void	ft_env(t_shell *data);
void	ft_pwd(void);
void	ft_export(t_shell *data);
void	ft_unset(t_shell *data);
void	ft_exit(t_shell *data);
/* ========================== */

/* ======== EXECUTOR ======== */
char	*ft_check_bin(t_shell *data);
void	child_process_pipe(t_shell *data, char *com);
void	child_process(t_shell *data, char *com);
void	ft_exec_bin(t_shell *data);
void	ft_exec_one(t_shell *data);
void	ft_pipex(t_shell *data);
void	ft_send_com(t_shell *data, char *com, t_com *com_struct);
/* ========================== */

/* ======== PARSE ======== */
void	ft_expansor(t_shell *data);
void	ft_parser(t_shell *data);
void	ft_quotes_input(t_shell *data);
void	ft_trim_input(t_shell *data);
short	ft_val_input(const char *com, const char c);
char	**ft_split_quotes(const char *com, const char c);
char	**ft_split_pipes(const char *com);
short	quotes(const char c);
char	*ft_trim_quotes(const char *str);
/* ========================== */

/* ======== REDIRECTION ======== */
int		ft_check_redirection(t_shell *data, t_redir *red);
void	ft_create_archive(t_shell *data, t_redir *red);
/* ========================== */

/* ======== SIGNALS ======== */
void	ft_handle_signals(void);
/* ========================== */

/* ======== UTILS ======== */
//env
char	*ft_get_env_value(const char *name, t_list *env);
void	ft_set_env_value(const char *content, t_shell *data);
void	ft_update_env_value(const char *name, const char *value, t_shell *data);
void	ft_init_env(t_shell *data, char **env);

//array
char	**ft_split_all(char *string, char *set);
int		array_len(const char **array);
size_t	array_char_len(const char **array);
char	*array_to_str(const char **array, const char spliter);

//free
void	free_input(t_shell *data);
void	free_program(t_shell *data);
void	free_redir_struct(t_redir *red);
void	ft_exit_program(t_shell *data, const char *message);
void	ft_free_array(char **array);
void	ft_free_env(t_list *env);

void	ft_update_prompt(t_shell *data);
int		ft_isnotprint(const char c);
size_t	ft_strlenchr(const char *str, const char c);
short	check_quotes(const char *input);
/* ========================== */

#endif
