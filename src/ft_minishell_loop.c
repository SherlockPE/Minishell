/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/20 17:06:15 by albartol         ###   ########.fr       */
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
	// rl_clear_history();
	// printf("Exiting minishell\n");
}
