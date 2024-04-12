/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/12 09:33:58 by flopez-r         ###   ########.fr       */
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
	int	manage_exit;

	ft_save_config(data);
	while (1)
	{
		ft_handle_signals();
		manage_exit = ft_get_input(data);
		if (manage_exit == EXIT_FAILURE)
			continue ;
		else if (manage_exit == EXIT_PROGRAM)
			break;
		if (!data->input)
			break ;
		ft_parser(data);
	}
}
