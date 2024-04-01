/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_archive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:13:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/01 17:25:44 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	get_redirection_type(t_shell *data, int pos, t_redir *red)
{
	int		i;
	int		type;
	char	*command;
	
	i = 0;
	type = 0;
	command = data->pipes[pos];
	while (command[i])
	{
		if (command[i] == '>')
			type++;
		i++;
	}
	// if (type >= 3)
	// {
	// 	// imprimir syntax error y también no ejecutar nada
	// 	printf("syntax error near unexpected token `>'\n");
	// 	type = 0;
	// 	// return (free_input(data));
	// }
	red->type = type;
	// char	*aux;
	// com->redir->type = 1;
	
	// aux = com->redir->com_argv[i];
	// com->redir->com_argv[i] = ft_strtrim(com->redir->com_argv[i], " ");
	// free(aux);
}

static int	file_open(t_redir *red, int i)
{
	int	fd;

	fd = 0;
	if (red->type == 1)
		fd = open(red->com_argv[i], O_WRONLY | O_CREAT | O_APPEND, FILE_PERM);
	else if (red->type == 2)
		fd = open(red->com_argv[i], O_WRONLY | O_CREAT | O_TRUNC, FILE_PERM);
	else if (red->type == 3)
		fd = open(red->com_argv[i], O_RDONLY, FILE_PERM);
	return (fd);
}

static void	get_fd(t_redir *red)
{
	int	i;
	// int	i;
	
	i = 1;
	while (red->com_argv[i + 1])
	{
		red->fd = file_open(red, i);
		if (red->fd == -1)
			return ; //<-------Ale, aquí Fabri. Hay que hacer que si pasa esto ya no trate de ejecutar el comando en ft_exec_command o antes de que este se llame
		close(red->fd);
		i++;
	}
	red->fd = file_open(red, i);
	if (red->fd == -1)
		return ; //<-------Ale, aquí Fabri. Hay que hacer que si pasa esto ya no trate de ejecutar el comando en ft_exec_command o antes de que este se llame
}

static void	get_archive_names(t_shell *data, int i, t_redir *red)
{
	char	*aux;

	//Get redirection type and save it in the actual redir->type
	get_redirection_type(data, i, red);
	red->com_argv = ft_split_all(data->pipes[i], "> ");
	if (!red->com_argv)
		ft_exit_program(data, "malloc");
	
	//Actualize the real command
	aux = data->pipes[i];
	data->pipes[i] = ft_strdup(red->com_argv[0]);
	if (!data->pipes[i])
		ft_exit_program(data, "malloc");
	free(aux);	
}

void	ft_create_archive(t_shell *data, int i)
{
	t_redir	red;

	get_archive_names(data, i, &red);
	get_fd(&red);
	// red.fd = file_open(&red);
}
