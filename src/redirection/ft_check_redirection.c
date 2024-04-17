/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:12:50 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/17 17:02:40 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	redir_output(t_shell *data, t_pipe *pipe, char  *com, int *i)
{
	t_redir *red;
	
	red = &pipe->output;
	if (com[*i + 1] == '>')
	{
		com = com + 3;
		red->type = APPEND;
	}
	else
	{
		com = com + 2;
		red->type = TRUNC;
	}
	while (com == ' ')
		com++;
	if (ft_create_archive(red, com, data))
		return (EXIT_FAILURE);
	if (reload_command(pipe))
		return (EXIT_FAILURE);
	*i = -1;
	return (EXIT_SUCCESS);
}

static int	redir_input(t_shell *data, t_pipe *pipe, char  *com, int *i)
{
	t_redir *red;
	
	red = &pipe->input;
	if (com[*i + 1] == '<')
	{
		com = com + 3;
		while (*com == ' ')
			com++;
		if (ft_get_limit(red, com))
			return (EXIT_FAILURE);
	}
	else
	{
		red->type = INPUT;
		com = com + 2;
		while (*com == ' ')
			com++;
		if (ft_create_archive(red, com, data))
			return (EXIT_FAILURE);
	}
	if (reload_command(pipe))
		return (EXIT_FAILURE);
	*i = -1;
}

static int	find_redir(t_shell *data, int i)
{
	t_pipe	*pipe;
	int		j;
	int		sucess;
	
	pipe = &data->com[i];
	j = 0;
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
	}
	return (EXIT_SUCCESS);
}
