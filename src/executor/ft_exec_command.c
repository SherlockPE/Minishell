/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:04:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/25 15:49:21 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_exec_command(char **argv, t_shell *data)
{
	if (!ft_strncmp(argv[0], "pwd", 4))
		ft_pwd(data);
	else if (!ft_strncmp(argv[0], "cd", 3))
		ft_cd(argv, data);
	else if (!ft_strncmp(argv[0], "env", 4))
		ft_env(argv, data);
	else if (!ft_strncmp(argv[0], "exit", 5))
		ft_exit(argv, data);
	else if (!ft_strncmp(argv[0], "echo", 5))
		ft_echo(argv, data);
	else if (!ft_strncmp(argv[0], "export", 7))
		ft_export(argv, data);
	else if (!ft_strncmp(argv[0], "unset", 6))
		ft_unset(argv, data);
	else
		ft_exec_bin(argv, data);
}
