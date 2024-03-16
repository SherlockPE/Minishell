/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:04:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/16 10:00:56 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// needs parser and a command table
void	ft_exec_command(t_shell *data)
{
	if (!ft_strncmp(data->command, "pwd", 3))
		ft_pwd();
	else if (!ft_strncmp(data->command, "cd", 2))
		ft_cd(data, data->command + 2);
	else if (!ft_strncmp(data->command, "env", 3))
		ft_env(data);
	else if (!ft_strncmp(data->command, "exit", 4))
		ft_env(data);
	// else if (!ft_strncmp(command, "echo", 4))
	// 	ft_echo(data, command + 4);
	else
		ft_exec_bin(data, data->command);
}
