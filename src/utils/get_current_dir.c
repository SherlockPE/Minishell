/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:46:40 by albartol          #+#    #+#             */
/*   Updated: 2024/04/25 17:48:33 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_current_dir(void)
{
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
	{
		perror("getcwd: moving to root");
		if (chdir("/") == -1)
		{
			perror("chdir to root failed");
			return (NULL);
		}
		return (get_current_dir());
	}
	return (current_dir);
}
