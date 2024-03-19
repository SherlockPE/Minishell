/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/16 11:21:00 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_minishell_loop(t_shell *data)
{
	ft_handle_signals();
	while (1)
	{
		ft_get_input(data);
		if (!data->command)
			break ;
		ft_parser(data);
		// free_input(data);
	}
	rl_clear_history();
	printf("Exiting minishell\n");
}
