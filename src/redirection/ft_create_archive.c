/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_archive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:13:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/06 22:23:30 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	file_dup(t_redir *red, int fd)
{
	int	fileno;

	fileno = STDOUT_FILENO;
	if (red->type == 3)
		fileno = STDIN_FILENO;
	if (dup2(fd, fileno) == -1)
	{
		
		close(fd);
		// ft_exit_program(data, "dup2");
		perror("dup2");
		return (0);
	}
	close(fd);
	return (1);
}

static int	file_open(t_redir *red)
{
	int	fd;

	if (red->type == 1)
		fd = open(red->file_name, O_WRONLY | O_APPEND | O_CREAT, FILE_PERM);
	else if (red->type == 2)
		fd = open(red->file_name, O_WRONLY | O_TRUNC | O_CREAT, FILE_PERM);
	else
		fd = open(red->file_name, O_RDONLY, FILE_PERM);
	free(red->file_name);
	if (fd == -1)
	{
		perror("open");
		return (0);
	}
	return (file_dup(red, fd));
}

// void	trim_archive_name(t_shell *data, t_redir *red, int i)
// {
// 	char	*temp;

// 	temp = ft_substr(red->com, 0, i);
// 	if (!temp)
// 	{
// 		free(data->com->command);
// 		ft_exit_program(data, "malloc");
// 	}
// 	red->file_name = ft_trim_quotes(temp);
// 	free(temp);
// 	if (!red->file_name)
// 	{
// 		free(data->com->command);
// 		ft_exit_program(data, "malloc");
// 	}
// }

void	ft_create_archive(t_shell *data, t_redir *red)
{
	ft_get_archive_name(data, red);
	// if (!red->file_name)
	// {
	// 	ft_putstr_fd("redir: syntax error near unexpected token\n", STDERR);
	// 	red->success = 0;
	// 	return ;
	// }
	red->success = file_open(red);
}
