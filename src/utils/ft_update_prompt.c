/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:53:14 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/15 16:05:57 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_update_prompt(t_shell *data)
{
	char	*text;
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
	{
		perror(NULL);
		exit(errno);
	}
	text = ft_strjoin(PROMPT, current_dir);
	free(current_dir);
	if (!text)
	{
		perror(NULL);
		exit(errno);
	}
	data->prompt = ft_strjoin(text, DELIMITATOR);
	free(text);
	if (!data->prompt)
	{
		perror(NULL);
		exit(errno);
	}
}
