/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:02:25 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/12 12:41:41 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_pipex(t_shell *data)
{
	int	i;
	int	old_stdin;
	int	wstatus;

	old_stdin = dup(STDIN_FILENO);
	if (old_stdin == -1)
	{
		free_input(data);
		return (ft_exit_funct("dup", EXIT_FAILURE));
	}
	i = 0;
	while (data->pipes[i + 1])
	{
		if (child_process_pipe(data, data->pipes[i++]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (child_process(data, data->pipes[i]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free_input(data);
	if (dup2(old_stdin, STDIN_FILENO) == EXIT_FAILURE)
		return (ft_exit_funct("dup2", EXIT_FAILURE));
	close(old_stdin);
	while (waitpid(-1, &wstatus, 0) != -1 && errno != ECHILD)
	{
		if (WIFEXITED(wstatus))
			data->exit_code = WEXITSTATUS(wstatus);
	}
	return (EXIT_SUCCESS);
}
