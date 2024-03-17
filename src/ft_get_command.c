/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:48:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/15 17:11:28 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	get_command(t_shell *data)
{
	char	*aux;
	char	*new_input;

	data->command = readline(data->prompt);
	free(data->prompt);
	if (!data->command)
		return ;
	while (check_quotes(data->command))
	{
		new_input = readline(">");
		if (!new_input)
			return ;
		aux = data->command;
		data->command = ft_strjoin(data->command, "\n");
		free(aux);
		if (!data->command)
			ft_exit_program(data, "malloc");
		aux = data->command;
		data->command = ft_strjoin(data->command, new_input);
		free(aux);
		if (!data->command)
			ft_exit_program(data, "malloc");
	}
}

void	ft_get_input(t_shell *data)
{
	ft_update_prompt(data);
	get_command(data);
}
