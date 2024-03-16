/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:27:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/16 12:19:58 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_parser(t_shell *data)
{
	data->argv = ft_split(data->command, ' ');
	if (!data->argv)
		ft_exit_program(data,"malloc");
	free(data->command);
	data->command = array_to_str(data->argv, ' ');
	if (!data->command)
		ft_exit_program(data, "malloc");
	// ft_trim_input(data);
	// ft_quotes_input(data);
	// ft_redirections(data);
}
