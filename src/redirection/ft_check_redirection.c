/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:12:50 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/18 16:55:07 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	redir_output(t_shell *data, t_pipe *pipe, const char *com, int *i)
{
	t_redir	*red;

	red = &pipe->output;
	if (com[*i + 1] == '>')
	{
		red->type = APPEND;
		com = &com[*i + 2];
	}
	else
	{
		red->type = TRUNC;
		com = &com[*i + 1];
	}
	while (*com == ' ')
		com++;
	free(red->file_name);
	if (ft_create_archive(red, com, data))
		return (EXIT_FAILURE);
	if (reload_command(pipe))
		return (EXIT_FAILURE);
	*i = -1;
	return (EXIT_SUCCESS);
}

static void	check_old_redir(t_redir *red)
{
	if (red->type == HERE_DOC)
		unlink(red->file_name);
	free(red->file_name);
}

static int	redir_input(t_shell *data, t_pipe *pipe, const char *com, int *i)
{
	t_redir	*red;

	red = &pipe->input;
	check_old_redir(red);
	if (com[*i + 1] == '<')
	{
		red->type = HERE_DOC;
		com = &com[*i + 2];
		while (*com == ' ')
			com++;
		if (ft_here_doc(red, com))
			return (EXIT_FAILURE);
	}
	else
	{
		red->type = INPUT;
		com = &com[*i + 1];
		while (*com == ' ')
			com++;
		if (ft_create_archive(red, com, data))
			return (EXIT_FAILURE);
	}
	if (reload_command(pipe))
		return (EXIT_FAILURE);
	*i = -1;
	return (EXIT_SUCCESS);
}

static int	find_redir(t_shell *data, int i)
{
	t_pipe	*pipe;
	int		j;
	int		sucess;

	pipe = &data->com[i];
	j = 0;
	sucess = 0;
	while (pipe->com[j])
	{
		if (!quotes(pipe->com[j]))
		{
			if (pipe->com[j] == '>')
				sucess = redir_output(data, pipe, pipe->com, &j);
			else if (pipe->com[j] == '<')
				sucess = redir_input(data, pipe, pipe->com, &j);
			if (sucess)
				return (EXIT_FAILURE);
		}
		j++;
	}
	return (EXIT_SUCCESS);
}

/* Function check's the redirection type, creates
and archive and changes the stdin or stdout  */
int	ft_check_redirection(t_shell *data)
{
	int		i;

	i = 0;
	while (i < data->com_len)
	{
		if (find_redir(data, i))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
