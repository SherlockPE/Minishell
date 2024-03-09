/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/09 12:14:02 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_ctrl_c(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	ft_minishell_loop(void)
{
	char	*command;

	if (signal(SIGINT, ft_ctrl_c) == SIG_ERR)
		printf("Failed to register SIGINT\n");
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
