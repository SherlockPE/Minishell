/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:27:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/12 14:21:20 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_parser(t_shell *data)
{
	int	manage_exit;

	manage_exit = 7;
	if (ft_trim_input(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_val_input(data->input, '|', '&') 
		|| ft_val_input(data->input, '<', '>'))
		return (EXIT_FAILURE);
	// {
		// free_input(data);
	// }
	if (*data->input)
		add_history(data->input);
	data->pipes = ft_split_pipes(data->input);
	if (!data->pipes)
		return (ft_exit_funct("malloc", EXIT_FAILURE));
	if (ft_expansor(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (data->pipes[1])
		manage_exit = ft_pipex(data);
	else
		ft_exec_one(data);
	if (manage_exit == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
