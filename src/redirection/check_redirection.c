/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:12:50 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/22 18:28:40 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//-1 does not found a '>'
void   	check_redirection(t_shell *data)
{
	int i;
	int status;

	i = 0;
	status = 0;
	while (data->command[i])
	{
		if (data->command[i] == '>')
			status++;
		i++;
	}
	if (status > 2)
	{
		printf("syntax error near unexpected token `>'");
		return (free_input(data));
	}
	data->redir = status;
}