/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_com.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:00:01 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/02 20:24:28 by flopez-r         ###   ########.fr       */
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

static void	rm_quotes(t_shell *data, t_redir *red)
{
	red->old_stdin = dup(STDIN_FILENO);
	if (red->old_stdin == -1)
	{
		free_input(data);
		return (perror("dup"));
	}
	red->old_stdout = dup(STDOUT_FILENO);
	if (red->old_stdout == -1)
	{
		free_input(data);
		return (perror("dup"));
	}
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
	red.old_stdin = dup2(red.old_stdin, STDIN_FILENO);
	red.old_stdout = dup2(red.old_stdout, STDOUT_FILENO);
	if (!red.old_stdin)
		perror("dup2 : red.old_stdin");
	if (!red.old_stdout)
		perror("dup2 : red.old_stdout");
}
