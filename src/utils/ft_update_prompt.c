/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:53:14 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/12 01:10:01 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_update_prompt(t_shell *data)
{
	char	*text;
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
		return (ft_exit_funct("malloc", EXIT_FAILURE));
	text = ft_strjoin(PROMPT, current_dir);
	free(current_dir);
	if (!text)
		return (ft_exit_funct("malloc", EXIT_FAILURE));
	data->prompt = ft_strjoin(text, DELIMITATOR);
	free(text);
	if (!data->prompt)
		return (ft_exit_funct("malloc", EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
