/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:04:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/11 18:40:13 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// needs parser and a command table
void	ft_exec_command(const char *command)
{
	if (!ft_strncmp(command, "pwd", 3))
		ft_pwd();
	else if (!ft_strncmp(command, "cd", 2))
		ft_cd(command + 2);
	else
		printf("%s : command not found\n", command);
}
