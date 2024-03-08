/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:58:51 by albartol          #+#    #+#             */
/*   Updated: 2024/03/05 20:10:00 by albartol         ###   ########.fr       */
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
#include <sys/types.h>
// for read
#include <sys/uio.h>
// for open
# include <fcntl.h>
// for signal, sigaction, kill
# include <signal.h>
// for fork, kill
# include <sys/types.h>
// for waitpid, wait, waitpid, wait3, wait4
# include <sys/wait.h>
// for wait3, wait4
#include <sys/time.h>
// for wait3, wait4
#include <sys/resource.h>
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

#endif
