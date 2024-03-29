/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_com.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:00:01 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/29 14:00:23 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_send_com(t_shell *data, char *com, t_com *com_struct)
{
	com = ft_strtrim(com, " ");
	if (!com)
		ft_exit_program(data, "malloc");
	com_struct->argv = ft_split_quotes(com, ' ');
	free(com);
	if (!com_struct->argv)
		ft_exit_program(data, "malloc");
	data->com = com_struct;
	ft_exec_command(data);
}
