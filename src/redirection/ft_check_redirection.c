/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:12:50 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/03 16:43:05 by albartol         ###   ########.fr       */
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

/* Function check's the redirection type, creates
and archive and changes the stdin or stdout  */
int	ft_check_redirection(t_shell *data, t_redir *r)
{
	int		i;

	i = 0;
	while (data->com->command[i])
	{
		r->type = 0;
		r->success = 1;
		r->com = data->com->command;
		if (!quotes(r->com[i]) && r->com[i] == '>' && r->com[i + 1] == '>')
			r->type = 1;
		else if (!quotes(r->com[i]) && r->com[i] == '>')
			r->type = 2;
		else if (!quotes(r->com[i]) && r->com[i] == '<' && r->com[i + 1] == '<')
			r->type = 4;
		else if (!quotes(r->com[i]) && r->com[i] == '<')
			r->type = 3;
		r->com = &data->com->command[i];
		if (r->type > 0 && r->type < 4)
			ft_create_archive(data, r);
		// else if (r->type == 4)
		// 	ft_get_limit(data, &r); // <--- Falta implemementar esto
		if (!r->success)
			return (1);
		i++;
	}
	reload_command(data);
	return (0);
}
