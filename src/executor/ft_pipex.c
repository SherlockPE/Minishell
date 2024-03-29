/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:02:25 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/29 14:02:53 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_pipex(t_shell *data)
{
	int	i;
	int old_stdin;
	int	wstatus;

	old_stdin = dup(STDIN_FILENO);
	if (old_stdin == -1)
	{
		free_input(data);
		return (perror("dup"));
	}
	i = 0;
	while (data->pipes[i + 1])
	{
		child_process_pipe(data, data->pipes[i]);
		i++;
	}
	child_process(data, data->pipes[i]);
	free_input(data);
	i = dup2(old_stdin, STDIN_FILENO);
	close(old_stdin);
	while (waitpid(-1, &wstatus, 0) != -1 && errno != ECHILD)
	{
		if (WIFEXITED(wstatus))
			data->exit_code = WEXITSTATUS(wstatus);
	}
	if (i == -1)
		perror("dup2");
}
