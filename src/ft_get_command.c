/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:48:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/15 15:08:50 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//  34  "
//	39  '
int	check_input(char *input)
{
	int	i;
	int	double_q;
	int	simple_q;

	i = 0;
	double_q = 0;
	simple_q = 0;
	while (input[i])
	{
		if (input[i] == '\"')
			double_q++;
		if (input[i] == '\'')
			simple_q++;
		i++;
	}
	if ((double_q % 2 == 0) && (simple_q % 2 == 0))
		return (1);
	return (0);
}

char	*get_command(char *prompt)
{
	char	*aux;
	char	*input;
	char	*new_input;

	input = readline(prompt);
	if (!input)
		return (NULL);
	while (!check_input(input))
	{
		new_input = readline(">");
		if (!new_input)
			return (NULL);
		aux = input;
		input = ft_strjoin(input, "\n");
		free(aux);
		if (!input)
			return (NULL);
		aux = input;
		input = ft_strjoin(input, new_input);
		free(aux);
		if (!input)
			return (NULL);
	}
	// aux = input;
	// input = ft_strtrim(input, "\"");
	// free(aux);
	return (input);
}

char	*ft_get_input(t_shell *data)
{
	char	*input;
	char	*prompt;

	//NOTE: Make a function that reloads the prompt with a void return prototype
	prompt = ft_get_prompt(data);
	input = get_command(prompt);
	free(prompt);
	if (!input)
		return (NULL);
	return (input);
}
