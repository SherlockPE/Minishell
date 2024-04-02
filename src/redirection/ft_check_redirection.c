/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:12:50 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/02 20:17:16 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
		else if (!quotes(r->com[i]) && r->com[i] == '>')
			r->type = 3;
		r->com = &data->com->command[i];
		if (r->type > 0 && r->type < 4)
			ft_create_archive(data, &r);
		// else if (r->type == 4)
		// 	ft_get_limit(data, &r); // <--- Falta implemementar esto
		if (!r->success)
			return (1);
		i++;
	}
	return (0);
}
