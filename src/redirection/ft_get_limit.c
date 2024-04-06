/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_limit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:20:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/02 18:24:23 by flopez-r         ###   ########.fr       */
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
		return (NULL);
	}
	return (new_input);
}

void	ft_get_limit(t_shell *data, t_redir *red)
{
	char	*aux;
	char	*new_input;

	while (check_quotes(data->input))
	{
		aux = data->input;
		data->input = ft_charjoin(data->input, '\n');
		free(aux);
		if (!data->input)
			ft_exit_program(data, "malloc");
		new_input = get_input(data, red);
		if (!new_input)
			return ;
		aux = data->input;
		data->input = ft_strjoin(data->input, new_input);
		free(aux);
		free(new_input);
		if (!data->input)
			ft_exit_program(data, "malloc");
	}
}
