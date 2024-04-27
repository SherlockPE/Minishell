/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:02:25 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/26 13:26:06 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_pipex(t_shell *data)
{
	int	i;
	int	old_stdin;
	int	wstatus;

	old_stdin = dup(STDIN_FILENO);
	if (old_stdin == -1)
		return (perror("pipex: dup"));
	i = 0;
	while (i < data->com_len - 1)
		child_process_pipe(data, &data->com[i++]);
	child_process(data, &data->com[i]);
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		perror("signal");
	if (dup2(old_stdin, STDIN_FILENO) == -1)
		perror("dup2");
	close(old_stdin);
	while (waitpid(-1, &wstatus, 0) != -1 && errno != ECHILD)
		ft_handle_exit(data, wstatus);
}
