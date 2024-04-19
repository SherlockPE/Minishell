/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:59:06 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/17 18:35:47 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	child_init(t_pipe *com, t_shell *data)
{
	int	i;

	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
	{
		close(com->fd[0]);
		close(com->fd[1]);
		ft_exit_program(data, "signal");
	}
	close(com->fd[0]);
	i = dup2(com->fd[1], STDOUT_FILENO);
	close(com->fd[1]);
	if (i == -1)
		ft_exit_program(data, "dup2");
	data->child = 1;
}

static void	child_exec(t_pipe *com, t_shell *data)
{
	char	**argv;

	ft_change_fd(com, data);
	argv = ft_rm_quotes((const char **)com->argv);
	if (!argv)
		ft_exit_program(data, "malloc");
	free_input(data);
	ft_exec_command(argv, data);
	ft_free_array(argv);
	ft_lstclear(&data->env, free);
}

int	child_process_pipe(t_shell *data, t_pipe *com)
{
	int		i;

	if (pipe(com->fd) == -1)
		return (ft_exit_funct("pipe", EXIT_FAILURE));
	com->pid = fork();
	if (com->pid == -1)
		return (ft_exit_funct("fork", EXIT_FAILURE));
	if (com->pid == 0)
	{
		child_init(com, data);
		child_exec(com, data);
		exit(EXIT_SUCCESS);
	}
	close(com->fd[1]);
	i = dup2(com->fd[0], STDIN_FILENO);
	close(com->fd[0]);
	if (i == -1)
		return (ft_exit_funct("dup2", EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
