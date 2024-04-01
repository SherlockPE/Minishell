/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_archive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:13:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/01 15:55:33 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	get_redirection_type(t_shell *data, int pos)
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
	if (type >= 3)
	{
		// imprimir syntax error y también no ejecutar nada
		type = 0;
		// printf("syntax error near unexpected token `>'");
		// return (free_input(data));
	}
	data->com->redir->type = type;
	// char	*aux;
	// com->redir->type = 1;
	
	// aux = com->redir->com_argv[i];
	// com->redir->com_argv[i] = ft_strtrim(com->redir->com_argv[i], " ");
	// free(aux);
}

static int	file_open(char *file, int type)
{
	int	fd;

	fd = 0;
	if (type == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, FILE_PERM);
	else if (type == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERM);
	else if (type == 3)
		fd = open(file, O_RDONLY, FILE_PERM);
	return (fd);
}

void	get_fd(t_shell *data, int i)
{
	// int	i;
	int	fd;

	// i = 0;
	fd = file_open(data->pipes[i], data->com->redir->type);
	// while (data->com->redir->com_argv[i])
	// {
	// 	get_redirection_type(data->com, i);
	// 	fd = file_open(data->com->redir->com_argv[i], data->com->redir->type);
	// 	if (fd == -1)
	// 		return ; //<-------Ale, aquí Fabri. Hay que hacer que si pasa esto ya no trate de ejecutar el comando en ft_exec_command o antes de que este se llame
	// 	close(fd);
	// }	
	// fd = file_open(data->com->redir->com_argv[i], data->com->redir->type);
	// if (fd == -1)
	// 	return ; //<-------Ale, aquí Fabri. Hay que hacer que si pasa esto ya no trate de ejecutar el comando en ft_exec_command o antes de que este se llame
	// data->com->redir->fd = fd;
}

static void	get_archive_names(t_shell *data, int i)
{
	char	*aux;

	//Get redirection type and save it in the actual data->com->redir->type
	get_redirection_type(data, i);

	printf("incio del split\n");
	data->com->redir->com_argv = ft_split_all(data->pipes[i], "> ");
	if (!data->com->redir->com_argv)
		ft_exit_program(data, "malloc");
	printf("fin del split\n");
	aux = data->pipes[i];
	//Actualize the real command
	data->pipes[i] = ft_strdup(data->com->redir->com_argv[0]);
	if (!data->pipes[i])
		ft_exit_program(data, "malloc");
	free(aux);
	//Print test
	printf("Final command[%s]\n", data->pipes[i]);
	i = 0;
	while (data->com->redir->com_argv[i])
	{
		printf("Archive names[%s]\n", data->com->redir->com_argv[i]);
		i++;
	}
	
}

void	ft_create_archive(t_shell *data, int i)
{
	//Darle valor a la estructura s_redir
	get_archive_names(data, i);
	// clean_command(data); //<------- Necesito una funcion que limpie el comando original luego de los split redirections
	// get_fd(data, i);
}
