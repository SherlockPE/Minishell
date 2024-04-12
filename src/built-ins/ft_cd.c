/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/12 15:15:37 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	update_env(t_shell *data, const char *old_pwd)
{
	char	*temp;
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (perror("cd: getcwd"));
	temp = ft_get_env_value("PWD", data->env);
	if (temp)
		ft_update_env_value("PWD=", pwd, data);
	free(pwd);
	temp = ft_get_env_value("OLDPWD", data->env);
	if (temp)
		ft_update_env_value("OLDPWD=", old_pwd, data);
}

static int	change_dir(const char *new_dir, const char *old_dir, t_list *env)
{
	int		i;
	char	*temp;

	if (!new_dir)
	{
		temp = ft_get_env_value("HOME", env);
		if (!temp)
		{
			ft_putstr_fd("cd: HOME not set\n", STDERR);
			return (-1);
		}
		i = chdir(temp);
	}
	else if (*(new_dir) == '-')
		i = chdir(old_dir);
	else
		i = chdir(new_dir);
	if (i == -1)
		perror("cd: chdir");
	return (i);
}

void	ft_cd(t_shell *data)
{
	char		*current_dir;
	static char	*old_dir;

	if (data->com->argv[1] && data->com->argv[2])
		return ((void)ft_putstr_fd("cd: too many arguments\n", STDERR));
	current_dir = getcwd(NULL, 0);
	if (!current_dir)
		return (perror("cd: getcwd"));
	if (!old_dir)
	{
		old_dir = current_dir;
		ft_update_env_value("OLDPWD=", old_dir, data);
	}
	if (change_dir(data->com->argv[1], old_dir, data->env) == -1)
	{
		if (old_dir != current_dir)
			free(current_dir);
		return ;
	}
	if (old_dir && old_dir != current_dir)
		free(old_dir);
	old_dir = current_dir;
	update_env(data, old_dir);
}
