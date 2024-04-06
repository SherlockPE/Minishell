/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:12:50 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/06 20:42:44 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	reload_command(t_shell *data)
{
	int		i;
	char	*temp;

	temp = data->com->command;
	i = 0;
	while (temp[i])
	{
		if (!quotes(temp[i]) && ft_strchr("<>", temp[i]))
		{
			if (i > 0 && temp[i - 1] == ' ')
				i--;
			temp = ft_substr(data->com->command, 0, i);
			free(data->com->command);
			if (!temp)
				ft_exit_program(data, "malloc");
			data->com->command = temp;
			return ;
		}
		i++;
	}
}

static void	redir_type_output(t_shell *data, t_redir *red, int *i)
{
	if (red->com[*i + 1] == '>')
	{
		(*i)++;
		red->type = 1;
	}
	else
		red->type = 2;
	red->com = &data->com->command[*i + 1];
	while (*red->com == ' ')
		red->com++;
	ft_create_archive(data, red);
}

static void	redir_type_input(t_shell *data, t_redir *red, int *i)
{
	if (red->com[*i + 1] == '<')
	{
		(*i)++;
		red->com = &data->com->command[*i + 1];
		while (*red->com == ' ')
			red->com++;
		ft_get_limit(data, red);
	}
	else
	{
		red->type = 3;
		red->com = &data->com->command[*i + 1];
		while (*red->com == ' ')
			red->com++;
		ft_create_archive(data, red);
	}
}

/* Function check's the redirection type, creates
and archive and changes the stdin or stdout  */
int	ft_check_redirection(t_shell *data, t_redir *red)
{
	int	i;

	i = 0;
	while (data->com->command[i])
	{
		red->success = 1;
		red->com = data->com->command;
		if (!quotes(red->com[i]) && red->com[i] == '>')
			redir_type_output(data, red, &i);
		else if (!quotes(red->com[i]) && red->com[i] == '<')
			redir_type_input(data, red, &i);
		if (!red->success)
			return (1);
		i++;
	}
	reload_command(data);
	return (0);
}
