/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/14 18:15:13 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_update_env(t_shell *data, const char *old_pwd)
{
	char	*temp;
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (perror(NULL));
	temp = ft_get_env_value("PWD", data->env);
	if (temp)
		ft_set_env_value("PWD=", pwd, data);
	free(pwd);
	temp = ft_get_env_value("OLDPWD", data->env);
	if (temp)
		ft_set_env_value("OLDPWD=", old_pwd, data);
}

void	ft_cd(t_shell *data, const char *path)
{
	int			i;
	char		*current_dir;
	static char	*old_dir;

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
		return (perror(NULL));
	if (!old_dir)
	{
		old_dir = current_dir;
		ft_set_env_value("OLDPWD=", old_dir, data);
	}
	while (*path && ft_isnotprint(*path))
		path++;
	if (*path == '-')
		i = chdir(old_dir);
	else if (*path == '~' || *path == 0)
		i = chdir(getenv("HOME"));
	else
		i = chdir(path);
	if (i == -1)
	{
		if (old_dir != current_dir)
			free(current_dir);
		return (perror(NULL));
	}
	if (old_dir && old_dir != current_dir)
		free(old_dir);
	old_dir = current_dir;
	ft_update_env(data, old_dir);
}
