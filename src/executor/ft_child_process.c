/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:01:22 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/23 18:22:23 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	child_process(t_shell *data, t_pipe *com)
{
	char	**argv;

	com->pid = fork();
	if (com->pid == -1)
		return (ft_exit_funct("fork", EXIT_FAILURE));
	if (com->pid == 0)
	{
		if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
			ft_exit_program(data, "signal");
		data->child = 1;
		ft_change_fd(com, data);
		argv = ft_rm_quotes((const char **)com->argv);
		if (!argv)
			ft_exit_program(data, "malloc");
		free_input(data);
		ft_exec_command(argv, data);
		ft_free_array(argv);
		ft_lstclear(&data->env, free);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
