/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_archive_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 22:05:36 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/04/06 22:39:57 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	trim_archive_name(t_shell *data, t_redir *red, int i)
{
	char	*temp;

	temp = ft_substr(red->com, 0, i);
	if (!temp)
	{
		free(data->com->command);
		ft_exit_program(data, "malloc");
	}
	red->file_name = ft_trim_quotes(temp);
	free(temp);
	if (!red->file_name)
	{
		free(data->com->command);
		ft_exit_program(data, "malloc");
	}
}

void	ft_get_archive_name(t_shell *data, t_redir *red)
{
	int		i;

	i = 0;
	while (red->com[i])
	{
		if (!quotes(red->com[i]) && ft_strchr(" <>", red->com[i]))
		{
			trim_archive_name(data, red, i);
			return ;
		}
		i++;
	}
	trim_archive_name(data, red, i);
}
