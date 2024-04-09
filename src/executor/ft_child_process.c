/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:01:22 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/09 19:47:56 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	child_process(t_shell *data, char *com)
{
	t_com	child;
	// int		wstatus;

	child.pid = fork();
	if (child.pid == -1)
		return (perror("fork"));
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
	// else
	// {
	// 	waitpid(child.pid, &wstatus, 0);
	// 	if (WIFEXITED(wstatus))
	// 		data->exit_code = WEXITSTATUS(wstatus);
	// }
}
