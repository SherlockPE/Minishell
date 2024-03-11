/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/11 15:35:19 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_signal(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
	else if (signal == SIGQUIT)
	{
		rl_on_new_line();
		rl_replace_line(rl_line_buffer, 0);
		rl_redisplay();
	}
}

void	ft_minishell_loop(void)
{
	char	*command;

	if (signal(SIGINT, ft_signal) == SIG_ERR)
		ft_print_error();
	if (signal(SIGQUIT, ft_signal) == SIG_ERR)
		ft_print_error();
	while (1)
	{
		command = ft_get_command();
		if (!command)
			break ;
		if (*command)
			ft_exec_command(command);
		free(command);
	}
	rl_clear_history();
	printf("Exiting minishell\n");
}
