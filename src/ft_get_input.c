/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:48:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/15 15:56:58 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*	Function gets the input for user using the readline function.
	The function will asking for more inputs with a \n
	if the input its not okay */
static char	*get_input(void)
{
	char	*new_input;

	new_input = readline("> ");
	if (!new_input)
	{
		ft_putstr_fd("unexpected EOF while looking for \"\'\n", STDERR);
		return (NULL);
	}
	return (new_input);
}

static char	*get_new_input_fail(void)
{
	perror("malloc");
	return (NULL);
}

static char	*get_new_input(char *old_input)
{
	char	*aux;
	char	*input;
	char	*new_input;

	input = ft_charjoin(old_input, '\n');
	if (!input)
		return (get_new_input_fail());
	while (check_quotes(input))
	{
		new_input = get_input();
		if (!new_input)
			return (input);
		aux = input;
		input = ft_strjoin(input, new_input);
		free(aux);
		free(new_input);
		if (!input)
			return (get_new_input_fail());
		aux = input;
		input = ft_charjoin(input, '\n');
		free(aux);
		if (!input)
			return (get_new_input_fail());
	}
	return (EXIT_SUCCESS);
}

int	ft_get_input(t_shell *data)
{
	char *temp;

	temp = ft_update_prompt();
	if (!temp)
		data->input = readline("-> minishell $ ");
	else
	{
		data->input = readline(temp);
		free(temp);
	}
	if (!data->input)
		return (EXIT_PROGRAM);
	if (check_quotes(data->input))
	{
		temp = data->input;
		data->input = get_new_input(data->input);
		free(temp);
		if (!data->input)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
