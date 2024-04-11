/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:04:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/12 00:01:59 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// needs parser and a command table
void	ft_exec_command(t_shell *data)
{
	if (!ft_strncmp(data->com->argv[0], "pwd", 4))
		ft_pwd();
	else if (!ft_strncmp(data->com->argv[0], "cd", 3))
		ft_cd(data);
	else if (!ft_strncmp(data->com->argv[0], "env", 4))
		ft_env(data);
	else if (!ft_strncmp(data->com->argv[0], "exit", 5))
		ft_exit(data);
	else if (!ft_strncmp(data->com->argv[0], "echo", 5))
		ft_echo(data);
	else if (!ft_strncmp(data->com->argv[0], "export", 7))
		ft_export(data);
	else if (!ft_strncmp(data->com->argv[0], "unset", 6))
		ft_unset(data);
	else
		ft_exec_bin(data);
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &data->init_conf) == -1)
		perror("tcsetattr");
}
