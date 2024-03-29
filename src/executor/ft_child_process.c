/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:01:22 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/29 14:01:33 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	child_process(t_shell *data, char *com)
{
	t_com	child;
	// int		wstatus;

	child.redir = 0;
	child.pid = fork();
	if (child.pid == -1)
		return (perror("fork"));
	if (child.pid == 0)
	{
		ft_send_com(data, com, &child);
		free_program(data);
		exit(EXIT_SUCCESS);
	}
	// else
	// {
	// 	waitpid(child.pid, &wstatus, 0);
	// 	if (WIFEXITED(wstatus))
	// 		data->exit_code = WEXITSTATUS(wstatus);
	// }
}