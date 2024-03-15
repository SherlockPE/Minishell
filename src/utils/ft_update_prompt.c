/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:53:14 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/15 18:03:40 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_update_prompt(t_shell *data)
{
	char	*text;
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
		ft_exit_program(data, NULL);
	text = ft_strjoin(PROMPT, current_dir);
	free(current_dir);
	if (!text)
		ft_exit_program(data, NULL);
	data->prompt = ft_strjoin(text, DELIMITATOR);
	free(text);
	if (!data->prompt)
		ft_exit_program(data, NULL);
}
