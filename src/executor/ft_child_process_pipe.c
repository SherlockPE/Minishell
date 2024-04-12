/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:59:06 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/12 12:27:24 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	child_process_pipe(t_shell *data, char *com)
{
	t_com	child;
	int		i;
	// int		wstatus;

	if (pipe(child.fd) == -1)
		return (ft_exit_funct("pipe", EXIT_FAILURE));
	child.pid = fork();
	if (child.pid == -1)
		return (ft_exit_funct("fork", EXIT_FAILURE));
	if (child.pid == 0)
	{
		if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
			perror("signal");
		close(child.fd[0]);
		i = dup2(child.fd[1], STDOUT_FILENO);
		close(child.fd[1]);
		if (i == -1)
			ft_exit_program(data, "dup2");
		ft_send_com(data, com, &child);
		free_program(data);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (signal(SIGINT, SIG_IGN) == SIG_ERR)
			perror("signal");
		close(child.fd[1]);
		i = dup2(child.fd[0], STDIN_FILENO);
		close(child.fd[0]);
		// waitpid(child.pid, &wstatus, 0);
		// if (WIFEXITED(wstatus))
		// 	data->exit_code = WEXITSTATUS(wstatus);
		if (i == -1)
			return (ft_exit_funct("dup2", EXIT_FAILURE));
	}
	return (EXIT_SUCCESS);
}
