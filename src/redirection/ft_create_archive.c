/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_archive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:13:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/18 18:13:50 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	file_open(t_redir *red)
{
	int	fd;

	fd = 0;
	if (red->type == APPEND)
		fd = open(red->file_name, O_WRONLY | O_APPEND | O_CREAT, FILE_PERM);
	else if (red->type == TRUNC)
		fd = open(red->file_name, O_WRONLY | O_TRUNC | O_CREAT, FILE_PERM);
	else
		return (0);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	close(fd);
	return (0);
}

int	ft_create_archive(t_redir *red, const char *com, t_shell *data)
{
	red->file_name = ft_get_archive_name(com, data);
	if (!red->file_name)
		return (1);
/* 	ft_putstr_fd(red->file_name, 2);
	ft_putstr_fd("\n", 2); */
	return (file_open(red));
}
