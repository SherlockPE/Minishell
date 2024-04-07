/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_limit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:20:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/07 13:10:02 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
	
static char	*get_input(t_shell *data, t_redir *red)
{
	char	*new_input;

	new_input = readline("> ");
	if (!new_input)
	{
		free_input(data);
		data->input = (char *)ft_calloc(1, sizeof(char));
		if (!data->input)
			ft_exit_program(data, "malloc");
		ft_putstr_fd("unexpected EOF while looking for \"\'\n", STDERR);
		red->success = 0;
		free(red->file_name);
		return (NULL);
	}
	return (new_input);
}


void	ft_get_limit(t_shell *data, t_redir *red)
{
	char	*aux;
	char	*new_input;

	new_input = "";
	red->file_name = NULL;
	ft_get_archive_name(data, red);
	while (ft_strncmp(new_input, red->file_name, ft_strlen(red->file_name)))
	{
		aux = data->input;
		data->input = ft_strjoin(data->input, new_input);
		free(aux);
		aux = data->input;
		data->input = ft_charjoin(data->input, '\n');
		free(aux);
		if (!data->input)
			ft_exit_program(data, "malloc");
		new_input = get_input(data, red);
		if (!new_input)
			return ;
	}
	red->success = 0;
	// printf("%s", data->input);
	free(red->file_name);
}
