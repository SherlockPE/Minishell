/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:01:22 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/12 12:31:17 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	child_process(t_shell *data, char *com)
{
	t_com	child;
	// int		wstatus;

	child.pid = fork();
	if (child.pid == -1)
		return (ft_exit_funct("fork", EXIT_FAILURE));
	if (child.pid == 0)
	{
		if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
			perror("signal");
		ft_send_com(data, com, &child);
		free_program(data);
		exit(EXIT_SUCCESS);
	}
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		perror("signal");
	return (EXIT_SUCCESS);
}
