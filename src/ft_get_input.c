/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:48:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/12 01:25:02 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*	Function gets the input for user using the readline function.
	The function will asking for more inputs with a \n
	if the input its not okay */
static char	*get_input(t_shell *data)
{
	char	*new_input;

	new_input = readline("> ");
	if (!new_input)
	{
		ft_putstr_fd("unexpected EOF while looking for \"\'\n", STDERR);
		free_input(data);
		data->input = (char *)ft_calloc(1, sizeof(char));
		if (!data->input)
			return ((char *)ft_exit_funct("malloc", 0));
		return (NULL);
	}
	return (new_input);
}

static int	get_new_input(t_shell *data)
{
	char	*aux;
	char	*new_input;

	while (check_quotes(data->input))
	{
		aux = data->input;
		data->input = ft_charjoin(data->input, '\n');
		free(aux);
		if (!data->input)
			ft_exit_funct("malloc", EXIT_FAILURE);
		new_input = get_input(data);
		if (!new_input)
			return ;
		aux = data->input;
		data->input = ft_strjoin(data->input, new_input);
		free(aux);
		free(new_input);
		if (!data->input)
			ft_exit_program(data, "malloc");
	}
	return (EXIT_SUCCESS);
}

int	ft_get_input(t_shell *data)
{
	if (ft_update_prompt(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->input = readline(data->prompt);
	free(data->prompt);
	if (!data->input)
		return (ft_exit_funct("readline", EXIT_FAILURE));
	if (check_quotes(data->input))
	{
		if (get_new_input(data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
