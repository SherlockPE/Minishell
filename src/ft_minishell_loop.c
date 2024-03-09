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

void	ft_minishell_loop(void)
{
	char	*command;

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
