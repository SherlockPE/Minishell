/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_com.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:00:01 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/03 11:58:17 by flopez-r         ###   ########.fr       */
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
void	save_fd(t_shell *data, t_redir *red)
{
	if (pipe(red->old_fds) == -1)
		ft_exit_program(data, "pipe");
	red->old_fds[STDIN_FILENO] = dup(STDIN_FILENO);
	if (red->old_fds[STDIN_FILENO] == -1)
		ft_exit_program(data, "dup");
	red->old_fds[STDOUT_FILENO] = dup(STDOUT_FILENO);
	if (red->old_fds[STDOUT_FILENO] == -1)
		ft_exit_program(data, "dup");
}

void	restore_fd(t_shell *data, t_redir *red)
{
	if (dup2(red->old_fds[STDOUT_FILENO] , STDOUT_FILENO) == -1)
		return (ft_exit_program(data, "dup2 : red.old_stdout"));
	if (dup2(red->old_fds[STDIN_FILENO] , STDIN_FILENO) == -1)
		return (ft_exit_program(data, "dup2 : red.old_stdin"));
	close(red->old_fds[STDOUT_FILENO]);
	close(red->old_fds[STDIN_FILENO]);
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
		return ;
	}
	data->com->argv = ft_split_quotes(data->com->command, ' ');
	free(data->com->command);
	if (!data->com->argv)
		ft_exit_program(data, "malloc");
	rm_quotes(data);
	ft_exec_command(data);
	restore_fd(data, &red);
}
