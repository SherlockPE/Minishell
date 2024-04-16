/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:03:22 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/12 15:26:58 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	change_fd(t_pipe *com, t_shell *data)
{
	int		fd;
	int		i;

	if (com->input.file_name)
	{
		fd = open(com->input.file_name, O_RDONLY);
		if (fd == -1)
			return (ft_exit_funct("open", EXIT_FAILURE));
		i = dup2(fd, STDIN_FILENO);
		close(fd);
		if (i == -1)
			return (ft_exit_funct("input: dup2", EXIT_FAILURE));
	}
	if (com->output.file_name)
	{
		if (com->output.type == TRUNC)
			fd = open(com->output.file_name, O_WRONLY | O_TRUNC);
		else if (com->output.type == APPEND)
			fd = open(com->output.file_name, O_WRONLY | O_APPEND);
		if (fd == -1)
			return (ft_exit_funct("open", EXIT_FAILURE));
		i = dup2(fd, STDOUT_FILENO);
		close(fd);
		if (i == -1)
			return (ft_exit_funct("input: dup2", EXIT_FAILURE));
	}
	return (EXIT_SUCCESS);
}

static void	save_fd(int *fd)
{
	fd[0] = dup(STDIN_FILENO);
	if (fd[0] == -1)
		perror("dup: old_stdin");
	fd[1] = dup(STDOUT_FILENO);
	if (fd[1] == -1)
		perror("dup: old_stdout");
}

static void	restore_fd(int *fd)
{
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("dup2: old_stdout");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror("dup2: old_stdin");
	close(fd[1]);
	close(fd[0]);
}

void	ft_exec_one(t_shell *data)
{
	char	**argv;
	int		fd[2];

	argv = ft_rm_quotes(data->com->argv);
	if (!argv)
	{
		perror("malloc");
		return ;
	}
	save_fd(&fd[0]);
	if (change_fd(data->com, data))
		return ;
	ft_exec_command(argv, data);
	restore_fd(&fd[0]);
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &data->conf) == -1)
		perror("tcsetattr");
}
