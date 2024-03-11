/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/11 18:40:13 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

void	ft_minishell_loop(t_shell *data)
{
	char	*command;

	if (signal(SIGINT, ft_ctrl_c) == SIG_ERR)
		perror(NULL);
	while (1)
	{
		command = ft_get_command(data);
		if (!command)
			break ;
		if (*command)
			ft_exec_command(command);
		free(command);
	}
	rl_clear_history();
	printf("Exiting minishell\n");
}
