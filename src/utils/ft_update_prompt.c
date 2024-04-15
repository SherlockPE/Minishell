/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:53:14 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/15 14:52:59 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_update_prompt(void)
{
	char	*temp;
	char	*current_dir;
	char	*prompt;

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
	{
		perror("getcwd");
		return (NULL);
	}
	temp = ft_strjoin(PROMPT, current_dir);
	free(current_dir);
	if (!temp)
	{
		perror("malloc");
		return (NULL);
	}
	prompt = ft_strjoin(temp, DELIMITATOR);
	free(temp);
	if (!prompt)
	{
		perror("malloc");
		return (NULL);
	}
	return (prompt);
}
