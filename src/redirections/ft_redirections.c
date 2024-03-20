/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:18:23 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/20 10:54:52 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_redirections(t_shell *data, char *archive_name, char *content)
{
	int fd;

	fd = open(archive_name, O_CREAT, O_APPEND);
	if (fd == -1)
		return ; // print error?
	ft_putstr_fd(content, fd);
	close(fd);
}
