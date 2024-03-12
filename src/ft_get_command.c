/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:48:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/12 14:27:49 by albartol         ###   ########.fr       */
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

char	*ft_get_command(t_shell *data)
{
	char	*command;
	char	*input;
	char	*prompt;

	prompt = ft_get_prompt(data);
	input = readline(prompt);
	free(prompt);
	if (!input)
		return (NULL);
	command = ft_strtrim(input, NON_PRINT);
	free(input);
	if (!command)
	{
		perror(NULL);
		exit(errno);
	}
	if (*command)
		add_history(command);
	return (command);
}
