/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:27:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/18 18:00:32 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// TODO: exit if pipe fails or not ?

static void	child_process_pipe(t_shell *data, char *com)
{
	t_com 	child;
	int		wstatus;
	int		i;

	if (pipe(child.fd) == -1)
		return (perror("pipe"));
	child.pid = fork();
	if (child.pid == -1)
		return (perror("fork"));
	if (child.pid == 0)
	{
		child.argv = ft_split_quotes(com, ' ');
		if (!child.argv)
			ft_exit_program(data, "malloc");
		data->com = &child;
		close(child.fd[0]);
		i = dup2(child.fd[1], STDOUT_FILENO);
		close(child.fd[1]);
		if (i == -1)
			ft_exit_program(data, "dup2");
		ft_exec_command(data);
	}
	else
	{
		close(child.fd[1]);
		i = dup2(child.fd[0], STDIN_FILENO);
		close(child.fd[0]);
		if (i == -1)
			return (perror("dup2"));
		waitpid(child.pid, &wstatus, 0);
		if (WIFEXITED(wstatus))
			data->exit_code = WEXITSTATUS(wstatus);
	}
}


static void	child_process(t_shell *data, char *com)
{
	t_com child;
	int		wstatus;

	child.pid = fork();
	if (child.pid == -1)
		return (perror("fork"));
	if (child.pid == 0)
	{
		child.argv = ft_split_quotes(com, ' ');
		if (!child.argv)
			ft_exit_program(data, "malloc");
		data->com = &child;
		ft_exec_command(data);
	}
	else
	{
		waitpid(child.pid, &wstatus, 0);
		if (WIFEXITED(wstatus))
			data->exit_code = WEXITSTATUS(wstatus);
	}
}

static void	ft_pipex(t_shell *data)
{
	int	i;

	i = 0;
	while (data->pipes[i + 1])
	{
		child_process_pipe(data, data->pipes[i]);
		i++;
	}
	child_process(data, data->pipes[i]);
}


void	ft_parser(t_shell *data)
{
	// int	i;

	ft_trim_input(data);
	if (ft_validate_input(data->command, '|') || 
			ft_validate_input(data->command, '&'))
		return ;
	if (*data->command)
		add_history(data->command);
	// data->argv = ft_split_quotes(data->command, ' ');
	// if (!data->argv)
	// 	ft_exit_program(data, "malloc");
	data->pipes = ft_split_pipes(data->command);
	if (!data->pipes)
		ft_exit_program(data, "malloc");
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
	ft_pipex(data);
}
