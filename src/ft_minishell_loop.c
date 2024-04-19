/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/18 15:30:21 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	exit_minishell(t_shell *data)
{
	free_program(data);
	ft_putstr_fd("exit\n", STDOUT);
	exit(data->exit_code);
}

void	ft_minishell_loop(t_shell *data)
{
	int	manage_exit;

	while (1)
	{
		ft_unlink_here_doc(data);
		free_input(data);
		ft_handle_signals();
		manage_exit = ft_get_input(data);
		if (manage_exit == EXIT_FAILURE)
			continue ;
		else if (manage_exit == EXIT_PROGRAM)
			exit_minishell(data);
		// else if (manage_exit == EXIT_PROGRAM)
		// 	break ;
		if (data->input && *data->input)
		{
			add_history(data->input);
			ft_parser(data);
		}
	}
}
