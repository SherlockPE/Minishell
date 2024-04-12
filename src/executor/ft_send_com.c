/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_com.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:00:01 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/12 14:58:53 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	rm_quotes(t_shell *data)
{
	int		i;
	size_t	len;
	char	*tmp;

	i = 0;
	while(data->com->argv[i])
	{
		tmp = data->com->argv[i];
		len = ft_strlen(tmp);
		if ((ft_strlenchr(tmp, '\"') < len) || (ft_strlenchr(tmp, '\'') < len))
		{
			tmp = ft_trim_quotes(data->com->argv[i]);
			if (!tmp)
				ft_exit_program(data, "malloc");
			free(data->com->argv[i]);
			data->com->argv[i] = tmp;
		}
		i++;
	}
}

//Function saves the stdout and the stdin in a backup
static void	save_fd(t_shell *data, t_redir *red)
{
	red->old_stdin = dup(STDIN_FILENO);
	if (red->old_stdin == -1)
		ft_exit_program(data, "dup");
	red->old_stdout = dup(STDOUT_FILENO);
	if (red->old_stdout == -1)
		ft_exit_program(data, "dup");
}

static void	restore_fd(t_shell *data, t_redir *red)
{
	if (dup2(red->old_stdout, STDOUT_FILENO) == -1)
		return (ft_exit_program(data, "dup2 : red.old_stdout"));
	if (dup2(red->old_stdin, STDIN_FILENO) == -1)
		return (ft_exit_program(data, "dup2 : red.old_stdin"));
	close(red->old_stdout);
	close(red->old_stdin);
}

void	ft_send_com(t_shell *data, char *com, t_com *com_struct)
{
	t_redir red;

	com = ft_strtrim(com, " ");
	if (!com)
		ft_exit_program(data, "malloc");
	com_struct->argv = 0;
	com_struct->command = com;
	data->com = com_struct;
	save_fd(data, &red);
	if (ft_check_redirection(data, &red))
	{
		free(data->com->command);
		data->com = 0;
		restore_fd(data, &red);
		return ;
	}
	if (!data->com->command[0])
		return (restore_fd(data, &red));
	data->com->argv = ft_split_quotes(data->com->command, ' ');
	free(data->com->command);
	if (!data->com->argv)
		ft_exit_program(data, "malloc");
	rm_quotes(data);
	ft_exec_command(data);
	restore_fd(data, &red);
}
