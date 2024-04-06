/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_limit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:20:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/06 22:01:24 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
	
static char	*get_input(t_shell *data, t_redir *red)
{
	char	*new_input;

	// ft_putstr_fd("> ", 0);
	// new_input = get_next_line(0);
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

//Funcition get the limit word when an << appears
static void get_limit(t_shell *data, char *limit)
{
	int		i;
	char	*aux;

	i = 0;
	// printf("Data input 1 ==> [%s]\n", data->input);
	while (data->input[i])
	{
		if (data->input[i] == '<' && data->input[i + 1] == '<')
		{
 			limit = ft_substr(data->input, i + 2, ft_strlen(data->input));
			if (!limit)
				ft_exit_program(data, "malloc");
			aux = limit;
			limit = ft_strtrim(limit, " ");
			free(aux);
			if (!limit)
				ft_exit_program(data, "malloc");
			// printf("limit = [%s]\n", limit);
			return ;
		}
		i++;
	}
}

void	ft_get_limit(t_shell *data, t_redir *red)
{
	char	*limit;
	char	*aux;
	char	*new_input;

	limit = NULL;
	get_limit(data, limit);
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
	}
}

	// while (check_quotes(data->input))
	// {
	// 	aux = data->input;
	// 	data->input = ft_charjoin(data->input, '\n');
	// 	free(aux);
	// 	if (!data->input)
	// 		ft_exit_program(data, "malloc");
	// 	new_input = get_input(data, red);
	// 	if (!new_input)
	// 		return ;
	// 	printf("valor de new input: [%s]\n", new_input);
	// 	if (!ft_strncmp(new_input, limit, ft_strlen(limit)))
	// 	{
	// 		printf("coincidencia!\n");
	// 		return (free(limit));
	// 	}
	// 	aux = data->input;
	// 	data->input = ft_strjoin(data->input, new_input);
	// 	free(aux);
	// 	free(new_input);
	// 	if (!data->input)
	// 		ft_exit_program(data, "malloc");
	// }