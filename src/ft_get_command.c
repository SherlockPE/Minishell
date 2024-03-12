/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:48:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/12 17:31:51 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*ft_get_prompt(t_shell *data)
{
	char	*prompt;
	char	*text;
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
		perror(NULL);
	text = ft_strjoin(PROMPT, current_dir);
	free(current_dir);
	if (!text)
	{
		perror(NULL);
		exit(errno);
	}
	prompt = ft_strjoin(text, DELIMITATOR);
	free(text);
	if (!prompt)
	{
		perror(NULL);
		exit(errno);
	}
	return (prompt);
}

char	*ft_get_input(t_shell *data)
{
	char	*input;
	char	*prompt;

	prompt = ft_get_prompt(data);
	input = readline(prompt);
	free(prompt);
	if (!input)
		return (NULL);
	return (input);
}
