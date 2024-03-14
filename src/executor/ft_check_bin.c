/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:54:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/14 14:10:35 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*ft_get_env_value(char *name, t_list *env)
{
	size_t	len_name;
	size_t	len_env;
	char	*env_name;

	len_name = ft_strlen(name);
	while (env)
	{
		env_name = ((t_env *)env->content)->name;
		len_env = ft_strlen(env_name) - 1;
		if (len_name == len_env && !ft_strncmp(name, env_name, len_name))
			return (((t_env *)env->content)->value);
		env = env->next;
	}
	return (NULL);
}

static char	*ft_get_path(char *path, const char *command)
{
	size_t	i;
	size_t	j;
	size_t	len_com;
	size_t	len;
	char	*str;

	i = 0;
	len_com = ft_strlen(command);
	while (path[i] && path[i] != ':')
		i++;
	len = len_com + i + 1;
	str = ft_calloc(len + 1, 1);
	if (!str)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	j = 0;
	while (j < i)
	{
		str[j] = path[j];
		j++;
	}
	str[j] = '/';
	i = 0;
	while (++j < len)
	{
		str[j] = command[i];
		i++;
	}
	return (str);
}

static int	ft_len_path(char *path)
{
	int	len_path;

	len_path = 0;
	while (*path)
	{
		if (*path == ':')
			len_path++;
		path++;
	}
	return (len_path);
}

static char	*ft_check_path(char *path, const char *command)
{
	int		i;
	int		len_path;
	char	*str;

	i = 0;
	len_path = ft_len_path(path);
	str = 0;
	while (i < len_path && *path)
	{
		str = ft_get_path(path, command);
		if (access(str, X_OK) == 0)
			break ;
		free(str);
		str = 0;
		i++;
		while (*path && *path != ':')
			path++;
		if (*path == ':')
			path++;
	}
	return (str);
}

char	*ft_check_bin(t_shell *data, const char *command)
{
	char	*path;

	path = ft_get_env_value("PATH", data->env);
	return (ft_check_path(path, command));
}
