/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:12:50 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/09 18:09:42 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*reload_last_command(t_shell *data)
{
	int		i;
	char	*temp;

	temp = data->com->command;
	i = 0;
	while (temp[i] && ft_strchr("<> ", temp[i])) 
		i++;
	while (temp[i])
	{
		if (!quotes(temp[i]) && ft_strchr(" <>", temp[i]))
			break ;
		i++;
	}
	while (temp[i] == ' ')
		i++;
	return (ft_substr(data->com->command, i, ft_strlen(&temp[i])));
}

static char	*reload_front_command(t_shell *data, int pos)
{
	int		i;
	int		len;
	char	*temp;
	char	*rel_com;

	temp = data->com->command;
	i = pos;
	len = pos;
	while (temp[i] && ft_strchr("<> ", temp[i]))
		i++;
	while (temp[i])
	{
		if (!quotes(temp[i]) && ft_strchr(" <>", temp[i]))
			break ;
		i++;
	}
	len += ft_strlen(&temp[i]);
	rel_com = ft_calloc(len + 1, sizeof(char));
	if (!rel_com)
		return (NULL);
	ft_strlcpy(rel_com, temp, pos);
	ft_strlcat(rel_com, &temp[i], len);
	return (rel_com);
}

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
			if (i == 0)
				temp = reload_last_command(data);
			else
				temp = reload_front_command(data, i);
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
	reload_command(data);
	*i = -1;
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
	reload_command(data);
	*i = -1;
}

/* Function check's the redirection type, creates
and archive and changes the stdin or stdout  */
int	ft_check_redirection(t_shell *data, t_redir *red)
{
	int	i;

	i = 0;
	red->success = 1;
	while (data->com->command[i])
	{
		red->com = data->com->command;
		if (!quotes(red->com[i]) && red->com[i] == '>')
			redir_type_output(data, red, &i);
		else if (!quotes(red->com[i]) && red->com[i] == '<')
			redir_type_input(data, red, &i);
		if (!red->success)
			return (1);
		i++;
		// reload_command(data);
	}
	return (0);
}
