/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/02 16:14:28 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_minishell_loop(t_shell *data)
{
	ft_handle_signals();
	while (1)
	{
		ft_get_input(data);
		if (!data->input)
			break ;
		ft_parser(data);
		// if (data->pipes[1])
		// 	ft_pipex(data);
		// else
		// 	ft_exec_one(data);
		// free_input(data);
	}
	// rl_clear_history();
	// printf("Exiting minishell\n");
}
