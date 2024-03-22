/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_archive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:13:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/22 18:29:00 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int create_archive(t_shell *data)
{
	int	fd;

	fd = open(data->archive_name, O_CREAT | 0644 | O_APPEND);
	if (data->redir == 1)
		ft_putstr_fd("", fd);
	
	return (fd);
}