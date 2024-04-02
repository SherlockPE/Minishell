/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:03:22 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/02 15:31:52 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_exec_one(t_shell *data)
{
	t_com	parent;

	parent.pid = 1;
	ft_send_com(data, data->pipes[0], &parent);
	free_input(data);
}
