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

int	check_input(char *input)
{
	int	i;
	int	double_q;
	int	simple_q;

	i = 0;
	double_q = 0;
	simple_q = 0;
	while (input[i])
	{
		if (input[i] == '\"')
			double_q++;
		if (input[i] == '\'')
			simple_q++;
		i++;
	}
	if ((double_q % 2 == 0) && (simple_q % 2 == 0))
		return (1);
	return (0);
}

void	get_command(t_shell *data)
{
	char	*aux;
	char	*new_input;

	data->command = readline(data->prompt); //this is a malloc!!!!! we need to protect this correctly
	if (!data->command)
		return ;
	while (!check_input(data->command))
	{
		new_input = readline(">"); //this is a malloc!!!!! we need to protect this correctly
		if (!new_input)
			return ;
		aux = data->command;
		data->command = ft_strjoin(data->command, "\n");
		free(aux);
		if (!data->command)
			return ;
		aux = data->command;
		data->command = ft_strjoin(data->command, new_input);
		free(aux);
		if (!data->command)
			return ;
	}
}

void	ft_get_input(t_shell *data)
{
	ft_update_prompt(data);
	get_command(data);
	// if (*data->command)
	// 	ft_parser(data);
}
