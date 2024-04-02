/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_archive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:13:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/02 20:11:03 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	file_dup(t_redir *red, int fd)
{
	int	fileno;
	int	i;

	fileno = 0;
	if (red->type == 1 || red->type == 2)
		fileno = STDOUT_FILENO;
	else if (red->type == 3)
		fileno = STDIN_FILENO;
	if (!fileno)
	{
		close(fd);
		return (1);
	}
	i = dup2(fd, fileno);
	if (i == -1)
	{
		close(fd);
		perror("dup2");
		return (0);
	}
	// close(fd);
	return (1);
}

static int	file_open(t_redir *red)
{
	int	fd;

	fd = 0;
	if (red->type == 1)
		fd = open(red->file_name, O_WRONLY | O_CREAT | O_APPEND, FILE_PERM);
	else if (red->type == 2)
		fd = open(red->file_name, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERM);
	else if (red->type == 3)
		fd = open(red->file_name, O_RDONLY, FILE_PERM);
	free(red->file_name);
	if (fd == -1)
	{
		perror("open");
		return (0);
	}
	return (file_dup(red, fd));
}

static void	get_archive_name(t_shell *data, t_redir *red)
{
	int		i;
	int		j;

	i = 0;
	red->file_name = 0;
	while (red->com[i] == ' ')
		i++;
	j = i;
	while (red->com[i])
	{
		if (!quotes(red->com[i]) && ft_strchr(" <>", red->com[i]))
		{
			red->file_name = ft_substr(red->com, j, i - j);
			if (!red->file_name)
				ft_exit_program(data, "malloc");
			return ;
		}
		i++;
	}
	red->file_name = ft_substr(red->com, j, i - j);
	if (!red->file_name)
		ft_exit_program(data, "malloc");
}

void	ft_create_archive(t_shell *data, t_redir *red)
{
	if (red->type == 1 || red->type == 4)
		red->com += 2;
	else if (red->type == 2)
		red->com += 1;
	get_archive_name(data, red);
	if (!red->file_name)
	{
		ft_putstr_fd("redir: syntax error near unexpected token\n", STDERR);
		red->success = 0;
		return ;
	}
	red->success = file_open(red);
}
