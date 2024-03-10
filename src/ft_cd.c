/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/09 12:14:02 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_cd(const char *path)
{
	int			i;
	char		*current_dir;
	static char	*old_dir;

	if (!path || !ft_isnotprint(*path))
		return ;
	current_dir = getcwd(NULL, 0);
	if (!current_dir)
		return (ft_print_error());
	if (!old_dir)
		old_dir = current_dir;
	while (*path && ft_isnotprint(*path))
		path++;
	if (*path == '-')
		i = chdir(old_dir);
	else if (*path == '~')
		i = chdir(getenv("HOME"));
	else
		i = chdir(path);
	if (i == -1)
	{
		free(current_dir);
		return (ft_print_error());
	}
	if (old_dir && old_dir != current_dir)
		free(old_dir);
	old_dir = current_dir;
}
