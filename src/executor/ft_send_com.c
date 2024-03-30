/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_com.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:00:01 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/29 16:23:35 by flopez-r         ###   ########.fr       */
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

void	ft_send_com(t_shell *data, char *com, t_com *com_struct)
{
	com = ft_strtrim(com, " ");
	if (!com)
		ft_exit_program(data, "malloc");
	com_struct->argv = ft_split_quotes(com, ' ');
	free(com);
	if (!com_struct->argv)
		ft_exit_program(data, "malloc");
	data->com = com_struct;

	//Check redirections
	// ft_check_redirection(data);

	rm_quotes(data);

	ft_exec_command(data);
}
