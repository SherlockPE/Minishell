/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_archive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:13:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/29 17:38:55 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	get_redirection_type(t_com *com, int i)
{
	char	*aux;
	com->redir->type = 1;
	
	aux = com->redir->com_argv[i];
	com->redir->com_argv[i] = ft_strtrim(com->redir->com_argv[i], " ");
	free(aux);
}

static void	get_archive_names(t_shell *data)
{
	char	**split_quotes;

	split_quotes = ft_split(data->com->command, '>');
	if (!split_quotes)
		ft_exit_program(data, "malloc");
	data->com->redir->com_argv = split_quotes;
}

static int	manage_open(char *path, int type)
{
	int	fd;

	fd = 0;
	if (type == 1)
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (type == 2)
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (fd);
}

static void	get_fd(t_shell *data)
{
	int	i;
	int	fd;

	i = 0;
	while (data->com->redir->com_argv[i])
	{
		get_redirection_type(data->com, i);
		fd = manage_open(data->com->redir->com_argv[i], data->com->redir->type);
		if (fd == -1)
			return ; //<-------Ale, aquí Fabri. Hay que hacer que si pasa esto ya no trate de ejecutar el comando en ft_exec_command o antes de que este se llame
		close(fd);
	}	
	fd = manage_open(data->com->redir->com_argv[i], data->com->redir->type);
		if (fd == -1)
			return ; //<-------Ale, aquí Fabri. Hay que hacer que si pasa esto ya no trate de ejecutar el comando en ft_exec_command o antes de que este se llame
	data->com->redir->fd = fd;
}

void	ft_create_archive(t_shell *data)
{
	//Darle valor a la estructura s_redir
	get_archive_names(data);
	// clean_command(data); //<------- Necesito una funcion que limpie el comando original luego de los split redirections
	get_fd(data);
}
