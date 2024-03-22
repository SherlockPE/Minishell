/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:27:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/22 12:55:57 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// TODO: exit if pipe fails or not ?

static void	ft_send_com(t_shell *data, char *com, t_com *com_struct)
{
	int	fd;

	com = ft_strtrim(com, " ");
	if (!com)
		ft_exit_program(data, "malloc");
	com_struct->argv = ft_split_quotes(com, ' ');
	free(com);
	if (!com_struct->argv)
		ft_exit_program(data, "malloc");
	data->com = com_struct;
	
	if (data->redir >= 1)
	{
		fd = create_archive(data);
		if (fd == -1)
			return ((void)printf("Error creating fd\n"));
		dup2(STDOUT_FILENO, fd);
	}
	ft_exec_command(data);
	if (data->redir >= 1)
		close(fd);
}

static void	child_process_pipe(t_shell *data, char *com)
{
	t_com 	child;
	// int		wstatus;
	int		i;

	if (pipe(child.fd) == -1)
		return (perror("pipe"));
	child.pid = fork();
	if (child.pid == -1)
		return (perror("fork"));
	if (child.pid == 0)
	{
		close(child.fd[0]);
		i = dup2(child.fd[1], STDOUT_FILENO);
		close(child.fd[1]);
		if (i == -1)
			ft_exit_program(data, "dup2");
		ft_send_com(data, com, &child);
		free_program(data);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(child.fd[1]);
		i = dup2(child.fd[0], STDIN_FILENO);
		close(child.fd[0]);
		// waitpid(child.pid, &wstatus, 0);
		// if (WIFEXITED(wstatus))
		// 	data->exit_code = WEXITSTATUS(wstatus);
		if (i == -1)
			return (perror("dup2"));
	}
}


static void	child_process(t_shell *data, char *com)
{
	t_com	child;
	// int		wstatus;

	child.pid = fork();
	if (child.pid == -1)
		return (perror("fork"));
	if (child.pid == 0)
	{
		ft_send_com(data, com, &child);
		free_program(data);
		exit(EXIT_SUCCESS);
	}
	// else
	// {
	// 	waitpid(child.pid, &wstatus, 0);
	// 	if (WIFEXITED(wstatus))
	// 		data->exit_code = WEXITSTATUS(wstatus);
	// }
}

static void	ft_pipex(t_shell *data)
{
	int	i;
	int old_stdin;
	int	wstatus;
	
	old_stdin = dup(STDIN_FILENO);
	if (old_stdin == -1)
	{
		free_input(data);
		return (perror("dup"));
	}
	i = 0;
	while (data->pipes[i + 1])
	{
		child_process_pipe(data, data->pipes[i]);
		i++;
	}
	child_process(data, data->pipes[i]);
	free_input(data);
	i = dup2(old_stdin, STDIN_FILENO);
	close(old_stdin);
	while (waitpid(-1, &wstatus, 0) != -1 && errno != ECHILD)
	{
		if (WIFEXITED(wstatus))
			data->exit_code = WEXITSTATUS(wstatus);
	}
	if (i == -1)
		perror("dup2");
}

static void	ft_exec_one(t_shell *data)
{
	t_com	parent;

	parent.pid = 1;
	ft_send_com(data, data->pipes[0], &parent);
	free_input(data);
}

void	ft_parser(t_shell *data)
{
	char **input;	

	ft_trim_input(data);
	if (ft_validate_input(data->command, '|') || 
			ft_validate_input(data->command, '&'))
		return ;
	if (*data->command)
		add_history(data->command);
	
	
	check_redirection(data);
	if (data->redir == -1)
	{
		printf("syntax error near unexpected token `>'\n");
		return (free_input(data));
	}
	else if (data->redir == 1)//IF THERE'S A '>'
	{
		input = ft_split(data->command, '>');
		data->pipes = ft_split_pipes(input[0]);
		if (!data->pipes)
			ft_exit_program(data, "malloc");
		data->archive_name = input[1];
	}
	// else if (data->redir == 1)//IF THERE'S A '>>'
	// {
	// 	input = ft_split(data->command, '>>');
	// 	data->pipes = ft_split_pipes(input[0]);
	// 	if (!data->pipes)
	// 		ft_exit_program(data, "malloc");
	// 	data->archive_name = input[1];
	// }
	else
	{
		//Split pipes
		data->pipes = ft_split_pipes(data->command);
		if (!data->pipes)
			ft_exit_program(data, "malloc");
	}

	//print input
	int i = 0;
	while (data->pipes[i])
	{
		printf("[%s]\n", data->pipes[i]);
		i++;
	}
	//print archive name
	if (data->redir >= 1)
		printf("Archive name[%s]\n", data->archive_name);
	//exec
	if (data->pipes[1])
		ft_pipex(data);
	else
		ft_exec_one(data);
}

































// data->argv = ft_split_quotes(data->command, ' ');
// if (!data->argv)
// 	ft_exit_program(data, "malloc");
// i = 0;
// while (data->pipes[i])
// {
// 	if (ft_validate_input(data->pipes[i]))
// 		return ;
// }
// free(data->command);
// data->command = array_to_str(data->argv, ' ');
// if (!data->command)
// 	ft_exit_program(data, "malloc");
//	ft_exec_command(data);
