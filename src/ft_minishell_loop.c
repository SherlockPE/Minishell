/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/12 01:13:30 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// static void	ft_signal(int signal)
// {
// 	if (signal == SIGINT)
// 	{
// 		printf("\n");
// 		rl_on_new_line();
// 		rl_replace_line("", 1);
// 		rl_redisplay();
// 	}
// }

void	ft_minishell_loop(t_shell *data)
{
	ft_save_config(data);
	while (1)
	{
		ft_handle_signals();
		if (ft_get_input(data) == EXIT_FAILURE);
			continue ;
		if (!data->input)
			break ;
		ft_parser(data);
	}
	// printf("Exiting minishell\n");
}
