/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/18 17:33:34 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	update_env(t_shell *data, const char *old_pwd)
{
	char	*temp;
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (perror(NULL));
	temp = ft_get_env_value("PWD", data->env);
	if (temp)
		ft_update_env_value("PWD=", pwd, data);
	free(pwd);
	temp = ft_get_env_value("OLDPWD", data->env);
	if (temp)
		ft_update_env_value("OLDPWD=", old_pwd, data);
}

static int	change_dir(const char *new_dir, const char *old_dir)
{
	int	i;

	if (!new_dir || *(new_dir) == '~')
		i = chdir(getenv("HOME"));
	else if (*(new_dir) == '-')
		i = chdir(old_dir);
	else
		i = chdir(new_dir);
	return (i);
}

void	ft_cd(t_shell *data)
{
	char		*current_dir;
	static char	*old_dir;

	if (data->com->argv[1] && data->com->argv[2])
		return ((void)ft_putstr_fd("cd: too many arguments\n", 2));
	current_dir = getcwd(NULL, 0);
	if (!current_dir)
		return (perror("cd"));
	if (!old_dir)
	{
		old_dir = current_dir;
		ft_update_env_value("OLDPWD=", old_dir, data);
	}
	if (change_dir(data->com->argv[1], old_dir) == -1)
	{
		if (old_dir != current_dir)
			free(current_dir);
		return (perror("cd"));
	}
	if (old_dir && old_dir != current_dir)
		free(old_dir);
	old_dir = current_dir;
	update_env(data, old_dir);
}
