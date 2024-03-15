/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:53:14 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/15 14:55:06 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_get_prompt(t_shell *data)
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
