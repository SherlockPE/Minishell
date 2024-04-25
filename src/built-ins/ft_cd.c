/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/25 17:49:14 by albartol         ###   ########.fr       */
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
	else if (!ft_strncmp(new_dir, "-", 2))
		i = chdir(old_dir);
	else
		i = chdir(new_dir);
	if (i == -1)
		perror("cd: chdir");
	return (i);
}

// static void	too_many_argv(t_shell *data)
// {
// 	ft_putstr_fd("cd: too many arguments\n", STDERR);
// 	data->exit_code = EXIT_FAILURE;
// }
	// if (argv[1] && argv[2])
	// 	return (too_many_argv(data));

void	ft_cd(char **argv, t_shell *data)
{
	char		*current_dir;
	static char	*old_dir;

	current_dir = get_current_dir();
	if (!old_dir)
	{
		old_dir = current_dir;
		ft_update_env_value("OLDPWD=", old_dir, data);
	}
	if (change_dir(argv[1], old_dir, data->env) == -1)
	{
		if (old_dir != current_dir)
			free(current_dir);
		return (ft_set_exit(data, EXIT_FAILURE));
	}
	if (old_dir && old_dir != current_dir)
		free(old_dir);
	old_dir = current_dir;
	update_env(data, old_dir);
	data->exit_code = EXIT_SUCCESS;
}
