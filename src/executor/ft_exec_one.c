/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:03:22 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/18 14:26:31 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	output_fd(t_pipe *com)
{
	int		fd;
	int		i;

	fd = 0;
	if (com->output.file_name)
	{
		if (com->output.type == TRUNC)
			fd = open(com->output.file_name, O_WRONLY | O_TRUNC);
		else if (com->output.type == APPEND)
			fd = open(com->output.file_name, O_WRONLY | O_APPEND);
		if (fd == 0)
			return (EXIT_SUCCESS);
		if (fd == -1)
			return (ft_exit_funct("open", EXIT_FAILURE));
		i = dup2(fd, STDOUT_FILENO);
		close(fd);
		if (i == -1)
			return (ft_exit_funct("input: dup2", EXIT_FAILURE));
	}
	return (EXIT_SUCCESS);
}

static int	change_fd(t_pipe *com)
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
	return (output_fd(com));
}

static int	save_fd(int *fd, t_pipe *com)
{
	if (com->input.file_name)
	{
		fd[0] = dup(STDIN_FILENO);
		if (fd[0] == -1)
			return (ft_exit_funct("dup: old_stdin", EXIT_FAILURE));
	}
	if (com->output.file_name)
	{
		fd[1] = dup(STDOUT_FILENO);
		if (fd[1] == -1)
		{
			if (com->input.file_name)
				close(fd[0]);
			return (ft_exit_funct("dup: old_stdout", EXIT_FAILURE));
		}
	}
	return (EXIT_SUCCESS);
}

static void	restore_fd(int *fd, t_pipe *com)
{
	if (com->input.file_name)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			perror("dup2: old_stdin");
		close(fd[0]);
	}
	if (com->output.file_name)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			perror("dup2: old_stdout");
		close(fd[1]);
	}
}

void	ft_exec_one(t_shell *data)
{
	char	**argv;
	int		fd[2];

	if (save_fd(&fd[0], data->com))
		return ;
	if (change_fd(data->com))
	{
		restore_fd(&fd[0], data->com);
		data->exit_code = EXIT_FAILURE;
		return ;
	}
	argv = ft_rm_quotes((const char **)data->com->argv);
	if (!argv)
	{
		restore_fd(&fd[0], data->com);
		perror("malloc");
		return ;
	}
	ft_exec_command(argv, data);
	restore_fd(&fd[0], data->com);
	if (isatty(STDIN_FILENO))
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &data->conf);
	ft_free_array(argv);
}
