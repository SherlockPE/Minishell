/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:58:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/08 15:41:02 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(void)
{
	char *command;

	while (1)
	{
		command = readline("minishell $> ");
		if (!command)
		{
			rl_clear_history();
			printf("Exiting minishell\n");
			return (EXIT_SUCCESS);
		}
		printf("Has ecrito: %s\n", command);
		free(command);
	}
	return (EXIT_SUCCESS);
}
